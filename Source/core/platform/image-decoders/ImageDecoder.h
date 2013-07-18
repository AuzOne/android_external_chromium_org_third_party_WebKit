/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
 * Copyright (C) Research In Motion Limited 2009-2010. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ImageDecoder_h
#define ImageDecoder_h

#include "SkColorPriv.h"
#include "core/platform/PlatformScreen.h"
#include "core/platform/SharedBuffer.h"
#include "core/platform/graphics/ImageSource.h"
#include "core/platform/graphics/IntRect.h"
#include "core/platform/graphics/skia/NativeImageSkia.h"
#include <wtf/Assertions.h>
#include <wtf/RefPtr.h>
#include <wtf/text/WTFString.h>
#include <wtf/Vector.h>

#if USE(QCMSLIB)
#include "qcms.h"
#if OS(DARWIN)
#include <ApplicationServices/ApplicationServices.h>
#include "core/platform/graphics/cg/GraphicsContextCG.h"
#include <wtf/RetainPtr.h>
#endif
#endif

namespace WebCore {

    // ImageFrame represents the decoded image data.  This buffer is what all
    // decoders write a single frame into.
    class ImageFrame {
    public:
        enum FrameStatus { FrameEmpty, FramePartial, FrameComplete };
        enum FrameDisposalMethod {
            // If you change the numeric values of these, make sure you audit
            // all users, as some users may cast raw values to/from these
            // constants.
            DisposeNotSpecified,      // Leave frame in framebuffer
            DisposeKeep,              // Leave frame in framebuffer
            DisposeOverwriteBgcolor,  // Clear frame to transparent
            DisposeOverwritePrevious  // Clear frame to previous framebuffer
                                      // contents
        };
        typedef uint32_t PixelData;

        ImageFrame();

        ImageFrame(const ImageFrame& other) { operator=(other); }

        // For backends which refcount their data, this operator doesn't need to
        // create a new copy of the image data, only increase the ref count.
        ImageFrame& operator=(const ImageFrame& other);

        // These do not touch other metadata, only the raw pixel data.
        void clearPixelData();
        void zeroFillPixelData();
        void zeroFillFrameRect(const IntRect&);

        // Makes this frame have an independent copy of the provided image's
        // pixel data, so that modifications in one frame are not reflected in
        // the other.  Returns whether the copy succeeded.
        bool copyBitmapData(const ImageFrame&);

        // Copies the pixel data at [(startX, startY), (endX, startY)) to the
        // same X-coordinates on each subsequent row up to but not including
        // endY.
        void copyRowNTimes(int startX, int endX, int startY, int endY)
        {
            ASSERT(startX < width());
            ASSERT(endX <= width());
            ASSERT(startY < height());
            ASSERT(endY <= height());
            const int rowBytes = (endX - startX) * sizeof(PixelData);
            const PixelData* const startAddr = getAddr(startX, startY);
            for (int destY = startY + 1; destY < endY; ++destY)
                memcpy(getAddr(startX, destY), startAddr, rowBytes);
        }

        // Allocates space for the pixel data.  Must be called before any pixels
        // are written.  Must only be called once.  Returns whether allocation
        // succeeded.
        bool setSize(int newWidth, int newHeight);

        // Returns a caller-owned pointer to the underlying native image data.
        // (Actual use: This pointer will be owned by BitmapImage and freed in
        // FrameData::clear()).
        PassRefPtr<NativeImageSkia> asNewNativeImage() const;

        bool hasAlpha() const;
        const IntRect& originalFrameRect() const { return m_originalFrameRect; }
        FrameStatus status() const { return m_status; }
        unsigned duration() const { return m_duration; }
        FrameDisposalMethod disposalMethod() const { return m_disposalMethod; }
        bool premultiplyAlpha() const { return m_premultiplyAlpha; }
        SkBitmap::Allocator* allocator() const { return m_allocator; }
        const SkBitmap& getSkBitmap() const { return m_bitmap->bitmap(); }

        size_t requiredPreviousFrameIndex() const
        {
            ASSERT(m_requiredPreviousFrameIndexValid);
            return m_requiredPreviousFrameIndex;
        }
#if !ASSERT_DISABLED
        bool requiredPreviousFrameIndexValid() const { return m_requiredPreviousFrameIndexValid; }
#endif
        void setHasAlpha(bool alpha);
        void setOriginalFrameRect(const IntRect& r) { m_originalFrameRect = r; }
        void setStatus(FrameStatus status);
        void setDuration(unsigned duration) { m_duration = duration; }
        void setDisposalMethod(FrameDisposalMethod method) { m_disposalMethod = method; }
        void setPremultiplyAlpha(bool premultiplyAlpha) { m_premultiplyAlpha = premultiplyAlpha; }
        void setMemoryAllocator(SkBitmap::Allocator* allocator) { m_allocator = allocator; }
        void setSkBitmap(const SkBitmap& bitmap) { m_bitmap = NativeImageSkia::create(bitmap); }

        void setRequiredPreviousFrameIndex(size_t previousFrameIndex)
        {
            m_requiredPreviousFrameIndex = previousFrameIndex;
#if !ASSERT_DISABLED
            m_requiredPreviousFrameIndexValid = true;
#endif
        }

        inline PixelData* getAddr(int x, int y)
        {
            return m_bitmap->bitmap().getAddr32(x, y);
        }

        inline void setRGBA(int x, int y, unsigned r, unsigned g, unsigned b, unsigned a)
        {
            setRGBA(getAddr(x, y), r, g, b, a);
        }

        static const unsigned div255 = static_cast<unsigned>(1.0 / 255 * (1 << 24)) + 1;

        inline void setRGBA(PixelData* dest, unsigned r, unsigned g, unsigned b, unsigned a)
        {
            if (m_premultiplyAlpha && a < 255) {
                if (!a) {
                    *dest = 0;
                    return;
                }

                unsigned alpha = a * div255;
                r = (r * alpha) >> 24;
                g = (g * alpha) >> 24;
                b = (b * alpha) >> 24;
            }

            // Call the "NoCheck" version since we may deliberately pass non-premultiplied
            // values, and we don't want an assert.
            *dest = SkPackARGB32NoCheck(a, r, g, b);
        }

        inline void setRGBARaw(PixelData* dest, unsigned r, unsigned g, unsigned b, unsigned a)
        {
            *dest = SkPackARGB32NoCheck(a, r, g, b);
        }

    private:
        int width() const
        {
            return m_bitmap->bitmap().width();
        }

        int height() const
        {
            return m_bitmap->bitmap().height();
        }

        RefPtr<NativeImageSkia> m_bitmap;
        SkBitmap::Allocator* m_allocator;
        bool m_hasAlpha;
        // This will always just be the entire buffer except for GIF or WebP
        // frames whose original rect was smaller than the overall image size.
        IntRect m_originalFrameRect;
        FrameStatus m_status;
        unsigned m_duration;
        FrameDisposalMethod m_disposalMethod;
        bool m_premultiplyAlpha;

        // The frame that must be decoded before this frame can be decoded.
        // WTF::notFound if this frame doesn't require any previous frame.
        // This is used by ImageDecoder::clearCacheExceptFrame(), and will never
        // be read for image formats that do not have multiple frames.
        size_t m_requiredPreviousFrameIndex;
#if !ASSERT_DISABLED
        bool m_requiredPreviousFrameIndexValid;
#endif
    };

    // ImageDecoder is a base for all format-specific decoders
    // (e.g. JPEGImageDecoder). This base manages the ImageFrame cache.
    class ImageDecoder {
        WTF_MAKE_NONCOPYABLE(ImageDecoder); WTF_MAKE_FAST_ALLOCATED;
    public:
        ImageDecoder(ImageSource::AlphaOption alphaOption, ImageSource::GammaAndColorProfileOption gammaAndColorProfileOption)
            : m_premultiplyAlpha(alphaOption == ImageSource::AlphaPremultiplied)
            , m_ignoreGammaAndColorProfile(gammaAndColorProfileOption == ImageSource::GammaAndColorProfileIgnored)
            , m_sizeAvailable(false)
            , m_isAllDataReceived(false)
            , m_failed(false) { }

        virtual ~ImageDecoder() { }

        // Returns a caller-owned decoder of the appropriate type.  Returns 0 if
        // we can't sniff a supported type from the provided data (possibly
        // because there isn't enough data yet).
        static PassOwnPtr<ImageDecoder> create(const SharedBuffer& data, ImageSource::AlphaOption, ImageSource::GammaAndColorProfileOption);

        virtual String filenameExtension() const = 0;

        bool isAllDataReceived() const { return m_isAllDataReceived; }

        virtual void setData(SharedBuffer* data, bool allDataReceived)
        {
            if (m_failed)
                return;
            m_data = data;
            m_isAllDataReceived = allDataReceived;
        }

        // Lazily-decodes enough of the image to get the size (if possible).
        // FIXME: Right now that has to be done by each subclass; factor the
        // decode call out and use it here.
        virtual bool isSizeAvailable()
        {
            return !m_failed && m_sizeAvailable;
        }

        virtual IntSize size() const { return m_size; }

        // This will only differ from size() for ICO (where each frame is a
        // different icon) or other formats where different frames are different
        // sizes. This does NOT differ from size() for GIF or WebP, since
        // decoding GIF or WebP composites any smaller frames against previous
        // frames to create full-size frames.
        virtual IntSize frameSizeAtIndex(size_t) const
        {
            return size();
        }

        // Returns whether the size is legal (i.e. not going to result in
        // overflow elsewhere).  If not, marks decoding as failed.
        virtual bool setSize(unsigned width, unsigned height)
        {
            if (isOverSize(width, height))
                return setFailed();
            m_size = IntSize(width, height);
            m_sizeAvailable = true;
            return true;
        }

        // Lazily-decodes enough of the image to get the frame count (if
        // possible), without decoding the individual frames.
        // FIXME: Right now that has to be done by each subclass; factor the
        // decode call out and use it here.
        virtual size_t frameCount() { return 1; }

        virtual int repetitionCount() const { return cAnimationNone; }

        // Decodes as much of the requested frame as possible, and returns an
        // ImageDecoder-owned pointer.
        virtual ImageFrame* frameBufferAtIndex(size_t) = 0;

        // Make the best effort guess to check if the requested frame has alpha channel.
        virtual bool frameHasAlphaAtIndex(size_t) const;

        // Whether or not the frame is fully received.
        virtual bool frameIsCompleteAtIndex(size_t) const;

        // Duration for displaying a frame in seconds. This method is used by animated images only.
        virtual float frameDurationAtIndex(size_t) const { return 0; }

        // Number of bytes in the decoded frame requested. Return 0 if not yet decoded.
        virtual unsigned frameBytesAtIndex(size_t) const;

        void setIgnoreGammaAndColorProfile(bool flag) { m_ignoreGammaAndColorProfile = flag; }
        bool ignoresGammaAndColorProfile() const { return m_ignoreGammaAndColorProfile; }

        ImageOrientation orientation() const { return m_orientation; }

        enum { iccColorProfileHeaderLength = 128 };

        static bool rgbColorProfile(const char* profileData, unsigned profileLength)
        {
            ASSERT_UNUSED(profileLength, profileLength >= iccColorProfileHeaderLength);

            return !memcmp(&profileData[16], "RGB ", 4);
        }

        static bool inputDeviceColorProfile(const char* profileData, unsigned profileLength)
        {
            ASSERT_UNUSED(profileLength, profileLength >= iccColorProfileHeaderLength);

            return !memcmp(&profileData[12], "mntr", 4) || !memcmp(&profileData[12], "scnr", 4);
        }

#if USE(QCMSLIB)
        static qcms_profile* qcmsOutputDeviceProfile()
        {
            static qcms_profile* outputDeviceProfile = 0;

            static bool qcmsInitialized = false;
            if (!qcmsInitialized) {
                qcmsInitialized = true;
                // FIXME: Add optional ICCv4 support.
#if OS(DARWIN)
                RetainPtr<CGColorSpaceRef> monitorColorSpace(AdoptCF, CGDisplayCopyColorSpace(CGMainDisplayID()));
                CFDataRef iccProfile(CGColorSpaceCopyICCProfile(monitorColorSpace.get()));
                if (iccProfile) {
                    size_t length = CFDataGetLength(iccProfile);
                    const unsigned char* systemProfile = CFDataGetBytePtr(iccProfile);
                    outputDeviceProfile = qcms_profile_from_memory(systemProfile, length);
                }
#else
                // FIXME: add support for multiple monitors.
                ColorProfile profile;
                screenColorProfile(profile);
                if (!profile.isEmpty())
                    outputDeviceProfile = qcms_profile_from_memory(profile.data(), profile.size());
#endif
                if (outputDeviceProfile && qcms_profile_is_bogus(outputDeviceProfile)) {
                    qcms_profile_release(outputDeviceProfile);
                    outputDeviceProfile = 0;
                }
                if (!outputDeviceProfile)
                    outputDeviceProfile = qcms_profile_sRGB();
                if (outputDeviceProfile)
                    qcms_profile_precache_output_transform(outputDeviceProfile);
            }
            return outputDeviceProfile;
        }
#endif

        // Sets the "decode failure" flag.  For caller convenience (since so
        // many callers want to return false after calling this), returns false
        // to enable easy tailcalling.  Subclasses may override this to also
        // clean up any local data.
        virtual bool setFailed()
        {
            m_failed = true;
            return false;
        }

        bool failed() const { return m_failed; }

        // Clears decoded pixel data from all frames except the provided frame.
        // Callers may pass WTF::notFound to clear all frames.
        // Note: If |m_frameBufferCache| contains only one frame, it won't be cleared.
        // Returns the number of bytes of frame data actually cleared.
        virtual size_t clearCacheExceptFrame(size_t);

        // If the image has a cursor hot-spot, stores it in the argument
        // and returns true. Otherwise returns false.
        virtual bool hotSpot(IntPoint&) const { return false; }

        virtual void setMemoryAllocator(SkBitmap::Allocator* allocator)
        {
            // FIXME: this doesn't work for images with multiple frames.
            if (m_frameBufferCache.isEmpty()) {
                m_frameBufferCache.resize(1);
                m_frameBufferCache[0].setRequiredPreviousFrameIndex(
                    findRequiredPreviousFrame(0));
            }
            m_frameBufferCache[0].setMemoryAllocator(allocator);
        }

    protected:
        // Calculates the most recent frame whose image data may be needed in
        // order to decode frame |frameIndex|, based on frame disposal methods.
        // If no previous frame's data is required, returns WTF::notFound.
        //
        // This function requires that the previous frame's
        // |m_requiredPreviousFrameIndex| member has been set correctly. The
        // easiest way to ensure this is for subclasses to call this method and
        // store the result on the frame via setRequiredPreviousFrameIndex()
        // as soon as the frame has been created and parsed sufficiently to
        // determine the disposal method; assuming this happens for all frames
        // in order, the required invariant will hold.
        //
        // Image formats which do not use more than one frame do not need to
        // worry about this; see comments on
        // ImageFrame::m_requiredPreviousFrameIndex.
        size_t findRequiredPreviousFrame(size_t frameIndex);

        virtual void clearFrameBuffer(size_t frameIndex);

        RefPtr<SharedBuffer> m_data; // The encoded data.
        Vector<ImageFrame, 1> m_frameBufferCache;
        bool m_premultiplyAlpha;
        bool m_ignoreGammaAndColorProfile;
        ImageOrientation m_orientation;

    private:
        // Some code paths compute the size of the image as "width * height * 4"
        // and return it as a (signed) int.  Avoid overflow.
        static bool isOverSize(unsigned width, unsigned height)
        {
            unsigned long long total_size = static_cast<unsigned long long>(width)
                                          * static_cast<unsigned long long>(height);
            return total_size > ((1 << 29) - 1);
        }

        IntSize m_size;
        bool m_sizeAvailable;
        bool m_isAllDataReceived;
        bool m_failed;
    };

} // namespace WebCore

#endif

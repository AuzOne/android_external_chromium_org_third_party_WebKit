# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := third_party_WebKit_Source_platform_blink_platform_gyp
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES := \
	$(call intermediates-dir-for,GYP,third_party_WebKit_Source_config_gyp,,,$(GYP_VAR_PREFIX))/config.stamp \
	$(call intermediates-dir-for,GYP,third_party_WebKit_Source_platform_blink_prerequisites_gyp,,,$(GYP_VAR_PREFIX))/blink_prerequisites.stamp \
	$(call intermediates-dir-for,GYP,skia_skia_gyp,,,$(GYP_VAR_PREFIX))/skia.stamp \
	$(call intermediates-dir-for,STATIC_LIBRARIES,skia_skia_library_gyp,,,$(GYP_VAR_PREFIX))/skia_skia_library_gyp.a \
	$(call intermediates-dir-for,GYP,third_party_icu_icui18n_gyp,,,$(GYP_VAR_PREFIX))/icui18n.stamp \
	$(call intermediates-dir-for,GYP,third_party_icu_icuuc_gyp,,,$(GYP_VAR_PREFIX))/icuuc.stamp \
	$(call intermediates-dir-for,GYP,third_party_libwebp_libwebp_gyp,,,$(GYP_VAR_PREFIX))/webp.stamp \
	$(call intermediates-dir-for,GYP,v8_tools_gyp_v8_gyp,,,$(GYP_VAR_PREFIX))/v8.stamp \
	$(call intermediates-dir-for,GYP,third_party_WebKit_Source_platform_make_platform_generated_gyp,,,$(GYP_VAR_PREFIX))/make_platform_generated.stamp \
	$(call intermediates-dir-for,GYP,third_party_libjpeg_libjpeg_gyp,,,$(GYP_VAR_PREFIX))/libjpeg.stamp

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

$(gyp_intermediate_dir)/FontFamilyNames.cpp: $(gyp_shared_intermediate_dir)/blink/platform/FontFamilyNames.cpp
	mkdir -p $(@D); cp $< $@
$(gyp_intermediate_dir)/RuntimeEnabledFeatures.cpp: $(gyp_shared_intermediate_dir)/blink/platform/RuntimeEnabledFeatures.cpp
	mkdir -p $(@D); cp $< $@
$(gyp_intermediate_dir)/ColorData.cpp: $(gyp_shared_intermediate_dir)/blink/platform/ColorData.cpp
	mkdir -p $(@D); cp $< $@
LOCAL_GENERATED_SOURCES := \
	$(gyp_intermediate_dir)/FontFamilyNames.cpp \
	$(gyp_intermediate_dir)/RuntimeEnabledFeatures.cpp \
	$(gyp_intermediate_dir)/ColorData.cpp

GYP_COPIED_SOURCE_ORIGIN_DIRS := \
	$(gyp_shared_intermediate_dir)/blink/platform

LOCAL_SRC_FILES := \
	third_party/WebKit/Source/platform/Clock.cpp \
	third_party/WebKit/Source/platform/ColorChooser.cpp \
	third_party/WebKit/Source/platform/ColorChooserClient.cpp \
	third_party/WebKit/Source/platform/ContentType.cpp \
	third_party/WebKit/Source/platform/ContextMenu.cpp \
	third_party/WebKit/Source/platform/ContextMenuItem.cpp \
	third_party/WebKit/Source/platform/CrossThreadCopier.cpp \
	third_party/WebKit/Source/platform/Crypto.cpp \
	third_party/WebKit/Source/platform/Cursor.cpp \
	third_party/WebKit/Source/platform/DateComponents.cpp \
	third_party/WebKit/Source/platform/DateTimeChooser.cpp \
	third_party/WebKit/Source/platform/DateTimeChooserClient.cpp \
	third_party/WebKit/Source/platform/Decimal.cpp \
	third_party/WebKit/Source/platform/DragImage.cpp \
	third_party/WebKit/Source/platform/EventTracer.cpp \
	third_party/WebKit/Source/platform/FileChooser.cpp \
	third_party/WebKit/Source/platform/FileMetadata.cpp \
	third_party/WebKit/Source/platform/JSONValues.cpp \
	third_party/WebKit/Source/platform/KillRingNone.cpp \
	third_party/WebKit/Source/platform/Language.cpp \
	third_party/WebKit/Source/platform/LayoutTestSupport.cpp \
	third_party/WebKit/Source/platform/Length.cpp \
	third_party/WebKit/Source/platform/LengthBox.cpp \
	third_party/WebKit/Source/platform/LengthFunctions.cpp \
	third_party/WebKit/Source/platform/LinkHash.cpp \
	third_party/WebKit/Source/platform/Logging.cpp \
	third_party/WebKit/Source/platform/MIMETypeFromURL.cpp \
	third_party/WebKit/Source/platform/MIMETypeRegistry.cpp \
	third_party/WebKit/Source/platform/NotImplemented.cpp \
	third_party/WebKit/Source/platform/OverscrollTheme.cpp \
	third_party/WebKit/Source/platform/Partitions.cpp \
	third_party/WebKit/Source/platform/PermissionCallbacks.cpp \
	third_party/WebKit/Source/platform/PlatformInstrumentation.cpp \
	third_party/WebKit/Source/platform/PlatformKeyboardEvent.cpp \
	third_party/WebKit/Source/platform/PlatformScreen.cpp \
	third_party/WebKit/Source/platform/PlatformThreadData.cpp \
	third_party/WebKit/Source/platform/Prerender.cpp \
	third_party/WebKit/Source/platform/PurgeableVector.cpp \
	third_party/WebKit/Source/platform/SSLKeyGenerator.cpp \
	third_party/WebKit/Source/platform/ScriptForbiddenScope.cpp \
	third_party/WebKit/Source/platform/SecureTextInput.cpp \
	third_party/WebKit/Source/platform/SharedBuffer.cpp \
	third_party/WebKit/Source/platform/SharedBufferChunkReader.cpp \
	third_party/WebKit/Source/platform/SharedTimer.cpp \
	third_party/WebKit/Source/platform/TaskSynchronizer.cpp \
	third_party/WebKit/Source/platform/Theme.cpp \
	third_party/WebKit/Source/platform/ThreadTimers.cpp \
	third_party/WebKit/Source/platform/Timer.cpp \
	third_party/WebKit/Source/platform/TracedValue.cpp \
	third_party/WebKit/Source/platform/UserGestureIndicator.cpp \
	third_party/WebKit/Source/platform/URLPatternMatcher.cpp \
	third_party/WebKit/Source/platform/UUID.cpp \
	third_party/WebKit/Source/platform/Widget.cpp \
	third_party/WebKit/Source/platform/animation/KeyframeValueList.cpp \
	third_party/WebKit/Source/platform/animation/TimingFunction.cpp \
	third_party/WebKit/Source/platform/audio/AudioBus.cpp \
	third_party/WebKit/Source/platform/audio/AudioChannel.cpp \
	third_party/WebKit/Source/platform/audio/AudioDSPKernel.cpp \
	third_party/WebKit/Source/platform/audio/AudioDSPKernelProcessor.cpp \
	third_party/WebKit/Source/platform/audio/AudioDelayDSPKernel.cpp \
	third_party/WebKit/Source/platform/audio/AudioDestination.cpp \
	third_party/WebKit/Source/platform/audio/AudioDestinationConsumer.cpp \
	third_party/WebKit/Source/platform/audio/AudioFIFO.cpp \
	third_party/WebKit/Source/platform/audio/AudioProcessor.cpp \
	third_party/WebKit/Source/platform/audio/AudioPullFIFO.cpp \
	third_party/WebKit/Source/platform/audio/AudioResampler.cpp \
	third_party/WebKit/Source/platform/audio/AudioResamplerKernel.cpp \
	third_party/WebKit/Source/platform/audio/AudioUtilities.cpp \
	third_party/WebKit/Source/platform/audio/Biquad.cpp \
	third_party/WebKit/Source/platform/audio/Cone.cpp \
	third_party/WebKit/Source/platform/audio/DirectConvolver.cpp \
	third_party/WebKit/Source/platform/audio/Distance.cpp \
	third_party/WebKit/Source/platform/audio/DownSampler.cpp \
	third_party/WebKit/Source/platform/audio/DynamicsCompressor.cpp \
	third_party/WebKit/Source/platform/audio/DynamicsCompressorKernel.cpp \
	third_party/WebKit/Source/platform/audio/EqualPowerPanner.cpp \
	third_party/WebKit/Source/platform/audio/FFTConvolver.cpp \
	third_party/WebKit/Source/platform/audio/FFTFrame.cpp \
	third_party/WebKit/Source/platform/audio/FFTFrameStub.cpp \
	third_party/WebKit/Source/platform/audio/HRTFDatabase.cpp \
	third_party/WebKit/Source/platform/audio/HRTFDatabaseLoader.cpp \
	third_party/WebKit/Source/platform/audio/HRTFElevation.cpp \
	third_party/WebKit/Source/platform/audio/HRTFKernel.cpp \
	third_party/WebKit/Source/platform/audio/HRTFPanner.cpp \
	third_party/WebKit/Source/platform/audio/MultiChannelResampler.cpp \
	third_party/WebKit/Source/platform/audio/Panner.cpp \
	third_party/WebKit/Source/platform/audio/Reverb.cpp \
	third_party/WebKit/Source/platform/audio/ReverbAccumulationBuffer.cpp \
	third_party/WebKit/Source/platform/audio/ReverbConvolver.cpp \
	third_party/WebKit/Source/platform/audio/ReverbConvolverStage.cpp \
	third_party/WebKit/Source/platform/audio/ReverbInputBuffer.cpp \
	third_party/WebKit/Source/platform/audio/SincResampler.cpp \
	third_party/WebKit/Source/platform/audio/UpSampler.cpp \
	third_party/WebKit/Source/platform/audio/VectorMath.cpp \
	third_party/WebKit/Source/platform/audio/ZeroPole.cpp \
	third_party/WebKit/Source/platform/audio/android/FFTFrameOpenMAXDLAndroid.cpp \
	third_party/WebKit/Source/platform/audio/ffmpeg/FFTFrameFFMPEG.cpp \
	third_party/WebKit/Source/platform/audio/ipp/FFTFrameIPP.cpp \
	third_party/WebKit/Source/platform/blob/BlobData.cpp \
	third_party/WebKit/Source/platform/blob/BlobRegistry.cpp \
	third_party/WebKit/Source/platform/blob/BlobURL.cpp \
	third_party/WebKit/Source/platform/clipboard/ClipboardMimeTypes.cpp \
	third_party/WebKit/Source/platform/clipboard/ClipboardUtilities.cpp \
	third_party/WebKit/Source/platform/clipboard/ClipboardUtilitiesPosix.cpp \
	third_party/WebKit/Source/platform/exported/Platform.cpp \
	third_party/WebKit/Source/platform/exported/WebActiveGestureAnimation.cpp \
	third_party/WebKit/Source/platform/exported/WebArrayBuffer.cpp \
	third_party/WebKit/Source/platform/exported/WebAudioBus.cpp \
	third_party/WebKit/Source/platform/exported/WebAudioDevice.cpp \
	third_party/WebKit/Source/platform/exported/WebBlobData.cpp \
	third_party/WebKit/Source/platform/exported/WebContentDecryptionModule.cpp \
	third_party/WebKit/Source/platform/exported/WebContentDecryptionModuleResult.cpp \
	third_party/WebKit/Source/platform/exported/WebContentDecryptionModuleSession.cpp \
	third_party/WebKit/Source/platform/exported/WebConvertableToTraceFormat.cpp \
	third_party/WebKit/Source/platform/exported/WebCryptoAlgorithm.cpp \
	third_party/WebKit/Source/platform/exported/WebCryptoKeyAlgorithm.cpp \
	third_party/WebKit/Source/platform/exported/WebCryptoKey.cpp \
	third_party/WebKit/Source/platform/exported/WebCryptoResult.cpp \
	third_party/WebKit/Source/platform/exported/WebCursorInfo.cpp \
	third_party/WebKit/Source/platform/exported/WebData.cpp \
	third_party/WebKit/Source/platform/exported/WebDeviceMotionData.cpp \
	third_party/WebKit/Source/platform/exported/WebDeviceOrientationData.cpp \
	third_party/WebKit/Source/platform/exported/WebFileSystemCallbacks.cpp \
	third_party/WebKit/Source/platform/exported/WebFilterKeyframe.cpp \
	third_party/WebKit/Source/platform/exported/WebHTTPBody.cpp \
	third_party/WebKit/Source/platform/exported/WebHTTPLoadInfo.cpp \
	third_party/WebKit/Source/platform/exported/WebImageSkia.cpp \
	third_party/WebKit/Source/platform/exported/WebMediaConstraints.cpp \
	third_party/WebKit/Source/platform/exported/WebMediaDeviceInfo.cpp \
	third_party/WebKit/Source/platform/exported/WebMediaStream.cpp \
	third_party/WebKit/Source/platform/exported/WebMediaStreamSource.cpp \
	third_party/WebKit/Source/platform/exported/WebMediaStreamTrack.cpp \
	third_party/WebKit/Source/platform/exported/WebMediaStreamTrackSourcesRequest.cpp \
	third_party/WebKit/Source/platform/exported/WebPermissionCallbacks.cpp \
	third_party/WebKit/Source/platform/exported/WebPrerender.cpp \
	third_party/WebKit/Source/platform/exported/WebPrerenderingSupport.cpp \
	third_party/WebKit/Source/platform/exported/WebRTCConfiguration.cpp \
	third_party/WebKit/Source/platform/exported/WebRTCICECandidate.cpp \
	third_party/WebKit/Source/platform/exported/WebRTCOfferOptions.cpp \
	third_party/WebKit/Source/platform/exported/WebRTCSessionDescription.cpp \
	third_party/WebKit/Source/platform/exported/WebRTCSessionDescriptionRequest.cpp \
	third_party/WebKit/Source/platform/exported/WebRTCStatsRequest.cpp \
	third_party/WebKit/Source/platform/exported/WebRTCStatsResponse.cpp \
	third_party/WebKit/Source/platform/exported/WebRTCVoidRequest.cpp \
	third_party/WebKit/Source/platform/exported/WebSchedulerProxy.cpp \
	third_party/WebKit/Source/platform/exported/WebScrollbarImpl.cpp \
	third_party/WebKit/Source/platform/exported/WebScrollbarThemeClientImpl.cpp \
	third_party/WebKit/Source/platform/exported/WebScrollbarThemeGeometryNative.cpp \
	third_party/WebKit/Source/platform/exported/WebSerializedOrigin.cpp \
	third_party/WebKit/Source/platform/exported/WebServiceWorkerProxy.cpp \
	third_party/WebKit/Source/platform/exported/WebServiceWorkerRequest.cpp \
	third_party/WebKit/Source/platform/exported/WebServiceWorkerResponse.cpp \
	third_party/WebKit/Source/platform/exported/WebSocketHandshakeRequestInfo.cpp \
	third_party/WebKit/Source/platform/exported/WebSocketHandshakeResponseInfo.cpp \
	third_party/WebKit/Source/platform/exported/WebSocketStreamError.cpp \
	third_party/WebKit/Source/platform/exported/WebSourceInfo.cpp \
	third_party/WebKit/Source/platform/exported/WebSpeechSynthesisUtterance.cpp \
	third_party/WebKit/Source/platform/exported/WebSpeechSynthesisVoice.cpp \
	third_party/WebKit/Source/platform/exported/WebSpeechSynthesizerClientImpl.cpp \
	third_party/WebKit/Source/platform/exported/WebStorageQuotaCallbacks.cpp \
	third_party/WebKit/Source/platform/exported/WebThreadSafeData.cpp \
	third_party/WebKit/Source/platform/exported/WebTransformKeyframe.cpp \
	third_party/WebKit/Source/platform/exported/WebURL.cpp \
	third_party/WebKit/Source/platform/exported/WebURLError.cpp \
	third_party/WebKit/Source/platform/exported/WebURLLoadTiming.cpp \
	third_party/WebKit/Source/platform/exported/WebURLRequest.cpp \
	third_party/WebKit/Source/platform/exported/WebURLResponse.cpp \
	third_party/WebKit/Source/platform/exported/linux/WebFontRenderStyle.cpp \
	third_party/WebKit/Source/platform/fonts/Character.cpp \
	third_party/WebKit/Source/platform/fonts/Font.cpp \
	third_party/WebKit/Source/platform/fonts/FontCache.cpp \
	third_party/WebKit/Source/platform/fonts/FontData.cpp \
	third_party/WebKit/Source/platform/fonts/FontDataCache.cpp \
	third_party/WebKit/Source/platform/fonts/FontDescription.cpp \
	third_party/WebKit/Source/platform/fonts/FontFallbackList.cpp \
	third_party/WebKit/Source/platform/fonts/FontFamily.cpp \
	third_party/WebKit/Source/platform/fonts/FontFeatureSettings.cpp \
	third_party/WebKit/Source/platform/fonts/GenericFontFamilySettings.cpp \
	third_party/WebKit/Source/platform/fonts/GlyphPageTreeNode.cpp \
	third_party/WebKit/Source/platform/fonts/SVGGlyph.cpp \
	third_party/WebKit/Source/platform/fonts/SegmentedFontData.cpp \
	third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp \
	third_party/WebKit/Source/platform/fonts/VDMXParser.cpp \
	third_party/WebKit/Source/platform/fonts/WidthIterator.cpp \
	third_party/WebKit/Source/platform/fonts/android/FontCacheAndroid.cpp \
	third_party/WebKit/Source/platform/fonts/harfbuzz/FontHarfBuzz.cpp \
	third_party/WebKit/Source/platform/fonts/harfbuzz/FontPlatformDataHarfBuzz.cpp \
	third_party/WebKit/Source/platform/fonts/harfbuzz/HarfBuzzFace.cpp \
	third_party/WebKit/Source/platform/fonts/harfbuzz/HarfBuzzFaceSkia.cpp \
	third_party/WebKit/Source/platform/fonts/harfbuzz/HarfBuzzShaper.cpp \
	third_party/WebKit/Source/platform/fonts/linux/FontPlatformDataLinux.cpp \
	third_party/WebKit/Source/platform/fonts/opentype/OpenTypeSanitizer.cpp \
	third_party/WebKit/Source/platform/fonts/opentype/OpenTypeVerticalData.cpp \
	third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp \
	third_party/WebKit/Source/platform/fonts/skia/FontCustomPlatformDataSkia.cpp \
	third_party/WebKit/Source/platform/fonts/skia/FontPlatformDataSkia.cpp \
	third_party/WebKit/Source/platform/fonts/skia/SimpleFontDataSkia.cpp \
	third_party/WebKit/Source/platform/geometry/FloatPolygon.cpp \
	third_party/WebKit/Source/platform/geometry/FloatPoint.cpp \
	third_party/WebKit/Source/platform/geometry/FloatPoint3D.cpp \
	third_party/WebKit/Source/platform/geometry/FloatQuad.cpp \
	third_party/WebKit/Source/platform/geometry/FloatRect.cpp \
	third_party/WebKit/Source/platform/geometry/FloatRoundedRect.cpp \
	third_party/WebKit/Source/platform/geometry/FloatSize.cpp \
	third_party/WebKit/Source/platform/geometry/IntRect.cpp \
	third_party/WebKit/Source/platform/geometry/LayoutBoxExtent.cpp \
	third_party/WebKit/Source/platform/geometry/LayoutRect.cpp \
	third_party/WebKit/Source/platform/geometry/Region.cpp \
	third_party/WebKit/Source/platform/geometry/RoundedRect.cpp \
	third_party/WebKit/Source/platform/geometry/TransformState.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEBlend.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEColorMatrix.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEComponentTransfer.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEComposite.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEConvolveMatrix.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEDiffuseLighting.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEDisplacementMap.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEDropShadow.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEFlood.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEGaussianBlur.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FELighting.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEMerge.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEMorphology.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FEOffset.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FESpecularLighting.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FETile.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FETurbulence.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FilterEffect.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FilterOperation.cpp \
	third_party/WebKit/Source/platform/graphics/filters/FilterOperations.cpp \
	third_party/WebKit/Source/platform/graphics/filters/LightSource.cpp \
	third_party/WebKit/Source/platform/graphics/filters/DistantLightSource.cpp \
	third_party/WebKit/Source/platform/graphics/filters/PointLightSource.cpp \
	third_party/WebKit/Source/platform/graphics/filters/ReferenceFilter.cpp \
	third_party/WebKit/Source/platform/graphics/filters/SkiaImageFilterBuilder.cpp \
	third_party/WebKit/Source/platform/graphics/filters/SourceAlpha.cpp \
	third_party/WebKit/Source/platform/graphics/filters/SourceGraphic.cpp \
	third_party/WebKit/Source/platform/graphics/filters/SpotLightSource.cpp \
	third_party/WebKit/Source/platform/graphics/gpu/DrawingBuffer.cpp \
	third_party/WebKit/Source/platform/graphics/gpu/Extensions3DUtil.cpp \
	third_party/WebKit/Source/platform/graphics/gpu/WebGLImageBufferSurface.cpp \
	third_party/WebKit/Source/platform/graphics/gpu/WebGLImageConversion.cpp \
	third_party/WebKit/Source/platform/graphics/media/MediaPlayer.cpp \
	third_party/WebKit/Source/platform/graphics/skia/GaneshUtils.cpp \
	third_party/WebKit/Source/platform/graphics/skia/NativeImageSkia.cpp \
	third_party/WebKit/Source/platform/graphics/skia/SkiaUtils.cpp \
	third_party/WebKit/Source/platform/graphics/BitmapImage.cpp \
	third_party/WebKit/Source/platform/graphics/Canvas2DLayerBridge.cpp \
	third_party/WebKit/Source/platform/graphics/Canvas2DLayerManager.cpp \
	third_party/WebKit/Source/platform/graphics/Color.cpp \
	third_party/WebKit/Source/platform/graphics/ColorSpace.cpp \
	third_party/WebKit/Source/platform/graphics/CompositingReasons.cpp \
	third_party/WebKit/Source/platform/graphics/CrossfadeGeneratedImage.cpp \
	third_party/WebKit/Source/platform/graphics/DecodingImageGenerator.cpp \
	third_party/WebKit/Source/platform/graphics/DeferredImageDecoder.cpp \
	third_party/WebKit/Source/platform/graphics/DiscardablePixelRef.cpp \
	third_party/WebKit/Source/platform/graphics/DisplayList.cpp \
	third_party/WebKit/Source/platform/graphics/DrawLooperBuilder.cpp \
	third_party/WebKit/Source/platform/graphics/FrameData.cpp \
	third_party/WebKit/Source/platform/graphics/GeneratedImage.cpp \
	third_party/WebKit/Source/platform/graphics/Gradient.cpp \
	third_party/WebKit/Source/platform/graphics/GradientGeneratedImage.cpp \
	third_party/WebKit/Source/platform/graphics/GraphicsContext.cpp \
	third_party/WebKit/Source/platform/graphics/GraphicsContextRecorder.cpp \
	third_party/WebKit/Source/platform/graphics/GraphicsContextState.cpp \
	third_party/WebKit/Source/platform/graphics/GraphicsLayer.cpp \
	third_party/WebKit/Source/platform/graphics/GraphicsLayerDebugInfo.cpp \
	third_party/WebKit/Source/platform/graphics/GraphicsTypes.cpp \
	third_party/WebKit/Source/platform/graphics/Image.cpp \
	third_party/WebKit/Source/platform/graphics/ImageBuffer.cpp \
	third_party/WebKit/Source/platform/graphics/ImageBufferSurface.cpp \
	third_party/WebKit/Source/platform/graphics/ImageDecodingStore.cpp \
	third_party/WebKit/Source/platform/graphics/ImageFrameGenerator.cpp \
	third_party/WebKit/Source/platform/graphics/ImageObserver.cpp \
	third_party/WebKit/Source/platform/graphics/ImageOrientation.cpp \
	third_party/WebKit/Source/platform/graphics/ImageSource.cpp \
	third_party/WebKit/Source/platform/graphics/LazyDecodingPixelRef.cpp \
	third_party/WebKit/Source/platform/graphics/LoggingCanvas.cpp \
	third_party/WebKit/Source/platform/graphics/OpaqueRectTrackingContentLayerDelegate.cpp \
	third_party/WebKit/Source/platform/graphics/Path.cpp \
	third_party/WebKit/Source/platform/graphics/PathTraversalState.cpp \
	third_party/WebKit/Source/platform/graphics/Pattern.cpp \
	third_party/WebKit/Source/platform/graphics/ProfilingCanvas.cpp \
	third_party/WebKit/Source/platform/graphics/RecordingImageBufferSurface.cpp \
	third_party/WebKit/Source/platform/graphics/RegionTracker.cpp \
	third_party/WebKit/Source/platform/graphics/ReplayingCanvas.cpp \
	third_party/WebKit/Source/platform/graphics/ScaledImageFragment.cpp \
	third_party/WebKit/Source/platform/graphics/StrokeData.cpp \
	third_party/WebKit/Source/platform/graphics/ThreadSafeDataTransport.cpp \
	third_party/WebKit/Source/platform/graphics/UnacceleratedImageBufferSurface.cpp \
	third_party/WebKit/Source/platform/image-decoders/ImageDecoder.cpp \
	third_party/WebKit/Source/platform/image-decoders/ImageFrame.cpp \
	third_party/WebKit/Source/platform/image-decoders/bmp/BMPImageDecoder.cpp \
	third_party/WebKit/Source/platform/image-decoders/bmp/BMPImageReader.cpp \
	third_party/WebKit/Source/platform/image-decoders/gif/GIFImageDecoder.cpp \
	third_party/WebKit/Source/platform/image-decoders/gif/GIFImageReader.cpp \
	third_party/WebKit/Source/platform/image-decoders/ico/ICOImageDecoder.cpp \
	third_party/WebKit/Source/platform/image-decoders/jpeg/JPEGImageDecoder.cpp \
	third_party/WebKit/Source/platform/image-decoders/png/PNGImageDecoder.cpp \
	third_party/WebKit/Source/platform/image-decoders/webp/WEBPImageDecoder.cpp \
	third_party/WebKit/Source/platform/image-encoders/skia/JPEGImageEncoder.cpp \
	third_party/WebKit/Source/platform/image-encoders/skia/PNGImageEncoder.cpp \
	third_party/WebKit/Source/platform/image-encoders/skia/WEBPImageEncoder.cpp \
	third_party/WebKit/Source/platform/mediastream/MediaStreamCenter.cpp \
	third_party/WebKit/Source/platform/mediastream/MediaStreamComponent.cpp \
	third_party/WebKit/Source/platform/mediastream/MediaStreamDescriptor.cpp \
	third_party/WebKit/Source/platform/mediastream/MediaStreamSource.cpp \
	third_party/WebKit/Source/platform/mediastream/MediaStreamWebAudioSource.cpp \
	third_party/WebKit/Source/platform/mhtml/ArchiveResource.cpp \
	third_party/WebKit/Source/platform/mhtml/ArchiveResourceCollection.cpp \
	third_party/WebKit/Source/platform/mhtml/MHTMLArchive.cpp \
	third_party/WebKit/Source/platform/mhtml/MHTMLParser.cpp \
	third_party/WebKit/Source/platform/network/ContentSecurityPolicyParsers.cpp \
	third_party/WebKit/Source/platform/network/ContentSecurityPolicyResponseHeaders.cpp \
	third_party/WebKit/Source/platform/network/DNS.cpp \
	third_party/WebKit/Source/platform/network/HTTPHeaderMap.cpp \
	third_party/WebKit/Source/platform/network/HTTPParsers.cpp \
	third_party/WebKit/Source/platform/network/HTTPRequest.cpp \
	third_party/WebKit/Source/platform/network/ParsedContentType.cpp \
	third_party/WebKit/Source/platform/network/ProxyServer.cpp \
	third_party/WebKit/Source/platform/network/ResourceError.cpp \
	third_party/WebKit/Source/platform/network/SocketStreamError.cpp \
	third_party/WebKit/Source/platform/network/SocketStreamHandle.cpp \
	third_party/WebKit/Source/platform/network/FormData.cpp \
	third_party/WebKit/Source/platform/network/FormDataBuilder.cpp \
	third_party/WebKit/Source/platform/network/ResourceRequest.cpp \
	third_party/WebKit/Source/platform/network/ResourceResponse.cpp \
	third_party/WebKit/Source/platform/network/WebSocketHandshakeRequest.cpp \
	third_party/WebKit/Source/platform/network/WebSocketHandshakeResponse.cpp \
	third_party/WebKit/Source/platform/plugins/PluginData.cpp \
	third_party/WebKit/Source/platform/plugins/PluginListBuilder.cpp \
	third_party/WebKit/Source/platform/scheduler/Scheduler.cpp \
	third_party/WebKit/Source/platform/scroll/FramelessScrollView.cpp \
	third_party/WebKit/Source/platform/scroll/ProgrammaticScrollAnimator.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollAnimator.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollAnimatorNone.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollView.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollableArea.cpp \
	third_party/WebKit/Source/platform/scroll/Scrollbar.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollbarTheme.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollbarThemeAndroid.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollbarThemeMock.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollbarThemeNonMacCommon.cpp \
	third_party/WebKit/Source/platform/scroll/ScrollbarThemeOverlay.cpp \
	third_party/WebKit/Source/platform/speech/PlatformSpeechSynthesisUtterance.cpp \
	third_party/WebKit/Source/platform/speech/PlatformSpeechSynthesisVoice.cpp \
	third_party/WebKit/Source/platform/speech/PlatformSpeechSynthesizer.cpp \
	third_party/WebKit/Source/platform/text/BidiCharacterRun.cpp \
	third_party/WebKit/Source/platform/text/BidiContext.cpp \
	third_party/WebKit/Source/platform/text/BidiTextRun.cpp \
	third_party/WebKit/Source/platform/text/DateTimeFormat.cpp \
	third_party/WebKit/Source/platform/text/LineEnding.cpp \
	third_party/WebKit/Source/platform/text/LocaleICU.cpp \
	third_party/WebKit/Source/platform/text/LocaleToScriptMapping.cpp \
	third_party/WebKit/Source/platform/text/PlatformLocale.cpp \
	third_party/WebKit/Source/platform/text/QuotedPrintable.cpp \
	third_party/WebKit/Source/platform/text/SegmentedString.cpp \
	third_party/WebKit/Source/platform/text/StringTruncator.cpp \
	third_party/WebKit/Source/platform/text/SurrogatePairAwareTextIterator.cpp \
	third_party/WebKit/Source/platform/text/TextBoundaries.cpp \
	third_party/WebKit/Source/platform/text/TextBreakIterator.cpp \
	third_party/WebKit/Source/platform/text/TextBreakIteratorICU.cpp \
	third_party/WebKit/Source/platform/text/TextBreakIteratorInternalICU.cpp \
	third_party/WebKit/Source/platform/text/TextEncodingDetector.cpp \
	third_party/WebKit/Source/platform/text/TextRun.cpp \
	third_party/WebKit/Source/platform/text/TextStream.cpp \
	third_party/WebKit/Source/platform/text/UnicodeRange.cpp \
	third_party/WebKit/Source/platform/text/UnicodeUtilities.cpp \
	third_party/WebKit/Source/platform/transforms/AffineTransform.cpp \
	third_party/WebKit/Source/platform/transforms/InterpolatedTransformOperation.cpp \
	third_party/WebKit/Source/platform/transforms/Matrix3DTransformOperation.cpp \
	third_party/WebKit/Source/platform/transforms/MatrixTransformOperation.cpp \
	third_party/WebKit/Source/platform/transforms/PerspectiveTransformOperation.cpp \
	third_party/WebKit/Source/platform/transforms/RotateTransformOperation.cpp \
	third_party/WebKit/Source/platform/transforms/ScaleTransformOperation.cpp \
	third_party/WebKit/Source/platform/transforms/SkewTransformOperation.cpp \
	third_party/WebKit/Source/platform/transforms/TransformOperations.cpp \
	third_party/WebKit/Source/platform/transforms/TranslateTransformOperation.cpp \
	third_party/WebKit/Source/platform/transforms/TransformationMatrix.cpp \
	third_party/WebKit/Source/platform/weborigin/DatabaseIdentifier.cpp \
	third_party/WebKit/Source/platform/weborigin/KURL.cpp \
	third_party/WebKit/Source/platform/weborigin/KnownPorts.cpp \
	third_party/WebKit/Source/platform/weborigin/OriginAccessEntry.cpp \
	third_party/WebKit/Source/platform/weborigin/SchemeRegistry.cpp \
	third_party/WebKit/Source/platform/weborigin/SecurityOrigin.cpp \
	third_party/WebKit/Source/platform/weborigin/SecurityPolicy.cpp \
	third_party/WebKit/Source/platform/heap/Heap.cpp \
	third_party/WebKit/Source/platform/heap/ThreadState.cpp \
	third_party/WebKit/Source/platform/heap/Visitor.cpp


# Flags passed to both C and C++ files.
MY_CFLAGS_Debug := \
	--param=ssp-buffer-size=4 \
	-Werror \
	-fno-exceptions \
	-fno-strict-aliasing \
	-Wall \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wno-unused-local-typedefs \
	-msse2 \
	-mfpmath=sse \
	-mmmx \
	-m32 \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fno-short-enums \
	-finline-limit=64 \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-unused-but-set-variable \
	-fno-stack-protector \
	-Os \
	-g \
	-fdata-sections \
	-ffunction-sections \
	-fomit-frame-pointer \
	-funwind-tables

MY_DEFS_Debug := \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DBLINK_SCALE_FILTERS_AT_RECORD_TIME' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DENABLE_WEBRTC=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_BROWSER_CDMS' \
	'-DENABLE_CONFIGURATION_POLICY' \
	'-DDISCARDABLE_MEMORY_ALWAYS_SUPPORTED_NATIVELY' \
	'-DSYSTEM_NATIVELY_SIGNALS_MEMORY_PRESSURE' \
	'-DENABLE_EGLIMAGE=1' \
	'-DCLD_VERSION=1' \
	'-DENABLE_PRINTING=1' \
	'-DENABLE_MANAGED_USERS=1' \
	'-DDATA_REDUCTION_FALLBACK_HOST="http://compress.googlezip.net:80/"' \
	'-DDATA_REDUCTION_DEV_HOST="http://proxy-dev.googlezip.net:80/"' \
	'-DSPDY_PROXY_AUTH_ORIGIN="https://proxy.googlezip.net:443/"' \
	'-DDATA_REDUCTION_PROXY_PROBE_URL="http://check.googlezip.net/connect"' \
	'-DDATA_REDUCTION_PROXY_WARMUP_URL="http://www.gstatic.com/generate_204"' \
	'-DVIDEO_HOLE=1' \
	'-DBLINK_PLATFORM_IMPLEMENTATION=1' \
	'-DINSIDE_BLINK' \
	'-DENABLE_CUSTOM_SCHEME_HANDLER=0' \
	'-DENABLE_SVG_FONTS=1' \
	'-DWTF_USE_CONCATENATED_IMPULSE_RESPONSES=1' \
	'-DWTF_USE_WEBAUDIO_OPENMAX_DL_FFT=1' \
	'-DENABLE_WEB_AUDIO=1' \
	'-DENABLE_OPENTYPE_VERTICAL=1' \
	'-DSK_ENABLE_INST_COUNT=0' \
	'-DSK_SUPPORT_GPU=1' \
	'-DGR_GL_CUSTOM_SETUP_HEADER="GrGLConfig_chrome.h"' \
	'-DSK_ENABLE_LEGACY_API_ALIASING=1' \
	'-DSK_ATTR_DEPRECATED=SK_NOTHING_ARG1' \
	'-DGR_GL_IGNORE_ES3_MSAA=0' \
	'-DSK_WILL_NEVER_DRAW_PERSPECTIVE_TEXT' \
	'-DSK_SUPPORT_LEGACY_PICTURE_CLONE' \
	'-DSK_SUPPORT_LEGACY_GETDEVICE' \
	'-DSK_IGNORE_ETC1_SUPPORT' \
	'-DSK_IGNORE_GPU_DITHER' \
	'-DSK_BUILD_FOR_ANDROID' \
	'-DSK_USE_POSIX_THREADS' \
	'-DSK_DEFERRED_CANVAS_USES_FACTORIES=1' \
	'-DU_USING_ICU_NAMESPACE=0' \
	'-DU_ENABLE_DYLOAD=0' \
	'-DCHROME_PNG_WRITE_SUPPORT' \
	'-DPNG_USER_CONFIG' \
	'-DCHROME_PNG_READ_PACK_SUPPORT' \
	'-DUSE_SYSTEM_LIBJPEG' \
	'-DUSE_OPENSSL=1' \
	'-DUSE_OPENSSL_CERTS=1' \
	'-D__STDC_CONSTANT_MACROS' \
	'-D__STDC_FORMAT_MACROS' \
	'-DANDROID' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=1' \
	'-DWTF_USE_DYNAMIC_ANNOTATIONS=1' \
	'-D_DEBUG'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Debug := \
	$(gyp_shared_intermediate_dir)/shim_headers/ashmem/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icuuc/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icui18n/target \
	$(gyp_shared_intermediate_dir) \
	$(LOCAL_PATH)/third_party/angle/include \
	$(gyp_shared_intermediate_dir)/blink \
	$(LOCAL_PATH)/third_party/openmax_dl \
	$(LOCAL_PATH)/third_party/WebKit/Source \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/skia/config \
	$(LOCAL_PATH)/third_party/khronos \
	$(LOCAL_PATH)/gpu \
	$(LOCAL_PATH)/third_party/WebKit \
	$(LOCAL_PATH)/third_party/skia/src/core \
	$(LOCAL_PATH)/third_party/skia/include/core \
	$(LOCAL_PATH)/third_party/skia/include/effects \
	$(LOCAL_PATH)/third_party/skia/include/pdf \
	$(LOCAL_PATH)/third_party/skia/include/gpu \
	$(LOCAL_PATH)/third_party/skia/include/lazy \
	$(LOCAL_PATH)/third_party/skia/include/pathops \
	$(LOCAL_PATH)/third_party/skia/include/pipe \
	$(LOCAL_PATH)/third_party/skia/include/ports \
	$(LOCAL_PATH)/third_party/skia/include/utils \
	$(LOCAL_PATH)/skia/ext \
	$(PWD)/external/icu/icu4c/source/common \
	$(PWD)/external/icu/icu4c/source/i18n \
	$(LOCAL_PATH)/third_party/libpng \
	$(LOCAL_PATH)/third_party/zlib \
	$(LOCAL_PATH)/third_party/libwebp \
	$(LOCAL_PATH)/third_party/ots/include \
	$(LOCAL_PATH)/third_party/qcms/src \
	$(LOCAL_PATH)/v8/include \
	$(LOCAL_PATH)/third_party/iccjpeg \
	$(PWD)/external/jpeg \
	$(LOCAL_PATH)/third_party/harfbuzz-ng/src \
	$(LOCAL_PATH)/third_party/openmax_dl \
	$(PWD)/frameworks/wilhelm/include \
	$(PWD)/bionic \
	$(PWD)/external/stlport/stlport


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Debug := \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wsign-compare \
	-Wno-c++0x-compat \
	-std=gnu++11 \
	-Wno-narrowing \
	-Wno-literal-suffix \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo


# Flags passed to both C and C++ files.
MY_CFLAGS_Release := \
	--param=ssp-buffer-size=4 \
	-Werror \
	-fno-exceptions \
	-fno-strict-aliasing \
	-Wall \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wno-unused-local-typedefs \
	-msse2 \
	-mfpmath=sse \
	-mmmx \
	-m32 \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fno-short-enums \
	-finline-limit=64 \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-unused-but-set-variable \
	-fno-stack-protector \
	-Os \
	-fno-ident \
	-fdata-sections \
	-ffunction-sections \
	-fomit-frame-pointer \
	-funwind-tables

MY_DEFS_Release := \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DBLINK_SCALE_FILTERS_AT_RECORD_TIME' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DENABLE_WEBRTC=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_BROWSER_CDMS' \
	'-DENABLE_CONFIGURATION_POLICY' \
	'-DDISCARDABLE_MEMORY_ALWAYS_SUPPORTED_NATIVELY' \
	'-DSYSTEM_NATIVELY_SIGNALS_MEMORY_PRESSURE' \
	'-DENABLE_EGLIMAGE=1' \
	'-DCLD_VERSION=1' \
	'-DENABLE_PRINTING=1' \
	'-DENABLE_MANAGED_USERS=1' \
	'-DDATA_REDUCTION_FALLBACK_HOST="http://compress.googlezip.net:80/"' \
	'-DDATA_REDUCTION_DEV_HOST="http://proxy-dev.googlezip.net:80/"' \
	'-DSPDY_PROXY_AUTH_ORIGIN="https://proxy.googlezip.net:443/"' \
	'-DDATA_REDUCTION_PROXY_PROBE_URL="http://check.googlezip.net/connect"' \
	'-DDATA_REDUCTION_PROXY_WARMUP_URL="http://www.gstatic.com/generate_204"' \
	'-DVIDEO_HOLE=1' \
	'-DBLINK_PLATFORM_IMPLEMENTATION=1' \
	'-DINSIDE_BLINK' \
	'-DENABLE_CUSTOM_SCHEME_HANDLER=0' \
	'-DENABLE_SVG_FONTS=1' \
	'-DWTF_USE_CONCATENATED_IMPULSE_RESPONSES=1' \
	'-DWTF_USE_WEBAUDIO_OPENMAX_DL_FFT=1' \
	'-DENABLE_WEB_AUDIO=1' \
	'-DENABLE_OPENTYPE_VERTICAL=1' \
	'-DSK_ENABLE_INST_COUNT=0' \
	'-DSK_SUPPORT_GPU=1' \
	'-DGR_GL_CUSTOM_SETUP_HEADER="GrGLConfig_chrome.h"' \
	'-DSK_ENABLE_LEGACY_API_ALIASING=1' \
	'-DSK_ATTR_DEPRECATED=SK_NOTHING_ARG1' \
	'-DGR_GL_IGNORE_ES3_MSAA=0' \
	'-DSK_WILL_NEVER_DRAW_PERSPECTIVE_TEXT' \
	'-DSK_SUPPORT_LEGACY_PICTURE_CLONE' \
	'-DSK_SUPPORT_LEGACY_GETDEVICE' \
	'-DSK_IGNORE_ETC1_SUPPORT' \
	'-DSK_IGNORE_GPU_DITHER' \
	'-DSK_BUILD_FOR_ANDROID' \
	'-DSK_USE_POSIX_THREADS' \
	'-DSK_DEFERRED_CANVAS_USES_FACTORIES=1' \
	'-DU_USING_ICU_NAMESPACE=0' \
	'-DU_ENABLE_DYLOAD=0' \
	'-DCHROME_PNG_WRITE_SUPPORT' \
	'-DPNG_USER_CONFIG' \
	'-DCHROME_PNG_READ_PACK_SUPPORT' \
	'-DUSE_SYSTEM_LIBJPEG' \
	'-DUSE_OPENSSL=1' \
	'-DUSE_OPENSSL_CERTS=1' \
	'-D__STDC_CONSTANT_MACROS' \
	'-D__STDC_FORMAT_MACROS' \
	'-DANDROID' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DNDEBUG' \
	'-DNVALGRIND' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=0' \
	'-D_FORTIFY_SOURCE=2'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Release := \
	$(gyp_shared_intermediate_dir)/shim_headers/ashmem/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icuuc/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icui18n/target \
	$(gyp_shared_intermediate_dir) \
	$(LOCAL_PATH)/third_party/angle/include \
	$(gyp_shared_intermediate_dir)/blink \
	$(LOCAL_PATH)/third_party/openmax_dl \
	$(LOCAL_PATH)/third_party/WebKit/Source \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/skia/config \
	$(LOCAL_PATH)/third_party/khronos \
	$(LOCAL_PATH)/gpu \
	$(LOCAL_PATH)/third_party/WebKit \
	$(LOCAL_PATH)/third_party/skia/src/core \
	$(LOCAL_PATH)/third_party/skia/include/core \
	$(LOCAL_PATH)/third_party/skia/include/effects \
	$(LOCAL_PATH)/third_party/skia/include/pdf \
	$(LOCAL_PATH)/third_party/skia/include/gpu \
	$(LOCAL_PATH)/third_party/skia/include/lazy \
	$(LOCAL_PATH)/third_party/skia/include/pathops \
	$(LOCAL_PATH)/third_party/skia/include/pipe \
	$(LOCAL_PATH)/third_party/skia/include/ports \
	$(LOCAL_PATH)/third_party/skia/include/utils \
	$(LOCAL_PATH)/skia/ext \
	$(PWD)/external/icu/icu4c/source/common \
	$(PWD)/external/icu/icu4c/source/i18n \
	$(LOCAL_PATH)/third_party/libpng \
	$(LOCAL_PATH)/third_party/zlib \
	$(LOCAL_PATH)/third_party/libwebp \
	$(LOCAL_PATH)/third_party/ots/include \
	$(LOCAL_PATH)/third_party/qcms/src \
	$(LOCAL_PATH)/v8/include \
	$(LOCAL_PATH)/third_party/iccjpeg \
	$(PWD)/external/jpeg \
	$(LOCAL_PATH)/third_party/harfbuzz-ng/src \
	$(LOCAL_PATH)/third_party/openmax_dl \
	$(PWD)/frameworks/wilhelm/include \
	$(PWD)/bionic \
	$(PWD)/external/stlport/stlport


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Release := \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wsign-compare \
	-Wno-c++0x-compat \
	-std=gnu++11 \
	-Wno-narrowing \
	-Wno-literal-suffix \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo


LOCAL_CFLAGS := $(MY_CFLAGS_$(GYP_CONFIGURATION)) $(MY_DEFS_$(GYP_CONFIGURATION))
LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES_$(GYP_CONFIGURATION))
LOCAL_CPPFLAGS := $(LOCAL_CPPFLAGS_$(GYP_CONFIGURATION))
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)
### Rules for final target.

LOCAL_LDFLAGS_Debug := \
	-Wl,-z,now \
	-Wl,-z,relro \
	-Wl,--fatal-warnings \
	-Wl,-z,noexecstack \
	-fPIC \
	-m32 \
	-fuse-ld=gold \
	-nostdlib \
	-Wl,--no-undefined \
	-Wl,--exclude-libs=ALL \
	-Wl,--warn-shared-textrel \
	-Wl,-O1 \
	-Wl,--as-needed


LOCAL_LDFLAGS_Release := \
	-Wl,-z,now \
	-Wl,-z,relro \
	-Wl,--fatal-warnings \
	-Wl,-z,noexecstack \
	-fPIC \
	-m32 \
	-fuse-ld=gold \
	-nostdlib \
	-Wl,--no-undefined \
	-Wl,--exclude-libs=ALL \
	-Wl,-O1 \
	-Wl,--as-needed \
	-Wl,--gc-sections \
	-Wl,--warn-shared-textrel


LOCAL_LDFLAGS := $(LOCAL_LDFLAGS_$(GYP_CONFIGURATION))

LOCAL_STATIC_LIBRARIES := \
	skia_skia_library_gyp

# Enable grouping to fix circular references
LOCAL_GROUP_STATIC_LIBRARIES := true

LOCAL_SHARED_LIBRARIES := \
	libstlport \
	libdl

# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: third_party_WebKit_Source_platform_blink_platform_gyp

# Alias gyp target name.
.PHONY: blink_platform
blink_platform: third_party_WebKit_Source_platform_blink_platform_gyp

include $(BUILD_STATIC_LIBRARY)

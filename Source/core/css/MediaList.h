/*
 * (C) 1999-2003 Lars Knoll (knoll@kde.org)
 * Copyright (C) 2004, 2006, 2008, 2009, 2010, 2012 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef MediaList_h
#define MediaList_h

#include "core/dom/ExceptionCode.h"
#include "wtf/Forward.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"

namespace WebCore {

class CSSRule;
class CSSStyleSheet;
class Document;
class MediaList;
class MediaQuery;

class MediaQuerySet : public RefCounted<MediaQuerySet> {
public:
    static PassRefPtr<MediaQuerySet> create()
    {
        return adoptRef(new MediaQuerySet());
    }
    static PassRefPtr<MediaQuerySet> create(const String& mediaString);
    ~MediaQuerySet();

    bool set(const String&);
    bool add(const String&);
    bool remove(const String&);

    void addMediaQuery(PassOwnPtr<MediaQuery>);

    const Vector<OwnPtr<MediaQuery> >& queryVector() const { return m_queries; }

    String mediaText() const;

    PassRefPtr<MediaQuerySet> copy() const { return adoptRef(new MediaQuerySet(*this)); }

private:
    MediaQuerySet();
    MediaQuerySet(const MediaQuerySet&);

    Vector<OwnPtr<MediaQuery> > m_queries;
};

class MediaList : public RefCounted<MediaList> {
public:
    static PassRefPtr<MediaList> create(MediaQuerySet* mediaQueries, CSSStyleSheet* parentSheet)
    {
        return adoptRef(new MediaList(mediaQueries, parentSheet));
    }
    static PassRefPtr<MediaList> create(MediaQuerySet* mediaQueries, CSSRule* parentRule)
    {
        return adoptRef(new MediaList(mediaQueries, parentRule));
    }

    ~MediaList();

    unsigned length() const { return m_mediaQueries->queryVector().size(); }
    String item(unsigned index) const;
    void deleteMedium(const String& oldMedium, ExceptionCode&);
    void appendMedium(const String& newMedium, ExceptionCode&);

    String mediaText() const { return m_mediaQueries->mediaText(); }
    void setMediaText(const String&);

    // Not part of CSSOM.
    CSSRule* parentRule() const { return m_parentRule; }
    CSSStyleSheet* parentStyleSheet() const { return m_parentStyleSheet; }
    void clearParentStyleSheet() { ASSERT(m_parentStyleSheet); m_parentStyleSheet = 0; }
    void clearParentRule() { ASSERT(m_parentRule); m_parentRule = 0; }
    const MediaQuerySet* queries() const { return m_mediaQueries.get(); }

    void reattach(MediaQuerySet*);

private:
    MediaList();
    MediaList(MediaQuerySet*, CSSStyleSheet* parentSheet);
    MediaList(MediaQuerySet*, CSSRule* parentRule);

    RefPtr<MediaQuerySet> m_mediaQueries;
    CSSStyleSheet* m_parentStyleSheet;
    CSSRule* m_parentRule;
};

// Adds message to inspector console whenever dpi or dpcm values are used for "screen" media.
void reportMediaQueryWarningIfNeeded(Document*, const MediaQuerySet*);

} // namespace

#endif

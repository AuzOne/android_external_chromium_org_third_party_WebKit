/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "WebHistoryItem.h"

#include "WebSerializedScriptValue.h"
#include "bindings/v8/SerializedScriptValue.h"
#include "core/history/HistoryItem.h"
#include "core/html/forms/FormController.h"
#include "platform/network/FormData.h"
#include "public/platform/WebHTTPBody.h"
#include "public/platform/WebPoint.h"
#include "public/platform/WebString.h"
#include "public/platform/WebVector.h"
#include "weborigin/KURL.h"
#include "wtf/text/StringHash.h"

using namespace WebCore;

namespace WebKit {
namespace {

void addReferencedFilePaths(HistoryItem* item, HashSet<String>& results)
{
    const FormData* formData = item->formData();
    if (formData) {
        for (size_t i = 0; i < formData->elements().size(); ++i) {
            const FormDataElement& element = formData->elements()[i];
            if (element.m_type == FormDataElement::encodedFile)
                results.add(element.m_filename);
        }
    }

    const Vector<String>& filePaths = FormController::getReferencedFilePaths(item->documentState());
    for (size_t i = 0; i < filePaths.size(); ++i)
        results.add(filePaths[i]);

    const HistoryItemVector& children = item->children();
    for (size_t i = 0; i < children.size(); ++i)
        addReferencedFilePaths(children[i].get(), results);
}

} // namespace

void WebHistoryItem::initialize()
{
    m_private = HistoryItem::create();
}

void WebHistoryItem::reset()
{
    m_private.reset();
}

void WebHistoryItem::assign(const WebHistoryItem& other)
{
    m_private = other.m_private;
}

WebString WebHistoryItem::urlString() const
{
    return m_private->urlString();
}

void WebHistoryItem::setURLString(const WebString& url)
{
    ensureMutable();
    m_private->setURLString(KURL(ParsedURLString, url).string());
}

WebString WebHistoryItem::originalURLString() const
{
    return m_private->originalURLString();
}

void WebHistoryItem::setOriginalURLString(const WebString& originalURLString)
{
    ensureMutable();
    m_private->setOriginalURLString(originalURLString);
}

WebString WebHistoryItem::referrer() const
{
    return m_private->referrer();
}

void WebHistoryItem::setReferrer(const WebString& referrer)
{
    ensureMutable();
    m_private->setReferrer(referrer);
}

WebString WebHistoryItem::target() const
{
    return m_private->target();
}

void WebHistoryItem::setTarget(const WebString& target)
{
    ensureMutable();
    m_private->setTarget(target);
}

WebPoint WebHistoryItem::scrollOffset() const
{
    return m_private->scrollPoint();
}

void WebHistoryItem::setScrollOffset(const WebPoint& scrollOffset)
{
    ensureMutable();
    m_private->setScrollPoint(scrollOffset);
}

float WebHistoryItem::pageScaleFactor() const
{
    return m_private->pageScaleFactor();
}

void WebHistoryItem::setPageScaleFactor(float scale)
{
    ensureMutable();
    m_private->setPageScaleFactor(scale);
}

WebVector<WebString> WebHistoryItem::documentState() const
{
    return m_private->documentState();
}

void WebHistoryItem::setDocumentState(const WebVector<WebString>& state)
{
    ensureMutable();
    // FIXME: would be nice to avoid the intermediate copy
    Vector<String> ds;
    for (size_t i = 0; i < state.size(); ++i)
        ds.append(state[i]);
    m_private->setDocumentState(ds);
}

long long WebHistoryItem::itemSequenceNumber() const
{
    return m_private->itemSequenceNumber();
}

void WebHistoryItem::setItemSequenceNumber(long long itemSequenceNumber)
{
    ensureMutable();
    m_private->setItemSequenceNumber(itemSequenceNumber);
}

long long WebHistoryItem::documentSequenceNumber() const
{
    return m_private->documentSequenceNumber();
}

void WebHistoryItem::setDocumentSequenceNumber(long long documentSequenceNumber)
{
    ensureMutable();
    m_private->setDocumentSequenceNumber(documentSequenceNumber);
}

WebSerializedScriptValue WebHistoryItem::stateObject() const
{
    return WebSerializedScriptValue(m_private->stateObject());
}

void WebHistoryItem::setStateObject(const WebSerializedScriptValue& object)
{
    ensureMutable();
    m_private->setStateObject(object);
}

WebString WebHistoryItem::httpContentType() const
{
    return m_private->formContentType();
}

void WebHistoryItem::setHTTPContentType(const WebString& httpContentType)
{
    ensureMutable();
    m_private->setFormContentType(httpContentType);
}

WebHTTPBody WebHistoryItem::httpBody() const
{
    return WebHTTPBody(m_private->formData());
}

void WebHistoryItem::setHTTPBody(const WebHTTPBody& httpBody)
{
    ensureMutable();
    m_private->setFormData(httpBody);
}

WebVector<WebHistoryItem> WebHistoryItem::children() const
{
    return m_private->children();
}

void WebHistoryItem::appendToChildren(const WebHistoryItem& item)
{
    ensureMutable();
    m_private->addChildItem(item);
}

WebVector<WebString> WebHistoryItem::getReferencedFilePaths() const
{
    HashSet<String> filePaths;
    addReferencedFilePaths(m_private.get(), filePaths);

    Vector<String> results;
    copyToVector(filePaths, results);
    return results;
}

WebHistoryItem::WebHistoryItem(const PassRefPtr<HistoryItem>& item)
    : m_private(item)
{
}

WebHistoryItem& WebHistoryItem::operator=(const PassRefPtr<HistoryItem>& item)
{
    m_private = item;
    return *this;
}

WebHistoryItem::operator PassRefPtr<HistoryItem>() const
{
    return m_private.get();
}

void WebHistoryItem::ensureMutable()
{
    if (!m_private->hasOneRef())
        m_private = m_private->copy();
}

} // namespace WebKit

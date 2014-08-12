/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
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

#ifndef InspectorFrontendClientImpl_h
#define InspectorFrontendClientImpl_h

#include "core/inspector/InspectorFrontendClient.h"
#include "wtf/Noncopyable.h"

namespace blink {
class InspectorFrontendHost;
class Page;
}

namespace blink {

class WebDevToolsFrontendClient;
class WebDevToolsFrontendImpl;

class InspectorFrontendClientImpl FINAL : public blink::InspectorFrontendClient {
    WTF_MAKE_NONCOPYABLE(InspectorFrontendClientImpl);
public:
    InspectorFrontendClientImpl(blink::Page*, WebDevToolsFrontendClient*, WebDevToolsFrontendImpl*);
    virtual ~InspectorFrontendClientImpl();
    virtual void trace(Visitor*) OVERRIDE;

    // InspectorFrontendClient methods:
    virtual void windowObjectCleared() OVERRIDE;

    virtual void sendMessageToBackend(const WTF::String&) OVERRIDE;

    virtual void sendMessageToEmbedder(const WTF::String&) OVERRIDE;

    virtual bool isUnderTest() OVERRIDE;

    virtual void dispose() OVERRIDE;

private:
    RawPtrWillBeMember<blink::Page> m_frontendPage;
    WebDevToolsFrontendClient* m_client;
    RefPtrWillBeMember<blink::InspectorFrontendHost> m_frontendHost;
};

} // namespace blink

#endif

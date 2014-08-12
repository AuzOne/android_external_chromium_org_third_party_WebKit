// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef RemoteFrameClient_h
#define RemoteFrameClient_h

#include "core/frame/FrameClient.h"

namespace blink {

class WebRemoteFrameImpl;

class RemoteFrameClient : public blink::FrameClient {
public:
    explicit RemoteFrameClient(WebRemoteFrameImpl*);

    // FrameClient overrides:
    virtual blink::Frame* opener() const OVERRIDE;
    virtual void setOpener(blink::Frame*) OVERRIDE;

    virtual blink::Frame* parent() const OVERRIDE;
    virtual blink::Frame* top() const OVERRIDE;
    virtual blink::Frame* previousSibling() const OVERRIDE;
    virtual blink::Frame* nextSibling() const OVERRIDE;
    virtual blink::Frame* firstChild() const OVERRIDE;
    virtual blink::Frame* lastChild() const OVERRIDE;

    WebRemoteFrameImpl* webFrame() const { return m_webFrame; }

private:
    WebRemoteFrameImpl* m_webFrame;
};

} // namespace blink

#endif // RemoteFrameClient_h

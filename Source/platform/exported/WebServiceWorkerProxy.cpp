// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "config.h"
#include "public/platform/WebServiceWorkerProxy.h"

namespace blink { class ServiceWorker; }

namespace blink {

WebServiceWorkerProxy::WebServiceWorkerProxy(blink::ServiceWorker* serviceWorker)
    : m_private(serviceWorker)
{
}

blink::ServiceWorker* WebServiceWorkerProxy::unwrap() const
{
    return m_private;
}

} // namespace blink

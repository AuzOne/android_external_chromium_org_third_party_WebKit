// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef StorageClientImpl_h
#define StorageClientImpl_h

#include "core/page/StorageClient.h"

namespace blink {

class WebViewImpl;

class StorageClientImpl : public blink::StorageClient {
public:
    explicit StorageClientImpl(WebViewImpl*);

    virtual PassOwnPtr<blink::StorageNamespace> createSessionStorageNamespace() OVERRIDE;
    virtual bool canAccessStorage(blink::LocalFrame*, blink::StorageType) const OVERRIDE;

private:
    WebViewImpl* m_webView;
};

} // namespace blink

#endif // StorageClientImpl_h

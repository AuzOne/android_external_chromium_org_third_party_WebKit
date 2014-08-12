// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#ifndef V8TestDictionary_h
#define V8TestDictionary_h

#include "bindings/core/v8/V8Binding.h"
#include "bindings/tests/idls/TestDictionary.h"
#include "platform/heap/Handle.h"

namespace blink {

class V8TestDictionary {
public:
    static TestDictionary* toNative(v8::Isolate*, v8::Handle<v8::Value>);
};

v8::Handle<v8::Value> toV8(TestDictionary*, v8::Handle<v8::Object>, v8::Isolate*);

template<class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, TestDictionary* impl)
{
    v8SetReturnValue(callbackInfo, toV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

} // namespace blink

#endif // V8TestDictionary_h

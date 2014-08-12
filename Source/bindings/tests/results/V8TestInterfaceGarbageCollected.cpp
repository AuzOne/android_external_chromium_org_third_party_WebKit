// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8TestInterfaceGarbageCollected.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/tests/v8/V8TestInterfaceGarbageCollected.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

static void initializeScriptWrappableForInterface(TestInterfaceGarbageCollected* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8TestInterfaceGarbageCollected::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace blink

void webCoreInitializeScriptWrappableForInterface(blink::TestInterfaceGarbageCollected* object)
{
    blink::initializeScriptWrappableForInterface(object);
}

namespace blink {
const WrapperTypeInfo V8TestInterfaceGarbageCollected::wrapperTypeInfo = { gin::kEmbedderBlink, V8TestInterfaceGarbageCollected::domTemplate, V8TestInterfaceGarbageCollected::derefObject, 0, V8TestInterfaceGarbageCollected::toEventTarget, 0, V8TestInterfaceGarbageCollected::installPerContextEnabledMethods, &V8EventTarget::wrapperTypeInfo, WrapperTypeObjectPrototype, GarbageCollectedObject };

namespace TestInterfaceGarbageCollectedV8Internal {

template <typename T> void V8_USE(T) { }

static void attr1AttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TestInterfaceGarbageCollected* impl = V8TestInterfaceGarbageCollected::toNative(holder);
    v8SetReturnValueFast(info, WTF::getPtr(impl->attr1()), impl);
}

static void attr1AttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("blink", "DOMGetter");
    TestInterfaceGarbageCollectedV8Internal::attr1AttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("v8", "V8Execution");
}

static void attr1AttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    TestInterfaceGarbageCollected* impl = V8TestInterfaceGarbageCollected::toNative(holder);
    TONATIVE_VOID(TestInterfaceGarbageCollected*, cppValue, V8TestInterfaceGarbageCollected::toNativeWithTypeCheck(info.GetIsolate(), v8Value));
    impl->setAttr1(WTF::getPtr(cppValue));
}

static void attr1AttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("blink", "DOMSetter");
    TestInterfaceGarbageCollectedV8Internal::attr1AttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("v8", "V8Execution");
}

static void funcMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("func", "TestInterfaceGarbageCollected", 1, info.Length(), info.GetIsolate());
        return;
    }
    TestInterfaceGarbageCollected* impl = V8TestInterfaceGarbageCollected::toNative(info.Holder());
    TestInterfaceGarbageCollected* arg;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(arg, V8TestInterfaceGarbageCollected::toNativeWithTypeCheck(info.GetIsolate(), info[0]));
    }
    impl->func(arg);
}

static void funcMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("blink", "DOMMethod");
    TestInterfaceGarbageCollectedV8Internal::funcMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("v8", "V8Execution");
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForConstructor("TestInterfaceGarbageCollected", 1, info.Length(), info.GetIsolate());
        return;
    }
    V8StringResource<> str;
    {
        TOSTRING_VOID_INTERNAL(str, info[0]);
    }
    RawPtr<TestInterfaceGarbageCollected> impl = TestInterfaceGarbageCollected::create(str);
    v8::Handle<v8::Object> wrapper = info.Holder();
    V8DOMWrapper::associateObjectWithWrapper<V8TestInterfaceGarbageCollected>(impl.release(), &V8TestInterfaceGarbageCollected::wrapperTypeInfo, wrapper, info.GetIsolate(), WrapperConfiguration::Independent);
    v8SetReturnValue(info, wrapper);
}

} // namespace TestInterfaceGarbageCollectedV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8TestInterfaceGarbageCollectedAttributes[] = {
    {"attr1", TestInterfaceGarbageCollectedV8Internal::attr1AttributeGetterCallback, TestInterfaceGarbageCollectedV8Internal::attr1AttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::ExposedToAllScripts, V8DOMConfiguration::OnInstance},
};

static const V8DOMConfiguration::MethodConfiguration V8TestInterfaceGarbageCollectedMethods[] = {
    {"func", TestInterfaceGarbageCollectedV8Internal::funcMethodCallback, 0, 1, V8DOMConfiguration::ExposedToAllScripts},
};

void V8TestInterfaceGarbageCollected::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SCOPED_SAMPLING_STATE("blink", "DOMConstructor");
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(ExceptionMessages::constructorNotCallableAsFunction("TestInterfaceGarbageCollected"), info.GetIsolate());
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    TestInterfaceGarbageCollectedV8Internal::constructor(info);
}

static void installV8TestInterfaceGarbageCollectedTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "TestInterfaceGarbageCollected", V8EventTarget::domTemplate(isolate), V8TestInterfaceGarbageCollected::internalFieldCount,
        V8TestInterfaceGarbageCollectedAttributes, WTF_ARRAY_LENGTH(V8TestInterfaceGarbageCollectedAttributes),
        0, 0,
        V8TestInterfaceGarbageCollectedMethods, WTF_ARRAY_LENGTH(V8TestInterfaceGarbageCollectedMethods),
        isolate);
    functionTemplate->SetCallHandler(V8TestInterfaceGarbageCollected::constructorCallback);
    functionTemplate->SetLength(1);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8TestInterfaceGarbageCollected::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8TestInterfaceGarbageCollectedTemplate);
}

bool V8TestInterfaceGarbageCollected::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8TestInterfaceGarbageCollected::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TestInterfaceGarbageCollected* V8TestInterfaceGarbageCollected::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

EventTarget* V8TestInterfaceGarbageCollected::toEventTarget(v8::Handle<v8::Object> object)
{
    return toNative(object);
}

v8::Handle<v8::Object> wrap(TestInterfaceGarbageCollected* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8TestInterfaceGarbageCollected>(impl, isolate));
    return V8TestInterfaceGarbageCollected::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8TestInterfaceGarbageCollected::createWrapper(RawPtr<TestInterfaceGarbageCollected> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8TestInterfaceGarbageCollected>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8TestInterfaceGarbageCollected>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8TestInterfaceGarbageCollected::derefObject(void* object)
{
}

template<>
v8::Handle<v8::Value> toV8NoInline(TestInterfaceGarbageCollected* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace blink

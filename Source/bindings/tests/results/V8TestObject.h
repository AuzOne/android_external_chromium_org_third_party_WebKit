/*
    This file is part of the Blink open source project.
    This file has been auto-generated by CodeGeneratorV8.pm. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef V8TestObject_h
#define V8TestObject_h

#include "bindings/bindings/tests/idls/TestObj.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8DOMWrapper.h"
#include "bindings/v8/WrapperTypeInfo.h"

namespace WebCore {

class V8TestObject {
public:
    static bool HasInstance(v8::Handle<v8::Value>, v8::Isolate*, WrapperWorldType);
    static bool HasInstanceInAnyWorld(v8::Handle<v8::Value>, v8::Isolate*);
    static v8::Handle<v8::FunctionTemplate> GetTemplate(v8::Isolate*, WrapperWorldType);
    static TestObj* toNative(v8::Handle<v8::Object> object)
    {
        return fromInternalPointer(object->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex));
    }
    static void derefObject(void*);
    static WrapperTypeInfo info;
    static void customMethodMethodCustom(const v8::FunctionCallbackInfo<v8::Value>&);
    static void customMethodWithArgsMethodCustom(const v8::FunctionCallbackInfo<v8::Value>&);
    static void classMethod2MethodCustom(const v8::FunctionCallbackInfo<v8::Value>&);
    static void constructorCallback(const v8::FunctionCallbackInfo<v8::Value>&);
    static void customAttrAttrGetterCustom(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>&);
    static void customAttrAttrSetterCustom(v8::Local<v8::String> name, v8::Local<v8::Value>, const v8::PropertyCallbackInfo<void>&);
    static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
    static inline void* toInternalPointer(TestObj* impl)
    {
        return impl;
    }

    static inline TestObj* fromInternalPointer(void* object)
    {
        return static_cast<TestObj*>(object);
    }
    static void installPerContextProperties(v8::Handle<v8::Object>, TestObj*, v8::Isolate*);
    static void installPerContextPrototypeProperties(v8::Handle<v8::Object>, v8::Isolate*);
private:
    friend v8::Handle<v8::Object> wrap(TestObj*, v8::Handle<v8::Object> creationContext, v8::Isolate*);
    static v8::Handle<v8::Object> createWrapper(PassRefPtr<TestObj>, v8::Handle<v8::Object> creationContext, v8::Isolate*);
};

template<>
class WrapperTypeTraits<TestObj > {
public:
    static WrapperTypeInfo* info() { return &V8TestObject::info; }
};


inline v8::Handle<v8::Object> wrap(TestObj* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(DOMDataStore::getWrapper<V8TestObject>(impl, isolate).IsEmpty());
    return V8TestObject::createWrapper(impl, creationContext, isolate);
}

inline v8::Handle<v8::Value> toV8(TestObj* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (UNLIKELY(!impl))
        return v8NullWithCheck(isolate);
    v8::Handle<v8::Value> wrapper = DOMDataStore::getWrapper<V8TestObject>(impl, isolate);
    if (!wrapper.IsEmpty())
        return wrapper;
    return wrap(impl, creationContext, isolate);
}

inline v8::Handle<v8::Value> toV8ForMainWorld(TestObj* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(worldType(isolate) == MainWorld);
    if (UNLIKELY(!impl))
        return v8NullWithCheck(isolate);
    v8::Handle<v8::Value> wrapper = DOMDataStore::getWrapperForMainWorld<V8TestObject>(impl);
    if (!wrapper.IsEmpty())
        return wrapper;
    return wrap(impl, creationContext, isolate);
}

template<class CallbackInfo, class Wrappable>
inline v8::Handle<v8::Value> toV8Fast(TestObj* impl, const CallbackInfo& callbackInfo, Wrappable* wrappable)
{
    if (UNLIKELY(!impl))
        return v8::Null(callbackInfo.GetIsolate());
    v8::Handle<v8::Object> wrapper = DOMDataStore::getWrapperFast<V8TestObject>(impl, callbackInfo, wrappable);
    if (!wrapper.IsEmpty())
        return wrapper;
    return wrap(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
}

inline v8::Handle<v8::Value> toV8ForMainWorld(PassRefPtr< TestObj > impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8ForMainWorld(impl.get(), creationContext, isolate);
}


template<class CallbackInfo, class Wrappable>
inline v8::Handle<v8::Value> toV8Fast(PassRefPtr< TestObj > impl, const CallbackInfo& callbackInfo, Wrappable* wrappable)
{
    return toV8Fast(impl.get(), callbackInfo, wrappable);
}

inline v8::Handle<v8::Value> toV8(PassRefPtr< TestObj > impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl.get(), creationContext, isolate);
}

}

#endif // V8TestObject_h

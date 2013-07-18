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

#include "config.h"
#include "V8TestNamedConstructor.h"

#include "RuntimeEnabledFeatures.h"
#include "V8Document.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/ScriptController.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8DOMWrapper.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "core/page/Frame.h"
#include "core/platform/chromium/TraceEvent.h"
#include "wtf/UnusedParam.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(TestNamedConstructor* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::setTypeInfoInObject(object, &V8TestNamedConstructor::info);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

// In ScriptWrappable::init, the use of a local function declaration has an issue on Windows:
// the local declaration does not pick up the surrounding namespace. Therefore, we provide this function
// in the global namespace.
// (More info on the MSVC bug here: http://connect.microsoft.com/VisualStudio/feedback/details/664619/the-namespace-of-local-function-declarations-in-c)
void webCoreInitializeScriptWrappableForInterface(WebCore::TestNamedConstructor* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
WrapperTypeInfo V8TestNamedConstructor::info = { V8TestNamedConstructor::GetTemplate, V8TestNamedConstructor::derefObject, V8TestNamedConstructor::toActiveDOMObject, 0, 0, V8TestNamedConstructor::installPerContextPrototypeProperties, 0, WrapperTypeObjectPrototype };

namespace TestNamedConstructorV8Internal {

template <typename T> void V8_USE(T) { }

} // namespace TestNamedConstructorV8Internal

WrapperTypeInfo V8TestNamedConstructorConstructor::info = { V8TestNamedConstructorConstructor::GetTemplate, V8TestNamedConstructor::derefObject, V8TestNamedConstructor::toActiveDOMObject, 0, 0, V8TestNamedConstructor::installPerContextPrototypeProperties, 0, WrapperTypeObjectPrototype };

static void V8TestNamedConstructorConstructorCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (!args.IsConstructCall()) {
        throwTypeError("DOM object constructor cannot be called as a function.", args.GetIsolate());
        return;
    }

    if (ConstructorMode::current() == ConstructorMode::WrapExistingObject) {
        args.GetReturnValue().Set(args.Holder());
        return;
    }

    Document* document = currentDocument();

    // Make sure the document is added to the DOM Node map. Otherwise, the TestNamedConstructor instance
    // may end up being the only node in the map and get garbage-collected prematurely.
    toV8(document, args.Holder(), args.GetIsolate());

    if (args.Length() < 1) {
        throwNotEnoughArgumentsError(args.GetIsolate());
        return;
    }
    ExceptionState es(args.GetIsolate());
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, str1, args[0]);
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, str2, args[1]);
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, str3, argumentOrNull(args, 2));

    RefPtr<TestNamedConstructor> impl = TestNamedConstructor::createForJSConstructor(document, str1, str2, str3, es);
    v8::Handle<v8::Object> wrapper = args.Holder();
    if (es.throwIfNeeded())
        return;

    V8DOMWrapper::associateObjectWithWrapper<V8TestNamedConstructor>(impl.release(), &V8TestNamedConstructorConstructor::info, wrapper, args.GetIsolate(), WrapperConfiguration::Dependent);
    args.GetReturnValue().Set(wrapper);
}

v8::Handle<v8::FunctionTemplate> V8TestNamedConstructorConstructor::GetTemplate(v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    // This is only for getting a unique pointer which we can pass to privateTemplate.
    static const char* privateTemplateUniqueKey = "V8TestNamedConstructorConstructor::GetTemplatePrivateTemplate";
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    v8::Handle<v8::FunctionTemplate> result = data->privateTemplateIfExists(currentWorldType, &privateTemplateUniqueKey);
    if (!result.IsEmpty())
        return result;

    TRACE_EVENT_SCOPED_SAMPLING_STATE("Blink", "BuildDOMTemplate");
    v8::HandleScope scope(isolate);
    result = v8::FunctionTemplate::New(V8TestNamedConstructorConstructorCallback);

    v8::Local<v8::ObjectTemplate> instance = result->InstanceTemplate();
    instance->SetInternalFieldCount(V8TestNamedConstructor::internalFieldCount);
    result->SetClassName(v8::String::NewSymbol("TestNamedConstructor"));
    result->Inherit(V8TestNamedConstructor::GetTemplate(isolate, currentWorldType));
    data->setPrivateTemplate(currentWorldType, &privateTemplateUniqueKey, result);

    return scope.Close(result);
}

static v8::Handle<v8::FunctionTemplate> ConfigureV8TestNamedConstructorTemplate(v8::Handle<v8::FunctionTemplate> desc, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    desc->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::configureTemplate(desc, "TestNamedConstructor", v8::Local<v8::FunctionTemplate>(), V8TestNamedConstructor::internalFieldCount,
        0, 0,
        0, 0, isolate, currentWorldType);
    UNUSED_PARAM(defaultSignature); // In some cases, it will not be used.

    // Custom toString template
    desc->Set(v8::String::NewSymbol("toString"), V8PerIsolateData::current()->toStringTemplate());
    return desc;
}

v8::Handle<v8::FunctionTemplate> V8TestNamedConstructor::GetTemplate(v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    V8PerIsolateData::TemplateMap::iterator result = data->templateMap(currentWorldType).find(&info);
    if (result != data->templateMap(currentWorldType).end())
        return result->value.newLocal(isolate);

    TRACE_EVENT_SCOPED_SAMPLING_STATE("Blink", "BuildDOMTemplate");
    v8::HandleScope handleScope(isolate);
    v8::Handle<v8::FunctionTemplate> templ =
        ConfigureV8TestNamedConstructorTemplate(data->rawTemplate(&info, currentWorldType), isolate, currentWorldType);
    data->templateMap(currentWorldType).add(&info, UnsafePersistent<v8::FunctionTemplate>(isolate, templ));
    return handleScope.Close(templ);
}

bool V8TestNamedConstructor::HasInstance(v8::Handle<v8::Value> value, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&info, value, currentWorldType);
}

bool V8TestNamedConstructor::HasInstanceInAnyWorld(v8::Handle<v8::Value> value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&info, value, MainWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&info, value, IsolatedWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&info, value, WorkerWorld);
}

ActiveDOMObject* V8TestNamedConstructor::toActiveDOMObject(v8::Handle<v8::Object> object)
{
    return toNative(object);
}


v8::Handle<v8::Object> V8TestNamedConstructor::createWrapper(PassRefPtr<TestNamedConstructor> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl.get());
    ASSERT(DOMDataStore::getWrapper<V8TestNamedConstructor>(impl.get(), isolate).IsEmpty());

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &info, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;
    installPerContextProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8TestNamedConstructor>(impl, &info, wrapper, isolate, WrapperConfiguration::Dependent);
    return wrapper;
}
void V8TestNamedConstructor::derefObject(void* object)
{
    fromInternalPointer(object)->deref();
}

} // namespace WebCore

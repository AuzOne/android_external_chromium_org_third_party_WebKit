/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MediaKeySession_h
#define MediaKeySession_h

#include "bindings/core/v8/ScriptPromiseProperty.h"
#include "core/dom/ActiveDOMObject.h"
#include "core/dom/DOMException.h"
#include "modules/EventTargetModules.h"
#include "platform/Timer.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebContentDecryptionModuleSession.h"
#include "wtf/Forward.h"

namespace blink {
class WebContentDecryptionModule;
class WebString;
}

namespace blink {

class ScriptPromise;
class ScriptState;
class GenericEventQueue;
class MediaKeyError;
class MediaKeys;

// References are held by JS only. However, even if all JS references are
// dropped, it won't be garbage collected until close event received or
// MediaKeys goes away (as determined by the validity of a WeakPtr). This allows
// the CDM to continue to fire events for this session, as long as the session
// is open.
//
// WeakPtr<MediaKeys> is used instead of having MediaKeys and MediaKeySession
// keep references to each other, and then having to inform the other object
// when it gets destroyed.
//
// Because this object controls the lifetime of the WebContentDecryptionModuleSession,
// it may outlive any JavaScript references as long as the MediaKeys object is alive.
// The WebContentDecryptionModuleSession has the same lifetime as this object.
class MediaKeySession FINAL
    : public RefCountedGarbageCollectedWillBeGarbageCollectedFinalized<MediaKeySession>, public ActiveDOMObject, public EventTargetWithInlineData
    , private blink::WebContentDecryptionModuleSession::Client {
    DEFINE_EVENT_TARGET_REFCOUNTING_WILL_BE_REMOVED(RefCountedGarbageCollected<MediaKeySession>);
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(MediaKeySession);
public:
    static ScriptPromise create(ScriptState*, MediaKeys*, const String& initDataType, PassRefPtr<ArrayBuffer> initData, const String& sessionType);
    virtual ~MediaKeySession();

    const String& keySystem() const { return m_keySystem; }
    String sessionId() const;
    ScriptPromise closed(ScriptState*);

    void setError(MediaKeyError*);
    MediaKeyError* error() { return m_error.get(); }

    ScriptPromise update(ScriptState*, ArrayBuffer* response);
    ScriptPromise update(ScriptState*, ArrayBufferView* response);
    ScriptPromise release(ScriptState*);

    void enqueueEvent(PassRefPtrWillBeRawPtr<Event>);

    // EventTarget
    virtual const AtomicString& interfaceName() const OVERRIDE;
    virtual ExecutionContext* executionContext() const OVERRIDE;

    // ActiveDOMObject
    virtual bool hasPendingActivity() const OVERRIDE;
    virtual void stop() OVERRIDE;

    virtual void trace(Visitor*) OVERRIDE;

private:
    class PendingAction;
    friend class MediaKeySessionInitializer;

    MediaKeySession(ExecutionContext*, MediaKeys*, PassOwnPtr<blink::WebContentDecryptionModuleSession>);
    void actionTimerFired(Timer<MediaKeySession>*);

    // blink::WebContentDecryptionModuleSession::Client
    virtual void message(const unsigned char* message, size_t messageLength, const blink::WebURL& destinationURL) OVERRIDE;
    virtual void ready() OVERRIDE;
    virtual void close() OVERRIDE;
    virtual void error(MediaKeyErrorCode, unsigned long systemCode) OVERRIDE;
    virtual void error(blink::WebContentDecryptionModuleException, unsigned long systemCode, const blink::WebString& errorMessage) OVERRIDE;

    ScriptPromise updateInternal(ScriptState*, PassRefPtr<ArrayBuffer> response);

    String m_keySystem;
    RefPtrWillBeMember<MediaKeyError> m_error;
    OwnPtrWillBeMember<GenericEventQueue> m_asyncEventQueue;
    OwnPtr<blink::WebContentDecryptionModuleSession> m_session;

    // Used to determine if MediaKeys is still active.
    WeakMember<MediaKeys> m_keys;

    // Is the CDM finished with this session?
    bool m_isClosed;

    // Keep track of the closed promise.
    typedef ScriptPromiseProperty<Member<MediaKeySession>, V8UndefinedType, RefPtrWillBeMember<DOMException> > ClosedPromise;
    Member<ClosedPromise> m_closedPromise;

    HeapDeque<Member<PendingAction> > m_pendingActions;
    Timer<MediaKeySession> m_actionTimer;
};

}

#endif // MediaKeySession_h

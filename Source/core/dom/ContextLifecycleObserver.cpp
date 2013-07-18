/*
 * Copyright (C) 2008 Apple Inc. All Rights Reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "config.h"
#include "core/dom/ContextLifecycleObserver.h"

#include "core/dom/ScriptExecutionContext.h"

namespace WebCore {

ContextLifecycleObserver::ContextLifecycleObserver(ScriptExecutionContext* scriptExecutionContext, Type type)
    : LifecycleObserver(scriptExecutionContext)
    , m_scriptExecutionContext(0)
{
    observeContext(scriptExecutionContext, type);
}

ContextLifecycleObserver::~ContextLifecycleObserver()
{
    if (m_scriptExecutionContext)
        observeContext(0, GenericType);
}

void ContextLifecycleObserver::observeContext(ScriptExecutionContext* scriptExecutionContext, Type as)
{
    if (m_scriptExecutionContext) {
        ASSERT(m_scriptExecutionContext->isContextThread());
        m_scriptExecutionContext->wasUnobservedBy(this, as);
    }

    m_scriptExecutionContext = scriptExecutionContext;
    m_lifecycleContext = scriptExecutionContext;

    if (m_scriptExecutionContext) {
        ASSERT(m_scriptExecutionContext->isContextThread());
        m_scriptExecutionContext->wasObservedBy(this, as);
    }
}

void ContextLifecycleObserver::contextDestroyed()
{
    m_scriptExecutionContext = 0;

    LifecycleObserver::contextDestroyed();
}

} // namespace WebCore

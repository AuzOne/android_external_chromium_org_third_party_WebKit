/*
 * Copyright (C) 2010 Google, Inc. All Rights Reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ParserContentPolicy_h
#define ParserContentPolicy_h

namespace blink {

enum ParserContentPolicy {
    DisallowScriptingAndPluginContent,
    DisallowScriptingContent,
    AllowScriptingContent,
    AllowScriptingContentAndDoNotMarkAlreadyStarted,
};

static inline bool scriptingContentIsAllowed(ParserContentPolicy parserContentPolicy)
{
    return parserContentPolicy == AllowScriptingContent || parserContentPolicy == AllowScriptingContentAndDoNotMarkAlreadyStarted;
}

static inline ParserContentPolicy disallowScriptingContent(ParserContentPolicy parserContentPolicy)
{
    if (!scriptingContentIsAllowed(parserContentPolicy))
        return parserContentPolicy;
    return DisallowScriptingContent;
}

static inline bool pluginContentIsAllowed(ParserContentPolicy parserContentPolicy)
{
    return parserContentPolicy != DisallowScriptingAndPluginContent;
}

static inline ParserContentPolicy allowPluginContent(ParserContentPolicy parserContentPolicy)
{
    if (pluginContentIsAllowed(parserContentPolicy))
        return parserContentPolicy;
    return DisallowScriptingContent;
}

} // namespace blink

#endif // ParserContentPolicy_h

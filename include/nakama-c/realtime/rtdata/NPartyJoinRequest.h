/*
 * Copyright 2021 The Nakama Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "nakama-c/realtime/rtdata/NUserPresence.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Incoming notification for one or more new presences attempting to join the party.
typedef struct NAKAMA_API NPartyJoinRequest
{
    /// The ID of the party to get a list of join requests for.
    const char* partyId;

    /// Presences attempting to join, or who have joined.
    sNUserPresence* presences;

    /// Number of presences attempting to join or who have joined.
    uint16_t presencesCount;

} sNPartyJoinRequest;

#ifdef __cplusplus
}
#endif
/*
 * Copyright 2019 The Nakama Authors
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

#include "BaseClient.h"
#include "NRtClient.h"
#include "nakama-cpp/realtime/NWebsocketsFactory.h"
#include "nakama-cpp/log/NLogger.h"

#undef NMODULE_NAME
#define NMODULE_NAME "Nakama::BaseClient"

using namespace std;

namespace Nakama {

NRtClientPtr BaseClient::createRtClient(int32_t port, NRtTransportPtr transport)
{
    RtClientParameters parameters;
    
    parameters.host = _host;
    parameters.port = port;
    parameters.ssl  = _ssl;
    parameters.platformParams = _platformParams;

    return createRtClient(parameters, transport);
}

NRtClientPtr BaseClient::createRtClient(const RtClientParameters& parameters, NRtTransportPtr transport)
{
    if (!transport)
    {
        transport = createDefaultWebsocket(parameters.platformParams);

        if (!transport)
        {
            NLOG_ERROR("No default websockets transport available. Please set transport.");
            return nullptr;
        }
    }

    NRtClientPtr client(new NRtClient(transport, parameters.host, parameters.port, parameters.ssl));
    return client;
}

}

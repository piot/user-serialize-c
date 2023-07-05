/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <guise-serialize/query_client_out.h>
#include <guise-serialize/serialize.h>

#define COMMAND_DEBUG "ClientOut"

int guiseSerializeClientOutRequestInfo(struct FldOutStream* stream, GuiseSerializeUserSessionId ownSessionId,
                                       GuiseSerializeUserSessionId sessionIdToLookup,
                                       const GuiseSerializeAddress* address)
{
    guiseSerializeWriteCommand(stream, guiseSerializeCmdConfirmInfoRequest, COMMAND_DEBUG);
    guiseSerializeWriteUserSessionId(stream, ownSessionId);
    guiseSerializeWriteUserSessionId(stream, sessionIdToLookup);
    return guiseSerializeWriteNetworkAddress(stream, address);
}

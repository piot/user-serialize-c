/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <guise-serialize/commands.h>
#include <guise-serialize/query_server_out.h>

#define DEBUG_PREFIX "ServerOut"

/*
    GuiseSerializeUserId userId;
    GuiseSerializeUserSessionId userSessionId;
    GuiseSerializeUserName userName;
    GuiseSerializeAddress address;

*/

int guiseSerializeServerOutInfoResponse(struct FldOutStream* outStream, const GuiseSerializeConfirmResponse* forClient)
{
    guiseSerializeWriteCommand(outStream, guiseSerializeCmdConfirmInfoResponse, DEBUG_PREFIX);
    guiseSerializeWriteUserId(outStream, forClient->userId);
    guiseSerializeWriteUserSessionId(outStream, forClient->userSessionId);
    guiseSerializeWriteUserName(outStream, &forClient->userName);
    return guiseSerializeWriteNetworkAddress(outStream, &forClient->address);
}

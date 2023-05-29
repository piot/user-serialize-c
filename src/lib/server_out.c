/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <user-serialize/commands.h>
#include <user-serialize/server_out.h>

#define DEBUG_PREFIX "ServerOut"

int userSerializeServerOutChallenge(FldOutStream* outStream, UserSerializeClientNonce forClient,
                                    UserSerializeServerChallenge challenge)
{
    userSerializeWriteCommand(outStream, userSerializeCmdChallengeResponse, DEBUG_PREFIX);
    userSerializeWriteClientNonce(outStream, forClient);
    userSerializeWriteServerChallenge(outStream, challenge);

    return 0;
}

int userSerializeServerOutLogin(FldOutStream* outStream, UserSerializeClientNonce forClient,
                                UserSerializeUserSessionId userSessionId)
{
    userSerializeWriteCommand(outStream, userSerializeCmdLoginResponse, DEBUG_PREFIX);
    userSerializeWriteClientNonce(outStream, forClient);
    userSerializeWriteUserSessionId(outStream, userSessionId);

    return 0;
}

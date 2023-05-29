/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <user-serialize/client_in.h>
#include <user-serialize/serialize.h>

int userSerializeClientInChallenge(FldInStream* inStream, UserSerializeClientNonce* clientNonce,
                                   UserSerializeServerChallenge* serverChallenge)
{
    userSerializeReadClientNonce(inStream, clientNonce);

    return userSerializeReadServerChallenge(inStream, serverChallenge);
}

int userSerializeClientInLogin(struct FldInStream* inStream, UserSerializeClientNonce* clientNonce,
                               UserSerializeUserSessionId* userSessionId)
{
    userSerializeReadClientNonce(inStream, clientNonce);

    return userSerializeReadUserSessionId(inStream, userSessionId);
}

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <user-serialize/serialize.h>
#include <user-serialize/server_in.h>

int userSerializeServerInLogin(FldInStream* inStream, UserSerializeClientNonce* clientNonce,
                               UserSerializeServerChallenge* serverChallenge, char* target, size_t maxTarget)
{
    userSerializeReadClientNonce(inStream, clientNonce);
    userSerializeReadServerChallenge(inStream, serverChallenge);
    userSerializeReadString(inStream, target, maxTarget);

    return 0;
}

int userSerializeServerInChallenge(FldInStream* inStream, UserSerializeClientNonce* clientNonce)
{
    return userSerializeReadClientNonce(inStream, clientNonce);
}

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <guise-serialize/serialize.h>
#include <guise-serialize/server_in.h>

int guiseSerializeServerInLogin(FldInStream* inStream, GuiseSerializeClientNonce* clientNonce,
                               GuiseSerializeServerChallenge* serverChallenge, char* target, size_t maxTarget)
{
    guiseSerializeReadClientNonce(inStream, clientNonce);
    guiseSerializeReadServerChallenge(inStream, serverChallenge);
    guiseSerializeReadString(inStream, target, maxTarget);

    return 0;
}

int guiseSerializeServerInChallenge(FldInStream* inStream, GuiseSerializeClientNonce* clientNonce)
{
    return guiseSerializeReadClientNonce(inStream, clientNonce);
}

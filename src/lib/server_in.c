/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <guise-serialize/serialize.h>
#include <guise-serialize/server_in.h>

int guiseSerializeServerInLogin(FldInStream* inStream, GuiseSerializeClientNonce* clientNonce,
                                GuiseSerializeUserId* userId,
                                GuiseSerializePasswordHashWithChallenge* targetPassword)
{
    guiseSerializeReadClientNonce(inStream, clientNonce);
    guiseSerializeReadUserId(inStream, userId);
    guiseSerializeReadPasswordHashWithChallenge(inStream, targetPassword);

    return 0;
}

int guiseSerializeServerInChallenge(FldInStream* inStream, GuiseSerializeUserId* userId,
                                    GuiseSerializeClientNonce* clientNonce)
{
    guiseSerializeReadClientNonce(inStream, clientNonce);
    return guiseSerializeReadUserId(inStream, userId);
}

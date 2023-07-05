/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <guise-serialize/client_in.h>
#include <guise-serialize/serialize.h>

int guiseSerializeClientInChallenge(FldInStream* inStream, GuiseSerializeClientNonce* clientNonce,
                                    GuiseSerializeServerChallenge* serverChallenge)
{
    guiseSerializeReadClientNonce(inStream, clientNonce);

    return guiseSerializeReadServerChallenge(inStream, serverChallenge);
}

int guiseSerializeClientInLogin(struct FldInStream* inStream, GuiseSerializeClientNonce* clientNonce,
                                GuiseSerializeUserName* userName, GuiseSerializeUserSessionId* userSessionId,
                                GuiseSerializeAddress* address)
{
    guiseSerializeReadClientNonce(inStream, clientNonce);
    guiseSerializeReadUserName(inStream, userName);
    guiseSerializeReadUserSessionId(inStream, userSessionId);
    return guiseSerializeReadNetworkAddress(inStream, address);
}

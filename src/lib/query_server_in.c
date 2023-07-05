/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <guise-serialize/query_server_in.h>
#include <guise-serialize/serialize.h>

int guiseSerializeServerInInfoRequest(struct FldInStream* inStream, GuiseSerializeUserSessionId* sessionIdToLookup,
                                      GuiseSerializeAddress* address)
{
    guiseSerializeReadUserSessionId(inStream, sessionIdToLookup);
    return guiseSerializeReadNetworkAddress(inStream, address);
}

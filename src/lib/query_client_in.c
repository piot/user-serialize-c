/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <guise-serialize/query_client_in.h>
#include <guise-serialize/serialize.h>

int guiseSerializeReadGetInfoResponse(GuiseSerializeConfirmResponse* response, struct FldInStream* inStream)
{
    guiseSerializeReadUserId(inStream, &response->userId);
    guiseSerializeReadUserSessionId(inStream, &response->userSessionId);
    guiseSerializeReadUserName(inStream, &response->userName);
    return guiseSerializeReadNetworkAddress(inStream, &response->address);
}

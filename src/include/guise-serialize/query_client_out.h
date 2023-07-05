/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_QUERY_CLIENT_OUT
#define GUISE_QUERY_CLIENT_OUT

#include <guise-serialize/commands.h>
#include <guise-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int guiseSerializeClientOutRequestInfo(struct FldOutStream* stream, GuiseSerializeUserSessionId ownSessionId,
                                       GuiseSerializeUserSessionId sessionIdToLookup,
                                       const GuiseSerializeAddress* address);

#endif

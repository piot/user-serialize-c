/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_CLIENT_IN_H
#define GUISE_SERIALIZE_CLIENT_IN_H

#include <stdint.h>
#include <stdlib.h>
#include <guise-serialize/commands.h>
#include <guise-serialize/types.h>

struct FldInStream;

int guiseSerializeClientInChallenge(struct FldInStream* inStream, GuiseSerializeClientNonce* clientNonce,
                                   GuiseSerializeServerChallenge* serverChallenge);
int guiseSerializeClientInLogin(struct FldInStream* inStream, GuiseSerializeClientNonce* clientNonce,
                               GuiseSerializeUserSessionId* userSessionId);

#endif

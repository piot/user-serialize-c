/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_H
#define GUISE_SERIALIZE_H

#include <guise-serialize/commands.h>
#include <guise-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int guiseSerializeClientOutChallenge(struct FldOutStream* stream, GuiseSerializeClientNonce clientNonce);
int guiseSerializeClientOutLogin(struct FldOutStream* stream, GuiseSerializeClientNonce clientNonce,
                                 GuiseSerializeServerChallenge challenge, GuiseSerializeUserId userId,
                                 GuiseSerializePassword password);

#endif

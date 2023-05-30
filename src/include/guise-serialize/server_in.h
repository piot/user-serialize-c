/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_SERVER_IN_H
#define GUISE_SERIALIZE_SERVER_IN_H

#include <guise-serialize/commands.h>
#include <guise-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldInStream;

int guiseSerializeServerInLogin(struct FldInStream* inStream, GuiseSerializeClientNonce* clientNonce,
                                GuiseSerializeUserId* userId,
                                GuiseSerializePasswordHashWithChallenge* password);

int guiseSerializeServerInChallenge(struct FldInStream* inStream, GuiseSerializeUserId* userId,
                                    GuiseSerializeClientNonce* clientNonce);

#endif

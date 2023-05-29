/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef USER_SERIALIZE_H
#define USER_SERIALIZE_H

#include <stdint.h>
#include <stdlib.h>
#include <user-serialize/commands.h>
#include <user-serialize/types.h>

struct FldOutStream;

int userSerializeClientOutChallenge(struct FldOutStream* stream, UserSerializeClientNonce clientNonce);
int userSerializeClientOutLogin(struct FldOutStream* stream, UserSerializeClientNonce clientNonce,
                                UserSerializeServerChallenge challenge, const char* name);

#endif

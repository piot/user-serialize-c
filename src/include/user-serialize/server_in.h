/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef USER_SERIALIZE_SERVER_IN_H
#define USER_SERIALIZE_SERVER_IN_H

#include <stdint.h>
#include <stdlib.h>
#include <user-serialize/commands.h>
#include <user-serialize/types.h>

struct FldInStream;

int userSerializeServerInLogin(struct FldInStream* inStream, UserSerializeClientNonce* clientNonce,
                               UserSerializeServerChallenge* serverChallenge, char* target, size_t maxTarget);

int userSerializeServerInChallenge(struct FldInStream* inStream, UserSerializeClientNonce* clientNonce);

#endif

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef USER_SERIALIZE_SERVER_OUT_H
#define USER_SERIALIZE_SERVER_OUT_H

#include <stdint.h>
#include <stdlib.h>
#include <user-serialize/serialize.h>

struct FldOutStream;

int userSerializeServerOutChallenge(struct FldOutStream* outStream, UserSerializeClientNonce forClient,
                                    UserSerializeServerChallenge challenge);
int userSerializeServerOutLogin(struct FldOutStream* outStream, UserSerializeClientNonce forClient,
                                UserSerializeUserSessionId userSession);

#endif

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_SERVER_OUT_H
#define GUISE_SERIALIZE_SERVER_OUT_H

#include <guise-serialize/serialize.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int guiseSerializeServerOutChallenge(struct FldOutStream* outStream, GuiseSerializeClientNonce forClient,
                                     GuiseSerializeServerChallenge challenge);
int guiseSerializeServerOutLogin(struct FldOutStream* outStream, GuiseSerializeClientNonce forClient,
                                 const GuiseSerializeUserName* userName, GuiseSerializeUserSessionId userSession);

#endif

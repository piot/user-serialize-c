/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_SERVER_QUERY_OUT_H
#define GUISE_SERIALIZE_SERVER_QUERY_OUT_H

#include <guise-serialize/serialize.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int guiseSerializeServerOutInfoResponse(struct FldOutStream* outStream, const GuiseSerializeConfirmResponse* forClient);

#endif

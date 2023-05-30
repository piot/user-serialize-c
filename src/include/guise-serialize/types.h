/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_TYPES_H
#define GUISE_SERIALIZE_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef uint64_t GuiseSerializeUserSessionId;
typedef uint64_t GuiseSerializeUserId;

typedef uint64_t GuiseSerializeClientNonce;
typedef uint64_t GuiseSerializeServerChallenge;

typedef struct GuiseSerializePassword {
    uint8_t payload[32];
} GuiseSerializePassword;

#endif

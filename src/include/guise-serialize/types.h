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

typedef uint64_t GuiseSerializePasswordHashWithChallenge;

typedef struct GuiseSerializeUserName {
    char utf8[33];
} GuiseSerializeUserName;

#endif

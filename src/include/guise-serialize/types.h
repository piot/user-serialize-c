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

typedef enum GuiseSerializeAddressType {
    GuiseSerializeAddressTypeV4,
    GuiseSerializeAddressTypeV6,
} GuiseSerializeAddressType;

typedef struct GuiseSerializeAddress {
    union  {
        uint8_t ipv4[4];
        uint8_t ipv6[16];
    } address;

    uint16_t port;
    GuiseSerializeAddressType type;
} GuiseSerializeAddress;

typedef struct GuiseSerializeConfirmResponse {
    GuiseSerializeUserId userId;
    GuiseSerializeUserSessionId userSessionId;
    GuiseSerializeUserName userName;
    GuiseSerializeAddress address;
} GuiseSerializeConfirmResponse;

typedef enum GuiseSerializeRole {
    GuiseSerializeRoleNone = 0,
    GuiseSerializeRoleUser = 1,
    GuiseSerializeRoleQuery = 2,
    GuiseSerializeRoleAdmin = 4,
} GuiseSerializeRole;

#endif

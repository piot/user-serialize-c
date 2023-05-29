/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef USER_SERIALIZE_COMMANDS_H
#define USER_SERIALIZE_COMMANDS_H

#include <stdint.h>

// TODO: change to extern.

// Requests
#define userSerializeCmdNop (0x00)

#define userSerializeCmdLogin (0x02)
#define userSerializeCmdChallenge (0x0A)

// Responses
#define userSerializeCmdLoginResponse (0x22)
#define userSerializeCmdChallengeResponse (0x2A)

#endif

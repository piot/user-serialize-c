/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_COMMANDS_H
#define GUISE_SERIALIZE_COMMANDS_H

#include <stdint.h>

// TODO: change to extern.

// Requests

#define guiseSerializeCmdLogin (0x02)
#define guiseSerializeCmdChallenge (0x0A)
#define guiseSerializeCmdConfirmInfoRequest (0x0B)

// Responses
#define guiseSerializeCmdLoginResponse (0x22)
#define guiseSerializeCmdChallengeResponse (0x2A)

#define guiseSerializeCmdConfirmInfoResponse (0x2B)


#endif

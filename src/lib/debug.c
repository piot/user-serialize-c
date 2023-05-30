/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <stdio.h>
#include <guise-serialize/commands.h>
#include <guise-serialize/debug.h>

const char* guiseSerializeCmdToString(uint8_t t)
{
    switch (t) {
        case guiseSerializeCmdChallenge:
            return "Challenge";
        case guiseSerializeCmdChallengeResponse:
            return "ChallengeResponse";
        case guiseSerializeCmdLogin:
            return "Login";
        case guiseSerializeCmdLoginResponse:
            return "LoginResponse";
        default: {
            static char buf[128];
            tc_snprintf(buf, 128, "no idea %02X", t);
            return buf;
        }
    }
}

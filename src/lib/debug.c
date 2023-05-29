/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <stdio.h>
#include <user-serialize/commands.h>
#include <user-serialize/debug.h>

const char* userSerializeCmdToString(uint8_t t)
{
    switch (t) {
        case userSerializeCmdChallenge:
            return "Challenge";
        case userSerializeCmdChallengeResponse:
            return "ChallengeResponse";
        case userSerializeCmdLogin:
            return "Login";
        case userSerializeCmdLoginResponse:
            return "LoginResponse";
        default: {
            static char buf[128];
            tc_snprintf(buf, 128, "no idea %02X", t);
            return buf;
        }
    }
}

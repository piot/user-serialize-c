/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <flood/in_stream.h>
#include <flood/out_stream.h>
#include <user-serialize/serialize.h>

void userSerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix)
{
    // CLOG_VERBOSE("%s: cmd: %s", prefix, userSerializeCmdToString(cmd));
    fldOutStreamWriteUInt8(outStream, cmd);
}

void userSerializeWriteUserSessionId(struct FldOutStream* stream, UserSerializeUserSessionId userSessionId)
{
    if (userSessionId == 0) {
        CLOG_ERROR("userSessionId zero is reserved");
    }
    fldOutStreamWriteMarker(stream, 0x86);
    fldOutStreamWriteUInt64(stream, userSessionId);
}

int userSerializeReadUserSessionId(struct FldInStream* stream, UserSerializeUserSessionId* userSessionId)
{
    fldInStreamCheckMarker(stream, 0x86);
    return fldInStreamReadUInt64(stream, userSessionId);
}

void userSerializeWriteUserId(struct FldOutStream* stream, UserSerializeUserId userId)
{
    if (userId == 0) {
        CLOG_ERROR("userId zero is reserved");
    }
    fldOutStreamWriteMarker(stream, 0x89);
    fldOutStreamWriteUInt64(stream, userId);
}

int userSerializeReadUserId(struct FldInStream* stream, UserSerializeUserId* userId)
{
    fldInStreamCheckMarker(stream, 0x89);
    return fldInStreamReadUInt64(stream, userId);
}

void userSerializeWriteClientNonce(struct FldOutStream* stream, UserSerializeClientNonce clientNonce)
{
    fldOutStreamWriteMarker(stream, 0x87);
    fldOutStreamWriteUInt64(stream, clientNonce);
}

int userSerializeReadClientNonce(struct FldInStream* stream, UserSerializeClientNonce* clientNonce)
{
    fldInStreamCheckMarker(stream, 0x87);
    return fldInStreamReadUInt64(stream, clientNonce);
}

void userSerializeWriteServerChallenge(struct FldOutStream* stream, UserSerializeServerChallenge serverChallenge)
{
    fldOutStreamWriteMarker(stream, 0x88);
    fldOutStreamWriteUInt64(stream, serverChallenge);
}

int userSerializeReadServerChallenge(struct FldInStream* stream, UserSerializeServerChallenge* serverChallenge)
{
    fldInStreamCheckMarker(stream, 0x88);
    return fldInStreamReadUInt64(stream, serverChallenge);
}

int userSerializeWriteString(FldOutStream* stream, const char* s)
{
    size_t len = tc_strlen(s);
    fldOutStreamWriteUInt8(stream, len);
    return fldOutStreamWriteOctets(stream, (const uint8_t*) s, len);
}

int userSerializeReadString(struct FldInStream* stream, char* buf, size_t maxLength)
{
    uint8_t stringLength;
    fldInStreamReadUInt8(stream, &stringLength);
    if (stringLength + 1 > maxLength) {
        return -1;
    }
    int errorCode = fldInStreamReadOctets(stream, (uint8_t*) buf, stringLength);
    if (errorCode < 0) {
        return errorCode;
    }
    buf[stringLength] = 0;
    return stringLength;
}

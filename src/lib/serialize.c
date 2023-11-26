/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <flood/in_stream.h>
#include <flood/out_stream.h>
#include <guise-serialize/serialize.h>

void guiseSerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix)
{
    // CLOG_VERBOSE("%s: cmd: %s", prefix, guiseSerializeCmdToString(cmd));
    (void) prefix;
    fldOutStreamWriteUInt8(outStream, cmd);
}

void guiseSerializeWriteUserSessionId(struct FldOutStream* stream, GuiseSerializeUserSessionId userSessionId)
{
    if (userSessionId == 0) {
        CLOG_ERROR("userSessionId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x86);
    fldOutStreamWriteUInt64(stream, userSessionId);
}

int guiseSerializeReadUserSessionId(struct FldInStream* stream, GuiseSerializeUserSessionId* userSessionId)
{
    fldInStreamCheckMarker(stream, 0x86);
    return fldInStreamReadUInt64(stream, userSessionId);
}

void guiseSerializeWriteUserId(struct FldOutStream* stream, GuiseSerializeUserId userId)
{
    //if (userId == 0) {
        //CLOG_ERROR("userId zero is reserved")
    //}
    fldOutStreamWriteMarker(stream, 0x89);
    fldOutStreamWriteUInt64(stream, userId);
}

int guiseSerializeReadUserId(struct FldInStream* stream, GuiseSerializeUserId* userId)
{
    fldInStreamCheckMarker(stream, 0x89);
    return fldInStreamReadUInt64(stream, userId);
}

void guiseSerializeWritePasswordHashWithChallenge(struct FldOutStream* stream,
                                                  GuiseSerializePasswordHashWithChallenge password)
{
    fldOutStreamWriteMarker(stream, 0x99);
    fldOutStreamWriteUInt64(stream, password);
}

int guiseSerializeReadPasswordHashWithChallenge(struct FldInStream* stream,
                                                GuiseSerializePasswordHashWithChallenge* password)
{
    fldInStreamCheckMarker(stream, 0x99);
    return fldInStreamReadUInt64(stream, password);
}

void guiseSerializeWriteClientNonce(struct FldOutStream* stream, GuiseSerializeClientNonce clientNonce)
{
    fldOutStreamWriteMarker(stream, 0x87);
    fldOutStreamWriteUInt64(stream, clientNonce);
}

int guiseSerializeReadClientNonce(struct FldInStream* stream, GuiseSerializeClientNonce* clientNonce)
{
    fldInStreamCheckMarker(stream, 0x87);
    return fldInStreamReadUInt64(stream, clientNonce);
}

void guiseSerializeWriteServerChallenge(struct FldOutStream* stream, GuiseSerializeServerChallenge serverChallenge)
{
    fldOutStreamWriteMarker(stream, 0x88);
    fldOutStreamWriteUInt64(stream, serverChallenge);
}

int guiseSerializeReadServerChallenge(struct FldInStream* stream, GuiseSerializeServerChallenge* serverChallenge)
{
    fldInStreamCheckMarker(stream, 0x88);
    return fldInStreamReadUInt64(stream, serverChallenge);
}

void guiseSerializeWriteUserName(struct FldOutStream* stream, const GuiseSerializeUserName* userName)
{
    fldOutStreamWriteMarker(stream, 0x94);
    guiseSerializeWriteString(stream, userName->utf8);
}

int guiseSerializeReadUserName(struct FldInStream* stream, GuiseSerializeUserName* userName)
{
    fldInStreamCheckMarker(stream, 0x94);
    return guiseSerializeReadString(stream, userName->utf8, 32);
}

int guiseSerializeWriteString(FldOutStream* stream, const char* s)
{
    size_t len = tc_strlen(s);
    fldOutStreamWriteUInt8(stream, (uint8_t) len);
    return fldOutStreamWriteOctets(stream, (const uint8_t*) s, len);
}

int guiseSerializeReadString(struct FldInStream* stream, char* buf, size_t maxLength)
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

int guiseSerializeWriteNetworkAddress(struct FldOutStream* stream, const GuiseSerializeAddress* address)
{
    fldOutStreamWriteUInt8(stream, (uint8_t) address->type);
    if (address->type > 1) {
        CLOG_ERROR("wrong type")
    }
    switch (address->type) {
        case GuiseSerializeAddressTypeV4:
            fldOutStreamWriteOctets(stream, address->address.ipv4, sizeof(address->address.ipv4));
            break;
        case GuiseSerializeAddressTypeV6:
            fldOutStreamWriteOctets(stream, address->address.ipv6, sizeof(address->address.ipv6));
            break;
    }

    return fldOutStreamWriteUInt16(stream, address->port);
}

int guiseSerializeReadNetworkAddress(struct FldInStream* stream, GuiseSerializeAddress* address)
{
    uint8_t octetType;
    int err = fldInStreamReadUInt8(stream, &octetType);
    if (err < 0) {
        return err;
    }
    address->type = (GuiseSerializeAddressType) octetType;

    switch (address->type) {
        case GuiseSerializeAddressTypeV4:
            fldInStreamReadOctets(stream, address->address.ipv4, sizeof(address->address.ipv4));
            break;
        case GuiseSerializeAddressTypeV6:
            fldInStreamReadOctets(stream, address->address.ipv6, sizeof(address->address.ipv6));
            break;
    }

    return fldInStreamReadUInt16(stream, &address->port);
}

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef USER_SERIALIZE_SERIALIZE_H
#define USER_SERIALIZE_SERIALIZE_H

#include <stdint.h>
#include <stdlib.h>

#include <user-serialize/types.h>

struct FldOutStream;
struct FldInStream;

void userSerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix);

void userSerializeWriteUserSessionId(struct FldOutStream* outStream, UserSerializeUserSessionId userSessionId);
int userSerializeReadUserSessionId(struct FldInStream* stream, UserSerializeUserSessionId* userSessionId);

void userSerializeWriteUserId(struct FldOutStream* outStream, UserSerializeUserId userId);
int userSerializeReadUserId(struct FldInStream* stream, UserSerializeUserId* userId);

void userSerializeWriteClientNonce(struct FldOutStream* outStream, UserSerializeClientNonce clientNonce);
int userSerializeReadClientNonce(struct FldInStream* stream, UserSerializeClientNonce* clientNonce);

void userSerializeWriteServerChallenge(struct FldOutStream* outStream, UserSerializeServerChallenge serverChallenge);
int userSerializeReadServerChallenge(struct FldInStream* stream, UserSerializeServerChallenge* serverChallenge);

int userSerializeWriteString(struct FldOutStream* stream, const char* s);
int userSerializeReadString(struct FldInStream* stream, char* buf, size_t maxLength);

#endif

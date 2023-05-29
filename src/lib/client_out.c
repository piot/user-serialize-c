/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <user-serialize/client_out.h>
#include <user-serialize/serialize.h>

#define COMMAND_DEBUG "ClientOut"

int userSerializeClientOutLogin(FldOutStream* stream, UserSerializeClientNonce clientNonce,
                                UserSerializeServerChallenge challenge, const char* name)
{
    userSerializeWriteCommand(stream, userSerializeCmdLogin, COMMAND_DEBUG);
    userSerializeWriteClientNonce(stream, clientNonce);
    userSerializeWriteServerChallenge(stream, challenge);
    userSerializeWriteString(stream, name);

    return 0;
}

int userSerializeClientOutChallenge(FldOutStream* stream, UserSerializeClientNonce clientNonce)
{
    userSerializeWriteCommand(stream, userSerializeCmdChallenge, COMMAND_DEBUG);
    userSerializeWriteClientNonce(stream, clientNonce);

    return 0;
}

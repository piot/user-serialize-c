/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <guise-serialize/client_out.h>
#include <guise-serialize/serialize.h>

#define COMMAND_DEBUG "ClientOut"

int guiseSerializeClientOutLogin(FldOutStream* stream, GuiseSerializeClientNonce clientNonce,
                                 GuiseSerializeUserId userId,
                                 GuiseSerializePasswordHashWithChallenge passwordHashWithChallenge)
{
    guiseSerializeWriteCommand(stream, guiseSerializeCmdLogin, COMMAND_DEBUG);
    guiseSerializeWriteClientNonce(stream, clientNonce);
    guiseSerializeWriteUserId(stream, userId);
    guiseSerializeWritePasswordHashWithChallenge(stream, passwordHashWithChallenge);

    return 0;
}

int guiseSerializeClientOutChallenge(FldOutStream* stream, GuiseSerializeUserId userId,
                                     GuiseSerializeClientNonce clientNonce)
{
    guiseSerializeWriteCommand(stream, guiseSerializeCmdChallenge, COMMAND_DEBUG);
    guiseSerializeWriteClientNonce(stream, clientNonce);
    guiseSerializeWriteUserId(stream, userId);

    return 0;
}

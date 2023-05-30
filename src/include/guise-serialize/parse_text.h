/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef GUISE_SERIALIZE_PARSE_TEXT_H
#define GUISE_SERIALIZE_PARSE_TEXT_H

#include <guise-serialize/types.h>

struct FldTextInStream;

int guiseTextStreamReadUserId(struct FldTextInStream* stream, GuiseSerializeUserId* userId);
int guiseTextStreamReadPasswordHash(struct FldTextInStream* stream, uint64_t* value);
int guiseTextStreamReadUserName(struct FldTextInStream* stream, char* target, size_t max);

#endif

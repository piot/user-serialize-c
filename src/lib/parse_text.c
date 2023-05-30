#include <clog/clog.h>
#include <flood/in_stream.h>
#include <flood/text_in_stream.h>
#include <guise-serialize/parse_text.h>
#include <stdbool.h>

static bool isNumber(char ch)
{
    return ch >= '0' && ch <= '9';
}

static bool isAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

static bool isHex(char ch)
{
    return isNumber(ch) || (ch >= 'a' && ch <= 'f');
}

static bool isSpace(char ch)
{
    return ch == 9 || ch == ' ' || ch == 10 || ch == 13;
}

static bool isAlphaNum(char ch)
{
    return isNumber(ch) || isAlpha(ch);
}

int guiseTextStreamReadUserId(FldTextInStream* stream, GuiseSerializeUserId* userId)
{
    char numberBuffer[32];
    int pos = 0;
    while (1) {
        char ch;
        int err = fldTextInStreamReadCh(stream, &ch);
        if (err < 0) {
            return err;
        }
        if (isSpace(ch)) {
            if (pos > 0) {
                fldTextInStreamUnreadCh(stream);
                numberBuffer[pos] = 0;
                *userId = strtoull(numberBuffer, 0, 10);
                return 0;
            }
            continue;
        } else if (isNumber(ch)) {
            numberBuffer[pos++] = ch;
        }
    }
}

int guiseTextStreamReadPasswordHash(FldTextInStream* stream, uint64_t* value)
{
    char numberBuffer[128];
    int pos = 0;
    while (1) {
        char ch;
        int err = fldTextInStreamReadCh(stream, &ch);
        if (err < 0) {
            return err;
        }
        if (isSpace(ch)) {
            if (pos > 0) {
                if (pos != 16) {
                    return -2;
                }
                numberBuffer[pos] = 0;

                *value = strtoull(numberBuffer, 0, 16);
                return 0;
            }
            continue;
        } else if (isHex(ch)) {
            numberBuffer[pos++] = ch;
        }
    }
}

int guiseTextStreamReadUserName(FldTextInStream* stream, char* target, size_t max)
{
    int pos = 0;
    while (1) {
        char ch;
        int err = fldTextInStreamReadCh(stream, &ch);
        if (err < 0) {
            return err;
        }
        if (isSpace(ch)) {
            if (pos > 0) {
                target[pos] = 0;
                return pos;
            }
            continue;
        } else if (isAlphaNum(ch)) {
            target[pos++] = ch;
            if ((size_t) pos >= max) {
                return -1;
            }
        }
    }
}

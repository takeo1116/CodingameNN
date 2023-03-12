#pragma once
#include <string>
#include <fstream>

inline int char_to_int(char c)
{
    if (c == '=')
        return 0;
    if (c == '/')
        return 63;
    if (c == '+')
        return 62;
    if (c <= '9')
        return (c - '0') + 52;
    if ('a' <= c)
        return (c - 'a') + 26;
    return (c - 'A');
}

int DecodeBase64(std::string str, char *out)
{
    int len = str.length();
    char *p = out;
    for (int idx = 0; idx < len; idx += 4)
    {
        char c0 = char_to_int(str[idx + 0]);
        char c1 = char_to_int(str[idx + 1]);
        char c2 = char_to_int(str[idx + 2]);
        char c3 = char_to_int(str[idx + 3]);

        *p++ = (c0 << 2) | (c1 >> 4);
        *p++ = (((c1 & 15) << 4)) | (c2 >> 2);
        *p++ = (((c2 & 3) << 6)) | c3;
    }
    *p = 0;
    return (p - out);
}
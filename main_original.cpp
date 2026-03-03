#include <iostream>
#include "engine.h"

constexpr inline size_t compileTimeStrlen(const char* text) noexcept
{
    return (*text ? 1+compileTimeStrlen(text+1) : 0);
}

constexpr inline size_t compileTimeCountFirstDigits(const char* text) noexcept
{
    return (*text && ('0'<=*text && *text<='9') ? 1+compileTimeCountFirstDigits(text+1) : 0);
}

constexpr inline bool compileTimeIsDigit(const char* text) noexcept
{
    return compileTimeStrlen(text) == compileTimeCountFirstDigits(text);
}

constexpr inline bool compileTimeContains(const char* text, char letter) noexcept
{
    if ('\n' == *text)
        return false;

    return *text == letter ? 1 : compileTimeContains(text+1, letter);
}
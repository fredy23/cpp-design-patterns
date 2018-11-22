#pragma once

#include <string>
#include <algorithm>

#include "iencryption_strategy.hpp"

class ROT47EncryptionStrategy : public IEncryptionStrategy
{
public:
    std::string encrypt(const std::string& p_data) const override
    {
        std::string result = p_data;

        std::transform(result.begin(), result.end(), result.begin(), [](const char& p_char)
        {
            return inRange(p_char) ? toROT47(p_char) : p_char;
        });

        return result;
    }

    std::string decrypt(const std::string& p_data) const override
    {
        return encrypt(p_data);
    }

private:
    static bool inRange(const char& p_char)
    {
        return p_char >= '!' && p_char < '~';
    }

    static char toROT47(const char& p_char)
    {
        return static_cast<char>((p_char - '!' + 47) % 94 + '!');
    }
};

#pragma once

#include <string>
#include <algorithm>

#include "iencryption_strategy.hpp"

class XOREncryptionStrategy : public IEncryptionStrategy
{
public:
    XOREncryptionStrategy(const std::string& p_key)
        : m_key{p_key}
    {
    }

    std::string encrypt(const std::string& p_data) const override
    {
        std::string result = p_data;
        std::size_t keyIndex = 0;

        std::transform(result.begin(), result.end(), result.begin(), [key = m_key, &keyIndex](const char& p_char)
        {
            keyIndex %= key.length();
            return p_char xor key[keyIndex++];
        });

        return result;
    }

    std::string decrypt(const std::string& p_data) const override
    {
        return encrypt(p_data);
    }

private:
    std::string m_key;
};

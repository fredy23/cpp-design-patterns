#pragma once

#include <string>

class IEncryptionStrategy
{
public:
    virtual std::string encrypt(const std::string& p_data) const = 0;
    virtual std::string decrypt(const std::string& p_data) const = 0;
    virtual ~IEncryptionStrategy() = default;
};

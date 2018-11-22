#pragma once

#include <string>
#include <memory>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "iencryption_strategy.hpp"

class Message
{
public:
    Message(const std::string& p_data)
        : m_data{p_data}
    {
    }

    Message(const std::string& p_data, std::unique_ptr<IEncryptionStrategy>&& p_encryptonStrategy)
        : m_data{p_data}, m_encryptionStrategy{std::move(p_encryptonStrategy)}
    {
    }

    void encrypt()
    {
        if(m_encryptionStrategy)
        {
            m_data = m_encryptionStrategy->encrypt(m_data);
        }
    }

    void decrypt()
    {
        if(m_encryptionStrategy)
        {
            m_data = m_encryptionStrategy->decrypt(m_data);
        }
    }

    std::string getData() const
    {
        return m_data;
    }

    std::string getHexData() const
    {
        std::ostringstream result {};
        
        std::for_each(m_data.begin(), m_data.end(), [&result](const char& p_char)
        {
            result << std::hex << std::uppercase
                   << std::setfill('0') << std::setw(2)
                   << static_cast<int>(p_char);
        });

        return result.str();
    }

    void setEncryptionStrategy(std::unique_ptr<IEncryptionStrategy>&& p_encryptionStrategy)
    {
        m_encryptionStrategy = std::move(p_encryptionStrategy);
    }

private:
    std::string m_data;
    std::unique_ptr<IEncryptionStrategy> m_encryptionStrategy;
};

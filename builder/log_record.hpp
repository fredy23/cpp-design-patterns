#pragma once

#include <string>

class LogRecord
{
    public:

        void setType(const std::string& p_type)
        {
            m_type = p_type;
        }

        void setMessage(const std::string& p_message)
        {
            m_message = p_message;
        }

        void setDateTime(const std::string& p_dateTime)
        {
            m_dateTime = p_dateTime;
        }

        std::string getLogRecordContent() const
        {
            return m_type + '\n' + m_message + '\n' + m_dateTime;
        }

    private:
        std::string m_type {};
        std::string m_message {};
        std::string m_dateTime {};
};

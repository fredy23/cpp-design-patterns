#pragma once

#include <string>

class LogRecord
{
public:

    void setStart(const std::string& p_start)
    {
        m_start = p_start;
    }

    void setEnd(const std::string& p_end)
    {
        m_end = p_end;
    }

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
        return m_start + "\n  " +
                m_type + "\n  " + m_message + "\n  " + m_dateTime + '\n'
                + m_end;
    }

private:
    std::string m_start {};
    std::string m_end {};
    std::string m_type {};
    std::string m_message {};
    std::string m_dateTime {};
};

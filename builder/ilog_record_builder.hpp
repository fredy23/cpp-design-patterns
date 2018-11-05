#pragma once

#include <string>

#include "log_record.hpp"

class ILogRecordBuilder
{
public:
    virtual void buildLogRecordStart() = 0;
    virtual void buildLogRecordEnd() = 0;
    virtual void buildLogRecordType(const std::string& p_type) = 0;
    virtual void buildLogRecordMessage(const std::string& p_message) = 0;
    virtual void buildLogRecordDateTime(const std::string& p_dateTime) = 0;

    LogRecord getLogRecord() const
    {
        return m_logRecord;
    }

    virtual ~ILogRecordBuilder() = default;

protected:
    LogRecord m_logRecord;
};

#pragma once

#include <string>

#include "log_record.hpp"

class ILogRecordBuilder
{
    public:
        virtual void buildLogRecordType(const std::string& p_type) = 0;
        virtual void buildLogRecordMessage(const std::string& p_message) = 0;
        virtual void buildLogRecordDateTime(const std::string& p_dateTime) = 0;

        LogRecord getLogRecord()
        {
            return m_logRecord;
        }

        virtual ~ILogRecordBuilder() = default;

    protected:
        LogRecord m_logRecord;
};

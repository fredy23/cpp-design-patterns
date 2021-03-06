#pragma once

#include <memory>

#include "ilog_record_builder.hpp"

class LogRecordDirector
{
public:
    LogRecordDirector(std::unique_ptr<ILogRecordBuilder>&& p_logBuilder)
        : m_logBuilder{std::move(p_logBuilder)}
    {
    }

    void setLogRecordBuilder(std::unique_ptr<ILogRecordBuilder>&& p_logBuilder)
    {
        m_logBuilder = std::move(p_logBuilder);
    }

    void buildLogRecord(
        const std::string& p_type,
        const std::string& p_message,
        const std::string& p_dateTime)
    {
        m_logBuilder->buildLogRecordStart();
        m_logBuilder->buildLogRecordType(p_type);
        m_logBuilder->buildLogRecordMessage(p_message);
        m_logBuilder->buildLogRecordDateTime(p_dateTime);
        m_logBuilder->buildLogRecordEnd();
    }

    LogRecord getLogRecord() const
    {
        return m_logBuilder->getLogRecord();
    }

private:
    std::unique_ptr<ILogRecordBuilder> m_logBuilder;
};

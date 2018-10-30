#pragma once

#include <string>

#include "ilog_record_builder.hpp"

class JSONLogRecordBuilder : public ILogRecordBuilder
{
    public:
        void buildLogRecordStart()
        {
            m_logRecord.setStart("\"log\": {");
        }

        void buildLogRecordEnd()
        {
            m_logRecord.setEnd("}");
        }

        void buildLogRecordType(const std::string& p_type)
        {
            m_logRecord.setType("\"type\": \"" + p_type + "\",");
        }

        void buildLogRecordMessage(const std::string& p_message)
        {
            m_logRecord.setMessage("\"message\": \"" + p_message + "\",");
        }

        void buildLogRecordDateTime(const std::string& p_dateTime)
        {
            m_logRecord.setDateTime("\"datetime\": \"" + p_dateTime + "\",");
        }
};

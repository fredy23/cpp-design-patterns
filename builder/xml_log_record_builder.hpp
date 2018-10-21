#pragma once

#include <string>

#include "ilog_record_builder.hpp"

class XMLLogRecordBuilder : public ILogRecordBuilder
{
    public:
        void buildLogRecordType(const std::string& p_type)
        {
            m_logRecord.setType("<type>" + p_type + "</type>");
        }

        void buildLogRecordMessage(const std::string& p_message)
        {
            m_logRecord.setMessage("<message>" + p_message + "</message>");
        }

        void buildLogRecordDateTime(const std::string& p_dateTime)
        {
            m_logRecord.setDateTime("<datetime>" + p_dateTime + "</datetime>");
        }
};

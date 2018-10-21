#include <iostream>
#include <ctime>
#include <string>

#include "log_record_director.hpp"
#include "xml_log_record_builder.hpp"
#include "json_log_record_builder.hpp"

std::string getCurrentDateTime()
{
    std::time_t timeData = std::time(nullptr);
    std::string formattedDateTime {"0000-00-00 00:00:00"};
    char buffer[32];

    if(std::strftime(buffer, sizeof(buffer), "%F %T", std::localtime(&timeData)))
    {
        formattedDateTime = buffer;
    }

    return formattedDateTime;
}

int main()
{
    XMLLogRecordBuilder xmlLogBuilder {};

    LogRecordDirector logDirector {&xmlLogBuilder};

    logDirector.buildLogRecord("info", "Everything is OK", getCurrentDateTime());

    auto logRecord = logDirector.getLogRecord();

    std::cout << logRecord.getLogRecordContent() << '\n';

    /*JSONLogRecordBuilder jsonLogBuilder {};
    logDirector.setLogRecordBuilder(jsonRecordBuilder);
    logDirector.buildLogRecord("error", "Bad things happen...", "2018-10-20 16:06:13");*/
}

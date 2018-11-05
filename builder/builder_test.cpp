#include <iostream>
#include <ctime>
#include <string>

#include "log_record_director.hpp"
#include "xml_log_record_builder.hpp"
#include "json_log_record_builder.hpp"

#include "datetime_utils.hpp"

int main()
{
    XMLLogRecordBuilder xmlLogBuilder {};

    LogRecordDirector logDirector {&xmlLogBuilder};

    logDirector.buildLogRecord("info", "Everything is OK", DateTimeUtils::getCurrentDateTime());

    std::cout << "XML log record content:\n\n";

    auto logRecord = logDirector.getLogRecord();
    std::cout << logRecord.getLogRecordContent() << "\n\n";

    JSONLogRecordBuilder jsonLogBuilder {};
    logDirector.setLogRecordBuilder(&jsonLogBuilder);
    logDirector.buildLogRecord("error", "Bad things happen...", "2018-10-20 16:06:13");

    std::cout << "JSON log record content:\n\n";

    logRecord = logDirector.getLogRecord();
    std::cout << logRecord.getLogRecordContent() << "\n\n";
}

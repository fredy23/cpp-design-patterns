#include <ctime>
#include <string>

#include "datetime_utils.hpp"

std::string DateTimeUtils::getCurrentDateTime()
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

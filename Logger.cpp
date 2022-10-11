#include "Logger.h"

Logger::Logger(std::string name)
{
    logLevel = TESTING;

    if(name != "") filename = name;
    else filename = "LogFiles/" + std::to_string(time(NULL)) + "_logfile.txt";

    writer.open(filename);
}


void Logger::log(std::string message, int messageLevel)
{
    if(messageLevel >= logLevel)
    {
        //formatting garbage to make strftime() work
        time_t current_time;
        tm* time_temp;
        time(&current_time);
        time_temp = localtime(&current_time);

        //write message to log file with timestamp prepended
        char timestr [80];
        strftime(timestr, 1000, "%T", time_temp);
        writer << timestr << " ";
        writer << message << std::endl;
    }
}
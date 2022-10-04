#include "Logger.h"

Logger::Logger(std::string name)
{
    if(name == "") filename = "LogFiles/" + std::to_string(time(NULL)) + "_logfile.txt";
    else filename = name;
    writer.open(filename);
}


void Logger::log(std::string message)
{
    writer << message << std::endl;
}
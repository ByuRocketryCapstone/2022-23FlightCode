#include "Logger.h"


static bool enable = false;

static enum loggerState {
    init_st,
    wait_enable_st,
    log_data_st
} CurrState, NextState;

Logger::Logger(std::string name)
{
    logLevel = TESTING;

    if(name != "") filename = name;
    else filename = "LogFiles/" + std::to_string(time(NULL)) + "_logfile.txt";

    writer.open(filename);
}

void Logger::log_init() {
    enable = false;
};

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

void Logger::log_enable() {
    enable = true;
}

void Logger::log_disable() {
    enable = false;
}

//logger state machine
void Logger::log_tick() {

}
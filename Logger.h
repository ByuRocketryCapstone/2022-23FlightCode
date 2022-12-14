#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include "Parameters.h"

class Logger
{
    public:
    Logger(std::string name = "");
    ~Logger();
    void log(std::string message, int messageLevel); 
    void log_init();
    void log_tick();
    void log_enable();
    void log_disable();

    private:
    int logLevel;
    std::string filename;
    std::ofstream writer;
};

#endif //LOGGER_H
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include "Parameters.h"

class Logger
{
    public:
    Logger(std::string name = "");
    void log(std::string message, int messageLevel); 

    private:
    int logLevel;
    std::string filename;
    std::ofstream writer;
};

#endif //LOGGER_H
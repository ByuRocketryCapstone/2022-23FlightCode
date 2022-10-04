#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger
{
    public:
    Logger(std::string name = "");
    void log(std::string message); 

    private:
    std::string filename;
    std::ofstream writer;
};

#endif //LOGGER_H
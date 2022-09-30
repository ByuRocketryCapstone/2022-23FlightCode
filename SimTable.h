#ifndef SIM_TABLE_H
#define SIM_TABLE_H

#include <string>

class SimTable
{
    public:
    SimTable(int length,
                int numRows,
                std::string* rowIdentifiers,
                double** dataTable);
    double at(std::string rowID, int colNum);       //get value at specific column
    double atTime(std::string rowID, double time);  //get value at timestamp (with interpolation)
    
    private:
    double** dataTable;
    std::string* rowIdentifiers;
    int length, numRows;


};

#endif //SIM_TABLE_H
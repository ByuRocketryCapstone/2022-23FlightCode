#ifndef SIM_TABLE_H
#define SIM_TABLE_H

/*
Class to hold launch simulation data.

The class is structured to be able to hold an arbitrary amount of data (length), and
an abritrary amount of kinds of data (rows). The first row should always be time data,
followed by any other data, each in its own row.

The rowIdentifiers list is used to label each row with the kind of data, and make the 
data searchable by keyword.
*/

#include <string>
#include "Logger.h"
#include "Parameters.h"

extern Logger logger;

class SimTable
{
    public:
    SimTable(int length,
                int numRows,
                std::string* rowIdentifiers,        //1D array of strings as row labels
                double** dataTable);                //2D array containing the sim data
                                                    
    double at(std::string rowID, int colNum);       //get value at specific column
    double atTime(std::string rowID, double time);  //get value at timestamp (with interpolation)

    private:
    double** dataTable;                 //table containing simulation data
    std::string* rowIdentifiers;        //list of strings corresponding to row names
    int length, numRows;                //table sizes
    int findRow(std::string rowID);


};

#endif //SIM_TABLE_H
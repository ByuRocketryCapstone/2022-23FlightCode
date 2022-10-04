#include "SimTable.h"

SimTable::SimTable(int length,
                int numRows,
                std::string* rowIdentifiers,        
                double** dataTable)
{
    this->length = length;
    this->numRows = numRows;
    for(int i = 0; i < length; i++)
    {
        this->rowIdentifiers[i] = rowIdentifiers[i];
    }
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < length; j++)
        {
            this->dataTable[i][j] = dataTable[i][j];
        }
    }
}


double SimTable::at(std::string rowID, int colNum)
{
    int rowNum = findRow(rowID);
    if (rowNum == -1) 
    {
        logger.log("Identifier " + rowID + " was used in SimTable::at(), but \
        no row was found with that idenfifier.");
        return 0.0;
    }
    return dataTable[rowNum][colNum];
}


double SimTable::atTime(std::string rowID, double time)
{
    return 0;
}


int SimTable::findRow(std::string rowID)
{
    for(int i = 0; i < numRows; i++)
    {
        if (rowIdentifiers[i] == rowID) return i;
    }
    return -1;
}
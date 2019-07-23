#include<string>
#include<fstream>

#include "CostMatrix.hpp"

CostMatrix* readMatrixFromFile(const std::string &fileName)
{
    try
    {
        std::ifstream inFile(fileName);
        if (!inFile.is_open())
        {
            throw std::invalid_argument(fileName);
        }

        int size;
        inFile >> size;
        std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));

        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                inFile >> matrix[i][j];
            }
        }
        return new CostMatrix(matrix);
    }
    catch(std::invalid_argument &ia){
        std::cerr << "Invalid argument. Unable to open file: " << ia.what() << std::endl;
        return nullptr;
    }
    catch (std::exception e)
    {
        std::cerr << "File " << fileName << " has bad format, unable to parse matrix" << std::endl;
        return nullptr;
    }
}
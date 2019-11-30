#include <string>
#include <fstream>
#include <cctype>

#include "CostMatrix.hpp"

CostMatrix* readMatrixFromFile(const std::string &fileName)
{
    try
    {
        std::ifstream inFile(fileName);
        if (!inFile.is_open())
        {
            throw std::invalid_argument("Unable it open file: " + fileName);
        }

        std::string temp; 

        inFile >> temp;
        int size;
        size = std::stoi(temp);

        std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));

        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            { 
                if(inFile >> temp){
                    matrix[i][j] = std::stoi(temp);
                }
                else{
                    throw std::invalid_argument("Matrix has bad size");
                }
            }
        }
        return new CostMatrix(matrix);
    }
    catch(std::invalid_argument &ia){
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
        return nullptr;
    }
}
#include"CostMatrix.hpp"

#include<iostream>
#include <string>
#include <fstream>
#include <cctype>


int calcPathCost(const CostMatrix& costMatrix, const std::vector<int> &path)
{
    int cost = costMatrix[0][path[0]];

    for (int i = 0; i < path.size() - 1; i++)
    {
        cost += costMatrix[path[i]][path[i + 1]];
    }
    cost += costMatrix[path.back()][0];

    return cost;
}


void printMatrix(const CostMatrix& costMatrix)
{
    for (int i = 0; i < costMatrix.size(); i++)
    {
        for (int j = 0; j < costMatrix[i].size(); j++)
        {
            std::cout << costMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


CostMatrix readMatrixFromFile(const std::string &fileName)
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

        CostMatrix matrix(size, std::vector<int>(size, 0));

        for (size_t row = 0; row < size; ++row)
        {
            for (size_t column = 0; column < size; ++column)
            { 
                if(inFile >> temp){
                    matrix[row][column] = std::stoi(temp);
                }
                else{
                    throw std::invalid_argument("Matrix has bad size");
                }
            }
        }
        return matrix;
    }
    catch(std::invalid_argument &ia){
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
        throw std::invalid_argument(ia);
    }
}

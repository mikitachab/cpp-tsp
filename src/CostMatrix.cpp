//
// Created by mikita on 17.07.19.
//

#include "CostMatrix.h"

bool CostMatrix::readFromFile(const std::string &filename)
{
    std::ifstream inFile;

    inFile.open(filename);
    if (!inFile)
    {
        std::cout << "Unable to open file " << filename << std::endl;
        return false;
    }

    inFile >> this->size;
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));

    try
    {
        for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                inFile >> matrix[i][j];
            }
        }
    }
    catch (std::exception e)
    {
        std::cout << "File " << filename << " has bad format, unable to parse matrix" << std::endl;
        return false;
    }
    costMatrix = std::move(matrix);
    return true;
}

void CostMatrix::print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << costMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int CostMatrix::computeCost(const std::vector<int> &path)
{
    int cost = costMatrix[0][path[0]];

    for (int i = 0; i < path.size() - 1; i++)
    {
        cost += costMatrix[path[i]][path[i + 1]];
    }
    cost += costMatrix[path.back()][0];

    return cost;
}

#include "CostMatrix.h"

bool CostMatrix::readFromFile(const std::string &fileName)
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        std::cout << "Unable to open file " << fileName << std::endl;
        return false;
    }

    inFile >> size;
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));

    try
    {
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                inFile >> matrix[i][j];
            }
        }
    }
    catch (std::exception e)
    {
        std::cout << "File " << fileName << " has bad format, unable to parse matrix" << std::endl;
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

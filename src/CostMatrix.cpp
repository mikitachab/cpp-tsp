#include "CostMatrix.hpp"

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

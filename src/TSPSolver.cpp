#include <algorithm> // next_permutation, copy
#include <iterator>  // back_inserter
#include <limits>    // numeric_limits

#include "TSPSolver.h"

TSPResult *TSPSolver::solveBruteForce(CostMatrix &costs)
{
    std::vector<int> finalPath, currentPath;
    int finalCost = std::numeric_limits<int>::max();
    int currentCost;

    for (int i = 1; i < costs.size; i++)
    {
        currentPath.push_back(i);
    }

    do
    {
        currentCost = costs.computeCost(currentPath);
        if (currentCost < finalCost)
        {
            finalCost = currentCost;
            std::copy(currentPath.begin(), currentPath.end(), std::back_inserter(finalPath));
        }

    } while (std::next_permutation(currentPath.begin(), currentPath.end()));

    TSPResult *result = new TSPResult(finalPath, finalCost);
    return result;
}

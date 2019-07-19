#include <algorithm> // next_permutation, copy
#include <iterator>  // back_inserter
#include <limits>    // numeric_limits
#include <numeric>   // itoa

#include "TSPSolver.h"

TSPResult TSPSolver::solveBruteForce(CostMatrix &costs)
{
    size_t pathSize = costs.size - 1;
    std::vector<int> finalPath, currentPath(pathSize);
    std::iota(currentPath.begin(), currentPath.end(), 1);

    int finalCost = std::numeric_limits<int>::max();
    int currentCost;
    do
    {
        currentCost = costs.computeCost(currentPath);
        if (currentCost < finalCost)
        {
            finalCost = currentCost;
            finalPath = currentPath;
        }

    } while (std::next_permutation(currentPath.begin(), currentPath.end()));

    return TSPResult(finalPath, finalCost);
}

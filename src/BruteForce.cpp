#include <algorithm> // next_permutation
#include <iterator>  // back_inserter
#include <limits>    // numeric_limits
#include <numeric>   // iota

#include "TSPSolver.hpp"

TSPResult BruteForce::solve(CostMatrix &costs)
{
    size_t pathSize = costs.size() - 1;
    std::vector<int> finalPath, currentPath(pathSize);
    std::iota(currentPath.begin(), currentPath.end(), 1);

    int finalCost = std::numeric_limits<int>::max();
    int currentCost;
    do
    {
        currentCost = calcPathCost(costs, currentPath);
        if (currentCost < finalCost)
        {
            finalCost = currentCost;
            finalPath = currentPath;
        }

    } while (std::next_permutation(currentPath.begin(), currentPath.end()));

    TSPResult result{finalPath, finalCost};
    return result;
}

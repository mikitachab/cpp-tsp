#include "CostMatrix.h"

struct TSPResult
{
    int cost;
    std::vector<int> path;
    TSPResult() = default;
    TSPResult(std::vector<int> path, int cost) : path(path), cost(cost) {}
};

class TSPSolver
{
public:
    virtual ~TSPSolver() = default;

    TSPResult result;

    TSPResult solveBruteForce(CostMatrix &costs);
};
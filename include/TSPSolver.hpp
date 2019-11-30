#ifndef CPP_TSP_TSPSOLVER_H
#define CPP_TSP_TSPSOLVER_H

#include "CostMatrix.hpp"

struct TSPResult
{
    std::vector<int> path;
    int cost;
};

class TSPSolver
{
public:
    virtual ~TSPSolver() = default;

    TSPResult solveBruteForce(CostMatrix &costs);
};

#endif //CPP_TSP_TSPSOLVER_H
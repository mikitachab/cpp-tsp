#pragma once

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

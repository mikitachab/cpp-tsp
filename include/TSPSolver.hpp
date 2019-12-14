#pragma once

#include "CostMatrix.hpp"

struct TSPResult
{
    std::vector<int> path;
    int cost;
};


class ITSPSolver 
{
public:
    virtual TSPResult solve(CostMatrix &costs) = 0;
};


class BruteForce: ITSPSolver 
{
public:
    TSPResult solve(CostMatrix &costs);
};

#pragma once

#include "CostMatrix.hpp"

#include <limits>
#include <string>

const int INF = std::numeric_limits<int>::max();


struct TSPResult
{
    std::vector<int> path;
    int cost;
};


class ITSPSolver 
{
public:
    virtual std::string info() = 0;
    virtual TSPResult solve(CostMatrix &costs) = 0;
};


class BruteForce: public ITSPSolver 
{
public:
    std::string info()
    {
        return "Brute Force";
    }
    
    TSPResult solve(CostMatrix &costs);
};

class BranchAndBound: public ITSPSolver
{
public:
    std::string info()
    {
        return "Branch & Bound";
    }
    
    TSPResult solve(CostMatrix &costs);
};

#include"CostMatrix.hpp"
#include"TSPSolver.hpp"
#include <queue>
#include<vector>

struct Node
{
    std::vector<int> path;
    CostMatrix reducedCostMatrix;
    int lowerBoundCost;
    int currentCity;
    int level;
};

struct NodeComp {
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return lhs->lowerBoundCost > rhs->lowerBoundCost;
    }
};

typedef std::priority_queue<Node*, std::vector<Node*>, NodeComp> NodesHeap;

Node* makeNode(CostMatrix parentMatrix, const std::vector<int> &path, int level, int from, int to);

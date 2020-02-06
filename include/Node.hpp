#include"CostMatrix.hpp"
#include"TSPSolver.hpp"
#include<queue>
#include<vector>
#include<limits>

constexpr unsigned START_LEVEL = 0;
constexpr unsigned TO_ROOT_CITY = 0;
constexpr unsigned FROM_ROOT_CITY = std::numeric_limits<unsigned>::max();

struct Node
{
    std::vector<int> path;
    CostMatrix reducedCostMatrix;
    unsigned currentCity;
    unsigned level;
    int lowerBoundCost;
    
    Node(
        CostMatrix parentMatrix, 
        std::vector<int> path, 
        unsigned level=START_LEVEL, 
        unsigned from=FROM_ROOT_CITY, 
        unsigned to=TO_ROOT_CITY
    );
    friend bool operator>(const Node& lhs, const Node& rhs);
    friend bool operator<(const Node& lhs, const Node& rhs);
};

using NodesMinHeap = std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>>;


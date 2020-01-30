#include"Node.hpp"

Node::Node(
    CostMatrix parentMatrix, 
    std::vector<int> path, 
    unsigned level,
    unsigned from, 
    unsigned to
)
{
    this->path = path;
    this->level = level;
    this->currentCity = to;
    this->reducedCostMatrix = parentMatrix;
    this->reducedCostMatrix[to][0] = INF;
    
    if (level != START_LEVEL){
        this->path.push_back(to);

        for (int i = 0; i < this->reducedCostMatrix.size(); i++)
        {
            this->reducedCostMatrix[from][i] = INF;
            this->reducedCostMatrix[i][to] = INF;
        }
    }
}


bool operator>(const Node& lhs, const Node& rhs)
{
    return lhs.lowerBoundCost > rhs.lowerBoundCost;
}
bool operator<(const Node& lhs, const Node& rhs)
{
    return lhs.lowerBoundCost < rhs.lowerBoundCost;
}
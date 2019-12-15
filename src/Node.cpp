#include"Node.hpp"

Node* makeNode(CostMatrix parentMatrix, const std::vector<int> &path, int level, int from, int to)
{
    Node* node = new Node;

    node->path = path;
    node->level = level;
    node->currentCity = to;
    node->reducedCostMatrix = parentMatrix;
    node->reducedCostMatrix[to][0] = INF;
    
    if (level != 0){
        node->path.push_back(to);

        for (int i = 0; i < node->reducedCostMatrix.size(); i++)
        {
            node->reducedCostMatrix[from][i] = INF;
            node->reducedCostMatrix[i][to] = INF;
        }
    }

    return node;
}
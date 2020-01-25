#include "CostMatrix.hpp"
#include "TSPSolver.hpp"
#include "Node.hpp"
#include "Utils.hpp"

#include <vector>

int ReduceMatrixAndCalculateCost(CostMatrix &reducedMatrix);
std::vector<int> rowReduction(CostMatrix &reducedMatrix);
std::vector<int> columnReduction(CostMatrix &reducedMatrix);


TSPResult BranchAndBound::solve(CostMatrix &costs){

    NodesHeap liveNodes;
    std::vector<int> path;

    Node* root = makeNode(costs, path, 0, -1, 0);
    root->lowerBoundCost = ReduceMatrixAndCalculateCost(root->reducedCostMatrix);
    liveNodes.push(root);
    int currentCity = 0;

    while (!liveNodes.empty())
    {
        Node* bestNode = liveNodes.top();
        liveNodes.pop();
        currentCity = bestNode->currentCity;


        if (bestNode->level == costs.size() - 1)
        {
            return TSPResult{bestNode->path, bestNode->lowerBoundCost};
        }

        for (int city = 0; city < costs.size(); city++)
        {
            if (bestNode->reducedCostMatrix[currentCity][city] != INF)
            {

                Node* child = makeNode(bestNode->reducedCostMatrix, bestNode->path,
                    bestNode->level + 1, currentCity, city);

                int currentCost = bestNode->lowerBoundCost;
                int currentEdgeCost = bestNode->reducedCostMatrix[currentCity][city];
                int cityLowerBound = ReduceMatrixAndCalculateCost(child->reducedCostMatrix); 
                int lowerBound = currentCost + currentEdgeCost + cityLowerBound;
                
                child->lowerBoundCost = lowerBound;
                liveNodes.push(child);
            }
        }

        delete bestNode;
    }
}

int ReduceMatrixAndCalculateCost(CostMatrix &reducedMatrix)
{
    int cost = 0;

    auto rowsMins = rowReduction(reducedMatrix);
    auto colsMins = columnReduction(reducedMatrix);

    auto rowsColsMins = concat(rowsMins, colsMins);

    for(const auto& n: rowsColsMins){
        if(n != INF) {
            cost+=n;
        }
    }

    return cost;
}


std::vector<int> rowReduction(CostMatrix &reducedMatrix)
{

    size_t pathSize = reducedMatrix.size();
    std::vector<int> rowsMins(pathSize, INF);
    
    for (int row = 0; row < pathSize; row++)
        for (int column = 0; column < pathSize; column++)
            if (reducedMatrix[row][column] < rowsMins[row])
                rowsMins[row] = reducedMatrix[row][column];

    for (int row = 0; row < pathSize; row++)
        for (int column = 0; column < pathSize; column++)
            if (reducedMatrix[row][column] != INF && rowsMins[row] != INF)
                reducedMatrix[row][column] -= rowsMins[row];

    return rowsMins;
}

std::vector<int> columnReduction(CostMatrix &reducedMatrix)
{
    size_t pathSize = reducedMatrix.size();
    std::vector<int> colsMins(pathSize, INF);

    for (int row = 0; row < pathSize; row++)
        for (int column = 0; column < pathSize; column++)
            if (reducedMatrix[row][column] < colsMins[column])
                colsMins[column] = reducedMatrix[row][column];

    for (int row = 0; row < pathSize; row++)
        for (int column = 0; column < pathSize; column++)
            if (reducedMatrix[row][column] != INF && colsMins[column] != INF)
                reducedMatrix[row][column] -= colsMins[column];

    return colsMins;
}
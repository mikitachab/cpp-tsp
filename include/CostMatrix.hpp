#pragma once

#include<vector>
#include<string>

using CostMatrix = std::vector<std::vector<int>>;

CostMatrix readMatrixFromFile(const std::string &fileName);
void printMatrix(const CostMatrix& costMatrix);
int calcPathCost(const CostMatrix& costMatrix, const std::vector<int> &path);




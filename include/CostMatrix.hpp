#pragma once

#include<vector>
#include<string>

typedef  std::vector<std::vector<int>> CostMatrix;

CostMatrix readMatrixFromFile(const std::string &fileName);
void printMatrix(const CostMatrix& costMatrix);
int calcPathCost(const CostMatrix& costMatrix, const std::vector<int> &path);




#ifndef CPP_TSP_COSTMATRIX_H
#define CPP_TSP_COSTMATRIX_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class CostMatrix
{
public:
    size_t size{0};
    std::vector<std::vector<int>> costMatrix;
    int computeCost(const std::vector<int> &path);

    void print();
    CostMatrix(std::vector<std::vector<int>> matrix) : costMatrix(matrix), size(matrix.size()) {}
    CostMatrix() = default;
    CostMatrix(const CostMatrix &matrix) = delete;
    virtual ~CostMatrix() = default;
};

#endif //CPP_TSP_COSTMATRIX_H

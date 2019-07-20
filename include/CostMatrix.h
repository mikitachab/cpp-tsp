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

    bool readFromFile(const std::string &fileName);
    void print();

    CostMatrix() = default;
    CostMatrix(const CostMatrix &matrix) = delete;
    virtual ~CostMatrix() = default;
};

#endif //CPP_TSP_COSTMATRIX_H

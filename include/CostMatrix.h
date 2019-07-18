//
// Created by mikita on 17.07.19.
//
#ifndef CPP_TSP_COSTMATRIX_H
#define CPP_TSP_COSTMATRIX_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class CostMatrix
{
public:
    int size{0};
    std::vector<std::vector<int>> costMatrix;
    int computeCost(const std::vector<int> &path);

    bool readFromFile(const std::string &filename);
    void print();

    CostMatrix() = default;
    CostMatrix(const CostMatrix &matrix) = delete;
    virtual ~CostMatrix() = default;
};

#endif //CPP_TSP_COSTMATRIX_H

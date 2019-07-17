//
// Created by mikita on 17.07.19.
//
#ifndef CPP_TSP_COSTMATRIX_H
#define CPP_TSP_COSTMATRIX_H

#include <iostream>
#include <string>
#include <fstream>


class CostMatrix {
public:
    int size{0};
    int** costMatrix;

    void readFromFile(std::string filename);
    void print();
    int computeCost(int* path);

    virtual ~CostMatrix();
};


#endif //CPP_TSP_COSTMATRIX_H

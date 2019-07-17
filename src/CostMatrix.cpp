//
// Created by mikita on 17.07.19.
//

#include "CostMatrix.h"

void CostMatrix::readFromFile(std::string filename) {
    std::ifstream inFile;

    inFile.open(filename);
    if (!inFile){
        std::cout << "Unable to open file " << filename <<std::endl;
    }

    inFile >> this->size;

    // matrix alloc
    this->costMatrix = new int*[this->size];
    for (int i = 0; i < this->size; i++){
        costMatrix[i] = new int[this->size];
    }

    // fill matrix
    try {
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                inFile >> costMatrix[i][j];
            }
        }
    } catch (std::exception e) {
        std::cout << "File " << filename << " has bad format, unable to parse matrix" << std::endl;
    }
}

void CostMatrix::print(){
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout<< costMatrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}


int CostMatrix::computeCost(int* path){

    int cost = costMatrix[0][path[0]];
    int i = 0;
    for(; i < size-2;i++) {
        cost += costMatrix[path[i]][path[i+1]];
    }
    cost += costMatrix[i+1][0];
    return cost;
}


CostMatrix::~CostMatrix() {
    for (int i = 0; i < size; ++i)
        delete [] this->costMatrix[i];
    delete [] this->costMatrix;
}


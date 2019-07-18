#include <iostream>
#include <string>
#include <algorithm> /* next_permutation */
#include<limits> // numeric_limits<int>::max()
#include "CostMatrix.h"

struct TSPResult {
    int* path;
    int cost;
};

TSPResult* makeResult(int* path, int cost){
    TSPResult* result = new TSPResult;
    result->path = path;
    result->cost = cost;
    return result;
}

void deepCopy(int* dst, int* src, int size){
    for (int i = 0; i < size; i++){
        dst[i] = src[i];
    }
}
void pprint(int* path, int size){
    std::cout<<path[0]<<std::endl;

    for (int i = 0; i < size; i++){
        std::cout<<path[i]<<" ";
    }
}

void printResult(TSPResult* result, int size){
    std::cout<<"minimal cost = " << result->cost<<std::endl;
    std::cout<<"path: ";
    
    for (int i = 0; i < size; i++){
        std::cout<<result->path[i]<<" ";
    }
    
} 

TSPResult* TSPBruteForce(CostMatrix matrix){
    int* currentPath = new int[matrix.size-1];
    int* finalPath = new int[matrix.size-1];

    for(int i = 0; i < matrix.size-1; i++){
        currentPath[i] = i;
    }

    int finalCost, currentCost = std::numeric_limits<int>::max();
    while(std::next_permutation(currentPath, currentPath + matrix.size-1)) {
        currentCost = matrix.computeCost(currentPath);
        if (currentCost < finalCost){
            finalCost = currentCost;
            deepCopy(finalPath, currentPath, matrix.size-1);
        }        
    }
    return makeResult(finalPath, finalCost);
}

int main() {
    std::string filename = "file.txt";

    CostMatrix matrix;
    matrix.readFromFile(filename);
    matrix.print();
    // TSPResult* result; 

    // result =  TSPBruteForce(matrix);
    // printResult(result, matrix.size-1);

    return 0;
}


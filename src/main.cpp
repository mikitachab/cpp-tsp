#include <iostream>
#include <string>

#include "CostMatrix.hpp"
#include "TSPSolver.hpp"


void printResult(const TSPResult &result)
{
    std::cout << "cost: " << result.cost << std::endl;
    std::cout << "path: ";
    for (const auto &city : result.path)
    {
        std::cout << city << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    std::string fileName = "test-files/6_1.txt"; 
    if(argc >= 2){
        fileName = std::string(argv[1]);
    } 
    std::cout<<"matrix from: " << fileName << std::endl;

    CostMatrix matrix;

    try{
        matrix = readMatrixFromFile(fileName);
    }
    catch(std::invalid_argument &ia){
        std::cerr << "Matrix is invalid. Unaple to perform " << std::endl;
        exit(1);
    } 

    printMatrix(matrix);

    std::vector<int> path{1,2,3,4,5};
    std::cout<<calcPathCost(matrix, path)<<std::endl;
    
    TSPSolver solver = TSPSolver();
    TSPResult result = solver.solveBruteForce(matrix);
    std::cout<<result.cost<<std::endl;
    return 0;
}

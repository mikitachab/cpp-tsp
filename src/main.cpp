#include <iostream>
#include <string>

#include "CostMatrix.hpp"
#include "TSPSolver.hpp"
#include "TSPUtils.hpp"


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
    std::string fileName = "test-files/6_2.txt"; 
    if(argc >= 2){
        fileName = std::string(argv[1]);
    } 
    std::cout<<"matrix from: " << fileName << std::endl;

    CostMatrix* matrix = readMatrixFromFile(fileName);

    if (!matrix){
        std::cerr << "Matrix is invalid. Unaple to perform " << std::endl;
        exit(1);
    }
    matrix->print();
    TSPSolver solver;

    TSPResult result = solver.solveBruteForce(*matrix);
    printResult(result);

    return 0;
}

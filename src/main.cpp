#include "CostMatrix.hpp"
#include "TSPSolver.hpp"

#include <iostream>
#include <string>


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

void evaluateSolver(ITSPSolver* solver, CostMatrix &matrix){
    std::cout<<"evaluating " << solver->info()<<":"<<std::endl;
    std::cout<<"matrix size: "<< matrix.size()<<std::endl;
    TSPResult result = solver->solve(matrix);
    printResult(result);
}

int main(int argc, char *argv[])
{
    std::string fileName = "test-files/6_1.txt"; 
    if(argc >= 2)
    {
        fileName = std::string(argv[1]);
    }
    std::cout<<"matrix from: " << fileName << std::endl;

    CostMatrix matrix;

    try
    {
        matrix = readMatrixFromFile(fileName);
    }
    catch(std::invalid_argument &ia)
    {
        std::cerr << "Matrix is invalid. Unaple to solve" << std::endl;
        exit(1);
    } 

    printMatrix(matrix);

    ITSPSolver *bf = new  BruteForce();
    ITSPSolver *bb = new  BranchAndBound();

    evaluateSolver(bf, matrix);
    evaluateSolver(bb, matrix);

    return 0;
}

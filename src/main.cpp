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

int main()
{
    const std::string fileName = "test-files/6_2.txt"; //TODO read from command argumets

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

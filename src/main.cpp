#include <iostream>
#include <string>
#include "CostMatrix.h"
#include "TSPSolver.h"

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

    CostMatrix matrix;
    bool ok = matrix.readFromFile(fileName);
    if (!ok)
    {
        exit(1);
    }
    matrix.print();
    std::cout << std::endl;
    TSPSolver solver;
    TSPResult result;

    result = solver.solveBruteForce(matrix);
    printResult(result);

    return 0;
}

#include <iostream>
#include <string>
#include "CostMatrix.h"
#include "TSPSolver.h"

void printResult(const TSPResult &result)
{
    std::cout << "cost: " << result.cost << std::endl;
    std::cout << "path: ";
    for (auto city : result.path)
    {
        std::cout << city << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const std::string filename = "file.txt";

    CostMatrix matrix;
    matrix.readFromFile(filename);
    matrix.print();
    std::cout << std::endl;

    std::vector<int> path{1, 2, 3, 4, 5};

    TSPSolver solver;
    TSPResult *result;
    result = solver.solveBruteForce(matrix);
    printResult(*result);

    return 0;
}

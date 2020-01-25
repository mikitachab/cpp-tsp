#include"Utils.hpp"

std::vector<int> concat(const std::vector<int> a, const std::vector<int> b){
    std::vector<int> result(a);
    std::copy(b.begin(), b.end(), std::back_inserter(result));
    return result;
}
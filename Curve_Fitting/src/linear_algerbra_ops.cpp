#include <iostream>
#include <numeric>
#include <vector>

//Dot Product Matrix by Vector
double dot_produt(const std::vector<std::vector<int>> &e, const std::vector<float> &p)
{
    double result = 0;
    for (auto& v : e) 
        result += std::inner_product(v.begin(), v.end(), p.begin(), 0.0);
    return result;
}


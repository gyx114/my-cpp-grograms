#include "../my_stl/vector.hpp"
#include "../my_stl/sorts.hpp"
#include <iostream>
#include "sparse_matrix.hpp"
#include <vector>
#include <algorithm>

using namespace gyx;

int main()
{
    sparse_matrix<int> m1;
    sparse_matrix<int> m2;
    m1.reset(2, 4);
    m2.reset(4, 3);
    m1 *= m2;
    std::cout << m1;
}

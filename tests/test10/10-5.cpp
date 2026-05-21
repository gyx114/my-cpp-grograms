#include <iostream>
using namespace std;

// 使用递归直接计算排列数，避免计算大阶乘
template <unsigned M, unsigned N>
struct Permutation
{
    enum
    {
        VALUE = N * Permutation<M - 1, N - 1>::VALUE
    };
};

// 特化：P(0,N) = 1
template <unsigned N>
struct Permutation<0, N>
{
    enum
    {
        VALUE = 1
    };
};

int main()
{
    // P(3,25) = 25 × 24 × 23 = 13800
    cout << Permutation<3, 25>::VALUE << endl;
    return 0;
}

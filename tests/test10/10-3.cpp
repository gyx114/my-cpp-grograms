#include <iostream>
using namespace std;

template <unsigned N>
struct Power
{ // 类模板
    template <class T>
    static T value(T x)
    { // 函数模板
        return x * Power<N - 1>::value(x);
    }
};

template <>
struct Power<1>
{ // 特化 N=1
    template <class T>
    static T value(T x)
    {
        return x;
    }
};

template <unsigned N, class T>
inline T power(T v)
{ // 辅助函数模板
    return Power<N>::value(v);
}

int main()
{
    int v = Power<4>::value(2);
    cout << "2^4=" << v << endl;
    v = power<5>(3);
    cout << "3^5=" << v << endl;
}

#ifndef CALC_XOR_SUM
#define CALC_XOR_SUM

#include <iostream>
#include "../my_stl/my_list.hpp"

inline void calc_xor_sum(my_list<int> &lst)
{
    int ans = 0;
    my_list<int>::iterator it = lst.begin();
    for (size_t i = 0; i < lst.size(); i++)
    {
        ans += (i ^ *it);
        it++;
    }
    std::cout << ans << std::endl;
}

#endif

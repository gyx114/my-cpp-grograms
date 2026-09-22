#include "../my_stl/my_list.hpp"
#include <iostream>
#include "../my_stl/my_utils.hpp"
#include "../my_stl/my_vector.hpp"
#include "../my_stl/sorts.hpp"
#include "calc_xor_sum.hpp"

void solution_1()
{ // 先排序再建表
    int n, m;
    std::cin >> n >> m;
    my_vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        int n;
        std::cin >> n;
        v1.push_back(n);
    }
    my_vector<int> v2;
    for (int i = 0; i < m; i++)
    {
        int n;
        std::cin >> n;
        v2.push_back(n);
    }

    sorter obj_sorter;
    obj_sorter.insert_sort(v1.begin(), v1.end(), my_less<int>());
    obj_sorter.insert_sort(v2.begin(), v2.end(), my_less<int>());

    my_list<int> lst1;
    my_list<int> lst2;

    for (auto i : v1)
    {
        lst1.push_back(i);
    }
    calc_xor_sum(lst1);

    for (auto i : v2)
    {
        lst2.push_back(i);
    }
    calc_xor_sum(lst2);
}

void solution_2()
{
    // 先建表再排序
    int n, m;
    std::cin >> n >> m;
    my_list<int> lst1;
    my_list<int> lst2;
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        lst1.push_back(val);
    }
    lst1.sort();
    std::cout << lst1 << std::endl;

    for (int i = 0; i < m; i++)
    {
        int val;
        std::cin >> val;
        lst2.push_back(val);
    }
}

int main()
{
    solution_2();
}

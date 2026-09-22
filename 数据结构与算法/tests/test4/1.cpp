#include "../my_stl/my_list.hpp"
#include <iostream>
#include "calc_xor_sum.hpp"

#define INSERT 1
#define DELETE 2
#define REVERSE 3
#define INQUIRY 4
#define OUTPUT 5

void one_operation(my_list<int> &lst)
{
    int op;
    std::cin >> op;
    switch (op)
    {
    case INSERT:
    {
        int idx, val;
        std::cin >> idx >> val;
        auto it = lst.begin();
        for (int i = 0; i < idx; i++, it++)
        {
        }
        lst.insert(it, val);
        break;
    }

    case DELETE:
    {
        int val;
        std::cin >> val;
        my_list<int>::iterator it = lst.search(val);
        if (it == lst.end())
        {
            std::cout << "-1" << std::endl;
            return;
        }
        else
        {
            lst.erase(it);
        }
        break;
    }

    case REVERSE:
    {
        lst.reverse();
        break;
    }

    case INQUIRY:
    {
        int val;
        std::cin >> val;
        my_list<int>::iterator it = lst.begin();
        for (int i = 0; it != lst.end(); i++, it++)
        {
            if (*it == val)
            {
                std::cout << i << std::endl;
                return;
            }
        }
        std::cout << "-1" << std::endl;
        break;
    }

    case OUTPUT:
    {
        calc_xor_sum(lst);
        break;
    }

    default:
        break;
    }
}

int main()
{
    int n, q;
    std::cin >> n >> q;
    my_list<int> lst;
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        lst.push_back(val);
    }
    for (int i = 0; i < q; i++)
    {
        one_operation(lst);
    }
}

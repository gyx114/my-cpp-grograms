#include "../my_stl/sorts.hpp"
#include <iostream>
using namespace gyx;

int main()
{
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    less<int> less_int;
    sorter sorter_obj;
    sorter_obj.select_sort(arr, arr + n, less_int);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " \n"[i == n - 1];
    }
    delete[] arr;
}

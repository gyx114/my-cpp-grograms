#include "../my_stl/vector.hpp"
#include "../my_stl/sorts.hpp"
#include <iostream>
#include "sparse_matrix.hpp"

using namespace gyx;

#define RESET 1
#define MULTI 2
#define ADD 3
#define OUTPUT 4
#define ROTATE 5

void one_operation(sparse_matrix<int> &matrix)
{
    int op;
    std::cin >> op;
    switch (op)
    {
    case RESET:
    {
        int n, m;
        std::cin >> n >> m;
        matrix.reset(n, m);
        break;
    }
    case MULTI:
    {
        int n, m;
        std::cin >> n >> m;
        sparse_matrix<int> y(n, m);
        int t;
        std::cin >> t;
        for (int i = 0; i < t; i++)
        {
            int r, c, v;
            std::cin >> r >> c >> v;
            y.push_back_to_the_none_zero_table(r - 1, c - 1, v);
        }
        try
        {
            matrix *= y;
        }
        catch (const sparse_matrix<int>::SizeUnmatch &e)
        {
            matrix = move(y);
            std::cout << -1 << "\n";
        }
        break;
    }
    case ADD:
    {
        int n, m;
        std::cin >> n >> m;
        sparse_matrix<int> y(n, m);
        int t;
        std::cin >> t;
        for (int i = 0; i < t; i++)
        {
            int r, c, v;
            std::cin >> r >> c >> v;
            y.push_back_to_the_none_zero_table(r - 1, c - 1, v);
        }
        try
        {
            matrix += y;
        }
        catch (const sparse_matrix<int>::SizeUnmatch &e)
        {
            matrix = move(y);
            std::cout << -1 << "\n";
        }
        break;
    }

    case OUTPUT:
    {
        std::cout << matrix;
        break;
    }
    case ROTATE:
    {
        matrix.rotate();
        break;
    }

    default:
        break;
    }
}

int main()
{
    int w;
    std::cin >> w;
    sparse_matrix<int> matrix;
    for (int i = 0; i < w; i++)
    {
        one_operation(matrix);
    }
}

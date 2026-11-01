#include "../my_stl/BST.hpp"
#include <iostream>

using namespace gyx;

#define INSERT 0
#define FIND_VAL 1
#define ERASE_VAL 2
#define FIND_IDX 3
#define ERASE_IDX 4

void one_op(BST<int> &bst)
{
    int a;
    size_t b;
    std::cin >> a >> b;
    switch (a)
    {
    case INSERT:
        bst.insert(b, true);
        break;
    case FIND_VAL:
        bst.find(b, true);
        break;
    case ERASE_VAL:
        bst.erase(b, true);
        break;
    case FIND_IDX:
        bst.find_idx(b, true);
        break;
    case ERASE_IDX:
        bst.erase_idx(b, true);
        break;

    default:
        break;
    }
}

int main()
{
    BST<int> bst;
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        one_op(bst);
    }
}

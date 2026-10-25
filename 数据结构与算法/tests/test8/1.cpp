#include <iostream>
#include "../my_stl/binary_tree.hpp"

using namespace gyx;
int main()
{
    int n;
    std::cin >> n;
    binary_tree<int> bt(n); // 用int版的专属构造
    // 层序遍历
    bt.level_order([](binary_tree<int>::tree_node *nd) -> void
                   { std::cout << nd->value() << " "; });
    std::cout << "\n";

    // 子树节点数量
    vector<int> cnt_of_sub(n + 1, 1);
    bt.post_order([&cnt_of_sub](binary_tree<int>::tree_node *nd) -> void
                  {
                      cnt_of_sub[nd->value()] += (nd->left() ? cnt_of_sub[nd->left()->value()] : 0);
                      cnt_of_sub[nd->value()] += (nd->right() ? cnt_of_sub[nd->right()->value()] : 0); });
    for (int i = 1; i <= n; i++)
    {
        std::cout << cnt_of_sub[i] << " ";
    }
    std::cout << "\n";

    // 子树高度
    vector<int> height_of_sub(n + 1, 1);
    bt.post_order([&height_of_sub](binary_tree<int>::tree_node *nd) -> void
                  { height_of_sub[nd->value()] = 1 + max((nd->left() ? height_of_sub[nd->left()->value()] : 0), (nd->right() ? height_of_sub[nd->right()->value()] : 0)); });
    for (int i = 1; i <= n; i++)
    {
        std::cout << height_of_sub[i] << " ";
    }
    std::cout << "\n";
}

#include <iostream>
#include "../my_stl/binary_tree.hpp"
#include "../my_stl/vector.hpp"

using namespace gyx;
int main()
{
    int n;
    std::cin >> n;
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> pre[i];
    }
    vector<int> in(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> in[i];
    }

    binary_tree<int> bt(pre, in);

    bt.post_order([](auto x) -> void
                  { std::cout << x->value() << " "; });
    std::cout << "\n";
}

#include "../my_stl/undirected_graph.hpp"
using namespace gyx;
#include <iostream>

int main()
{
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    graph<No_weight> g(n);
    for (int i = 0; i < m; i++)
    {
        int op;
        int u, v;
        std::cin >> op >> u >> v;
        if (op == 0) // 加边
        {
            g.add_edge(u, v);
        }
        else
        {
            g.delete_edge(u, v);
        }
    }

    // 先求连通子图最小点
    auto v1 = g.min_represents_of_connected_subgrapgh();

    // 输出连通分量数
    std::cout << v1.size() << '\n';

    // 输出连通子图最小点
    for (auto i : v1)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 求s开始的字典序最小的dfs序列
    auto v2 = g.dfs(s, AscendingOrder{});

    // 输出dfs序列长度
    std::cout << v2.size() << '\n';

    // 输出dfs序列
    for (auto i : v2)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 求t开始的字典序最小的bfs序列
    auto v3 = g.bfs(t, AscendingOrder{});

    // 输出bfs序列长度
    std::cout << v3.size() << '\n';

    // 输出bfs序列
    for (auto i : v3)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 求s到t最短路径长度，不存在则输出-1
    auto v4 = g.min_path(s, t);
    if (v4.size())
    {
        std::cout << v4.size() - 1 << '\n';
    }
    else
    {
        std::cout << -1 << '\n';
    }
}

#include <iostream>
#include "../my_stl/sorts.hpp"
#include "../my_stl/disjoint_set.hpp"

using namespace gyx;
struct edge
{
    int from;
    int to;
    int weight;
};
int main()
{
    int n;
    std::cin >> n;
    int m;
    std::cin >> m;
    edge *edges = new edge[m];
    for (int i = 0; i < m; i++)
    {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    sorter ster;
    ster.quick_sort(edges, edges + m, [](const edge &a, const edge &b) -> bool
                    { return a.weight < b.weight; });

    int cnt = 0;
    long long sum = 0; // 不开longlong会溢出，WA
    disjoint_set ds(n);

    for (int i = 0; cnt < n - 1 && i < m; i++)
    {
        auto &e = edges[i];
        if (!ds.check(e.from, e.to))
        {
            cnt++;
            sum += e.weight;
            ds.unite(e.from, e.to);
        }
    }
    std::cout << (cnt == (n - 1) ? sum : -1) << '\n';
    delete[] edges;
}

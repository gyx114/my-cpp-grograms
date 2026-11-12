#include "../my_stl/vector.hpp"
#include "../my_stl/priority_queue.hpp"
#include "../my_stl/undirected_graph.hpp"
#include "../my_stl/disjoint_set.hpp"
#include <iostream>

using namespace gyx;

using edge = typename graph<int>::edge;
struct edge_greater
{
    bool operator()(const edge &a, const edge &b) const
    {
        return a.weight > b.weight;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    graph<int> g(n);
    disjoint_set ds(n);
    for (int i = 0; i < m; i++)
    {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        g.add_edge(from, to, weight);
    }

    vector<int> selected{1};

    priority_queue<edge, vector<edge>, edge_greater> pq(g.edges(1).begin(), g.edges(1).end());
    long long sum = 0;
    while (selected.size() < n && pq.size())
    {
        while (pq.size() && ds.check(1, pq.top().to))
        {
            pq.pop();
        }
        if (pq.size())
        {
            int t = pq.top().to;
            sum += pq.top().weight;
            pq.pop();
            selected.push_back(t);
            for (auto e : g.edges(t))
            {
                pq.push(e);
            }
            ds.unite(1, t);
        }
    }
    std::cout << sum << '\n';
}

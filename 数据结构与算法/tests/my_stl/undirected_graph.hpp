#ifndef GYX_MY_STL_UNDIRECTED_GRAPH_HPP
#define GYX_MY_STL_UNDIRECTED_GRAPH_HPP

#include <type_traits>
#include "list.hpp"
#include "vector.hpp"
#include "sorts.hpp"
#include "queue.hpp"

namespace gyx
{
    struct No_weight // 无权边
    {
    };

    // 几种选择策略，接收一个vector&，通过调整vector中数字的位置来实现特定顺序的遍历
    struct NaturalOrder // 原封不动
    {
        void operator()(vector<size_t> &) const {}
    };

    struct AscendingOrder // 升序排列vector，优先取序号小的节点
    {
        void operator()(vector<size_t> &v) const
        {
            sorter ster;
            ster.quick_sort(v.begin(), v.end(), less<>{});
        }
    };

    struct DescendingOrder // 降排列vector，优先取序号大的节点
    {
        void operator()(vector<size_t> &v) const
        {
            sorter ster;
            ster.quick_sort(v.begin(), v.end(), greater<>{});
        }
    };

    template <typename weight_type>
    class graph
    {
        /*
        使用邻接链表存储的无向图类
        点用数字代表，从1开始
        边包括有向边和无向边
        */
    public:
        struct edge // 边
        {
            size_t to;
            weight_type weight;

            template <typename T = weight_type, typename std::enable_if<std::is_same<T, No_weight>::value, int>::type = 0>
            edge(size_t t) : to(t), weight{} {} // 无权边构造

            template <typename T = weight_type, typename std::enable_if<!std::is_same<T, No_weight>::value, int>::type = 0>
            edge(size_t t, weight_type w) : to(t), weight(w) {} // 带权边构造

            template <typename T = weight_type, typename std::enable_if<std::is_same<T, No_weight>::value, int>::type = 0>
            bool operator==(const edge &other) const noexcept // 无权边比较
            {
                return to == other.to;
            }
            template <typename T = weight_type, typename std::enable_if<std::is_same<T, No_weight>::value, int>::type = 0>
            bool operator!=(const edge &other) const noexcept // 无权边比较
            {
                return to != other.to;
            }
        };

        static constexpr bool kWeighted = !std::is_same<weight_type, No_weight>::value;

    private:
        size_t n_;               // 顶点数
        vector<list<edge>> adj_; // 邻接表
        size_t edge_cnt_;        // 边数

        template <typename strategy>
        void dfs_impl(size_t cur_v, vector<size_t> &v_seq, strategy &&strtgy, vector<bool> &visited) const
        {
            v_seq.push_back(cur_v);
            visited[cur_v - 1] = true;
            vector<size_t> neighbors;
            neighbors.reserve(adj_[cur_v - 1].size());
            for (auto e : adj_[cur_v - 1])
            {
                if (!visited[e.to - 1])
                {
                    neighbors.push_back(e.to);
                }
            }
            strtgy(neighbors);
            for (auto i : neighbors)
            {
                if (!visited[i - 1])
                {
                    dfs_impl(i, v_seq, strtgy, visited);
                }
            }
        }

    public:
        explicit graph(size_t n) : n_(n), adj_(n), edge_cnt_(0) {}
        size_t VertexCount() const noexcept { return n_; }
        size_t EdgeCount() const noexcept { return edge_cnt_; }

        template <typename T = weight_type, typename std::enable_if<std::is_same<T, No_weight>::value, int>::type = 0>
        void add_edge(size_t u, size_t v) // 无权边版本,uv之间加一条边，要求调用者保证不能是重边，不能是自环，不能越界
        {
            adj_[u - 1].emplace_back(v);
            adj_[v - 1].emplace_back(u);
            edge_cnt_++;
        }
        template <typename T = weight_type, typename std::enable_if<!std::is_same<T, No_weight>::value, int>::type = 0>
        void add_edge(size_t u, size_t v, weight_type w) // 带权边版本,uv之间加一条边，要求调用者保证不能是重边，不能是自环，不能越界
        {
            adj_[u - 1].emplace_back(v, w);
            adj_[v - 1].emplace_back(u, w);
            edge_cnt_++;
        }

        template <typename T = weight_type, typename std::enable_if<std::is_same<T, No_weight>::value, int>::type = 0>
        void delete_edge(size_t u, size_t v) // 只给无权边版本提供，删掉uv之间的边，要求调用者保证不能越界
        {
            auto it1 = adj_[u - 1].search(edge(v));
            if (it1 != adj_[u - 1].end())
            {
                adj_[u - 1].erase(it1);
            }
            auto it2 = adj_[v - 1].search(edge(u));
            if (it2 != adj_[v - 1].end())
            {
                adj_[v - 1].erase(it2);
                edge_cnt_--;
            }
        }

        template <typename strategy>
        vector<size_t> dfs(size_t begin_v, strategy &&strtgy) const // 从begin_v开始dfs，以strtgy策略排序，返回遍历序列
        {
            vector<size_t> v_seq;
            v_seq.reserve(n_);
            vector<bool> visited(n_, false);
            dfs_impl(begin_v, v_seq, strtgy, visited);
            return v_seq;
        }

        template <typename strategy>
        vector<size_t> bfs(size_t begin_v, strategy &&strtgy) const // 从begin_v开始bfs，以strtgy策略排序，返回遍历序列
        {
            queue<size_t> q;
            q.push(begin_v);
            vector<bool> visited(n_, false);
            vector<size_t> v_seq;
            v_seq.reserve(n_);
            while (!q.empty())
            {
                size_t cur_v = q.front();
                q.pop();
                if (!visited[cur_v - 1])
                {
                    visited[cur_v - 1] = true;
                    v_seq.push_back(cur_v);
                    vector<size_t> neighbors;
                    neighbors.reserve(adj_[cur_v - 1].size());
                    for (auto e : adj_[cur_v - 1])
                    {
                        if (!visited[e.to - 1])
                        {
                            neighbors.push_back(e.to);
                        }
                    }
                    strtgy(neighbors);
                    for (auto i : neighbors)
                    {
                        q.push(i);
                    }
                }
            }
            return v_seq;
        }

        size_t cnt_of_connected_components() const // 连通分量数
        {
            vector<bool> visited(n_);
            size_t cnt = 0;
            for (size_t i = 1; i <= n_; i++)
            {
                if (!visited[i - 1])
                {
                    cnt++;
                    auto seq = dfs(i, NaturalOrder{});
                    for (auto x : seq)
                    {
                        visited[x - 1] = true;
                    }
                }
            }
            return cnt;
        }

        vector<size_t> min_represents_of_connected_subgrapgh() const // 返回每个连通子图中的最小元素，升序排列
        {
            vector<bool> visited(n_, false);
            vector<size_t> ret;
            for (size_t i = 1; i <= n_; i++)
            {
                if (!visited[i - 1])
                {
                    ret.push_back(i);
                    auto seq = dfs(i, NaturalOrder{});
                    for (auto x : seq)
                    {
                        visited[x - 1] = true;
                    }
                }
            }
            return ret;
        }

        template <typename T = weight_type, typename std::enable_if<std::is_same<T, No_weight>::value, int>::type = 0>
        vector<size_t> min_path(size_t u, size_t v) // 只给无权边版本提供，输出u到v的最短路径。不存在则返回空数组
        {
            if (u == v)
            {
                return vector<size_t>{u};
            }
            vector<size_t> ret;
            queue<size_t> q;
            vector<size_t> prev(n_, 0); // 遍历时每个顶点最早的前驱顶点，0表示还没有前驱。用于倒推路径
            q.push(u);
            while (!q.empty())
            {
                size_t cur_v = q.front();
                q.pop();
                for (auto e : adj_[cur_v - 1])
                {
                    size_t child = e.to;
                    if (child != u /*u没有prev，需要特判*/ && !prev[child - 1]) // 没visit
                    {
                        prev[child - 1] = cur_v;
                        q.push(child);
                    }
                    if (child == v) // 找到了
                    {
                        size_t tmp = child;
                        while (tmp) // u的prev是0，自然结束
                        {
                            ret.push_back(tmp);
                            tmp = prev[tmp - 1];
                        }
                        ret.reverse();
                        return ret;
                    }
                }
            }
            return ret;
        }
    };
} // namespace gyx

#endif

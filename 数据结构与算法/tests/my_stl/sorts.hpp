#ifndef SORTS_HPP
#define SORTS_HPP

// 去引用
template <typename T>
struct RemoveRef
{
    using type = T;
};

template <typename T>
struct RemoveRef<T &>
{
    using type = T;
};

template <typename T>
struct RemoveRef<T &&>
{
    using type = T;
};

template <typename T>
void my_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

class sorter // 排序类，提供名次排序、及时终止的选择排序、及时终止的冒泡排序、插入排序操作
{
private:
    // 选择
    template <typename random_it_type, typename cmp_type>
    int select(random_it_type begin, random_it_type end, cmp_type cmp, int cnt_of_sorted)
    // 返回目前最大的数的下标，如果已排序好，返回-91
    {
        int n = end - begin;
        bool is_sorted = true;
        int idx_selected = 0;
        for (int i = 1; i < n - cnt_of_sorted; i++)
        {
            if (!cmp(*(begin + i), *(begin + idx_selected)))
            {
                idx_selected = i;
            }
            else
            {
                is_sorted = false;
            }
        }
        return is_sorted ? -91 : idx_selected;
    }

public:
    // 名次排序(即计数排序)
    template <typename random_it_type, typename cmp_type>
    void rank_sort(random_it_type begin, random_it_type end, cmp_type cmp)
    {
        int n = end - begin;
        using elem_type = typename RemoveRef<decltype(*begin)>::type;
        int *rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
        }
        // 算rank
        for (auto it1 = begin; it1 != end; it1++)
        {
            for (auto it2 = begin; it2 != it1; it2++)
            {
                if (cmp(*it1, *it2))
                {
                    rank[it2 - begin]++;
                }
                else
                {
                    rank[it1 - begin]++;
                }
            }
        }
        // 根据rank排序
        elem_type *sorted = new elem_type[n];
        for (int i = 0; i < n; i++)
        {
            sorted[rank[i]] = *(begin + i);
        }

        // 覆盖原数组
        for (int i = 0; i < n; i++)
        {
            *(begin + i) = sorted[i];
        }

        // 释放内存
        delete[] rank;
        delete[] sorted;
    }

    // 及时终止的选择排序
    template <typename random_it_type, typename cmp_type>
    void select_sort(random_it_type begin, random_it_type end, cmp_type cmp)
    {
        int n = end - begin;
        int cnt_of_sorted = 0;
        while (cnt_of_sorted < n)
        {
            int idx_of_selected = select(begin, end, cmp, cnt_of_sorted);
            if (idx_of_selected >= 0)
            {
                my_swap(*(begin + idx_of_selected), *(begin + n - 1 - cnt_of_sorted));
                cnt_of_sorted++;
            }
            else
            {
                // 有序，及时退出
                return;
            }
        }
    }

    // 及时终止的冒泡排序
    template <typename random_it_type, typename cmp_type>
    void bubble_sort(random_it_type begin, random_it_type end, cmp_type cmp)
    {
        int n = end - begin;
        for (int i = 0; i < n; i++)
        {
            bool is_sorted = true;
            for (int j = 1; j < n - i; j++)
            {
                if (cmp(*(begin + j), *(begin + j - 1)))
                {
                    my_swap(*(begin + j), *(begin + j - 1));
                    is_sorted = false;
                }
            }
            if (is_sorted)
            {
                return;
            }
        }
    }

    // 插入排序
    template <typename random_it_type, typename cmp_type>
    void insert_sort(random_it_type begin, random_it_type end, cmp_type cmp)
    {
        int n = end - begin;
        for (int i = 1; i < n; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                if (cmp(*(begin + j), *(begin + j - 1)))
                {
                    my_swap(*(begin + j), *(begin + j - 1));
                }
                else
                {
                    break;
                }
            }
        }
    }
};

#endif

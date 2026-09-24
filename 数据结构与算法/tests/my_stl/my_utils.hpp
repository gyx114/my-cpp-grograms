#ifndef MY_UTILS
#define MY_UTILS
#include <utility>

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
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template <typename T>
class my_less
{
public:
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <typename T>
class my_greater
{
public:
    bool operator()(const T &a, const T &b) const
    {
        return a > b;
    }
};

#endif

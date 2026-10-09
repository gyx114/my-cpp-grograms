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

template <typename T = void>
struct my_less
{
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

// 对void版本特化
template <>
struct my_less<void>
{
    template <typename T, typename U>
    constexpr auto operator()(T &&a, U &&b) const -> decltype(std::forward<T>(a) < std::forward<U>(b))
    {
        return std::forward<T>(a) < std::forward<U>(b);
    }
};

template <typename T = void>
struct my_greater
{
    bool operator()(const T &a, const T &b) const
    {
        return a > b;
    }
};

// 对void版本特化
template <>
struct my_greater<void>
{
    template <typename T, typename U>
    constexpr auto operator()(T &&a, U &&b) const -> decltype(std::forward<T>(a) > std::forward<U>(b))
    {
        return std::forward<T>(a) > std::forward<U>(b);
    }
};

#endif

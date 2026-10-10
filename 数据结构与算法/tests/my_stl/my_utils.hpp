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
constexpr typename RemoveRef<T>::type &&my_move(T &&val) noexcept
{
    return static_cast<typename RemoveRef<T>::type &&>(val);
}

template <typename T>
void my_swap(T &a, T &b)
{
    T tmp = my_move(a);
    a = my_move(b);
    b = my_move(tmp);
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

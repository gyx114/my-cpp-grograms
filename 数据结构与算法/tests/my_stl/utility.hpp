#ifndef GYX_MY_STL_UTILITY_HPP
#define GYX_MY_STL_UTILITY_HPP

#include <utility>

namespace gyx
{
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
    constexpr typename RemoveRef<T>::type &&move(T &&val) noexcept
    {
        return static_cast<typename RemoveRef<T>::type &&>(val);
    }

    template <typename T>
    void swap(T &a, T &b)
    {
        T tmp = move(a);
        a = move(b);
        b = move(tmp);
    }

    template <typename T = void>
    struct less
    {
        bool operator()(const T &a, const T &b) const
        {
            return a < b;
        }
    };

    // 对void版本特化
    template <>
    struct less<void>
    {
        template <typename T, typename U>
        constexpr auto operator()(T &&a, U &&b) const -> decltype(std::forward<T>(a) < std::forward<U>(b))
        {
            return std::forward<T>(a) < std::forward<U>(b);
        }
    };

    template <typename T = void>
    struct greater
    {
        bool operator()(const T &a, const T &b) const
        {
            return a > b;
        }
    };

    // 对void版本特化
    template <>
    struct greater<void>
    {
        template <typename T, typename U>
        constexpr auto operator()(T &&a, U &&b) const -> decltype(std::forward<T>(a) > std::forward<U>(b))
        {
            return std::forward<T>(a) > std::forward<U>(b);
        }
    };

} // namespace gyx

#endif

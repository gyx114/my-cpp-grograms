#ifndef GYX_MY_STL_PAIR_HPP
#define GYX_MY_STL_PAIR_HPP

namespace gyx
{
    template <typename T, typename U>
    struct pair
    {
        T first;
        U second;

        pair() : first(), second() {}
        ~pair() {}

        pair(const T &f, const U &s) : first(f), second(s) {}
        pair(const pair &other) : first(other.first), second(other.second) {}
        pair(pair &&other) noexcept : first(move(other.first)), second(move(other.second)) {}

        pair &operator=(const pair &other)
        {
            if (this != &other)
            {
                first = other.first;
                second = other.second;
            }
            return *this;
        }
        pair &operator=(pair &&other) noexcept
        {
            if (this != &other)
            {
                first = move(other.first);
                second = move(other.second);
            }
            return *this;
        }

        template <typename X, typename Y>
        pair(const X &x, const Y &y) : first(x), second(y) {}

        constexpr bool operator==(const pair &other)
        {
            return first == other.first && second == other.second;
        }

        constexpr bool operator<(const pair &other)
        {
            return (first < other.first) || (first == other.first && second < other.second);
        }
    };

} // namespace gyx

#endif

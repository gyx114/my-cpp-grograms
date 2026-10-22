#ifndef GYX_MY_STL_ITERATOR_HPP
#define GYX_MY_STL_ITERATOR_HPP

#include <type_traits>
#include <utility>

namespace gyx
{
    namespace detail
    {
        template <typename...>
        struct make_void
        {
            using type = void;
        };

        template <typename... Ts>
        using void_t = typename make_void<Ts...>::type;

        template <typename It, typename = void>
        struct is_input_iterator : std::false_type
        {
        };

        template <typename It>
        struct is_input_iterator<It, void_t<
                                         decltype(++std::declval<It &>()),
                                         decltype(std::declval<It &>()++),
                                         decltype(*std::declval<It &>()),
                                         decltype(std::declval<It &>() != std::declval<It &>())>>
            : std::true_type
        {
        };
    }
}

#endif

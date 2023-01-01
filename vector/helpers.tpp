//
// Created by Hamza Chakoubi on 12/31/22.
//

#ifndef FT_CONTAINERS_HELPERS_TPP
#define FT_CONTAINERS_HELPERS_TPP

namespace ft
{
    struct true_type{static const bool value = true;};
    struct false_type{static const bool value = false;};

    template<typename T>
    struct is_integral : public false_type{};

    template<>
    struct is_integral<int> : public true_type{};

    template<>
    struct is_integral<char> : public true_type{};

    template<bool, typename T = void()>
    struct enable_if {};

    template<typename T>
    struct enable_if<true, T> {typedef T type;};

}

#endif //FT_CONTAINERS_HELPERS_TPP

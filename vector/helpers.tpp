//
// Created by Hamza Chakoubi on 12/31/22.
//

#ifndef FT_CONTAINERS_HELPERS_TPP
#define FT_CONTAINERS_HELPERS_TPP
#include  <cstddef>
namespace ft
{
    template<typename T>
    size_t distance(T& begin, T& end)
    {
        size_t counter;
        counter = 0;

        for(T it = begin; it != end; it++)
            counter++;
        return counter;
    }


    struct true_type{static const bool value = true;};
    struct false_type{static const bool value = false;};

    template<typename T>
    struct is_integral : public false_type{};

    template<>
    struct is_integral<bool> : public true_type{};

    template<>
    struct is_integral<char> : public true_type{};

    template<>
    struct is_integral<char16_t> : public true_type{};

    template<>
    struct is_integral<char32_t> : public true_type{};

    template<>
    struct is_integral<wchar_t> : public true_type{};

    template<>
    struct is_integral<signed char> : public true_type{};

    template<>
    struct is_integral<short int> : public true_type{};

    template<>
    struct is_integral<int> : public true_type{};

    template<>
    struct is_integral<long int> : public true_type{};

    template<>
    struct is_integral<long long int> : public true_type{};

    template<>
    struct is_integral<unsigned char> : public true_type{};

    template<>
    struct is_integral<unsigned short int> : public true_type{};

    template<>
    struct is_integral<unsigned int> : public true_type{};

    template<>
    struct is_integral<unsigned long int> : public true_type{};

    template<>
    struct is_integral<unsigned long long int> : public true_type{};


    template<bool, typename T = void()>
    struct enable_if {};

    template<typename T>
    struct enable_if<true, T> {typedef T type;};

}

#endif //FT_CONTAINERS_HELPERS_TPP

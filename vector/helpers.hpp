//
// Created by Hamza Chakoubi on 12/31/22.
//

#ifndef FT_CONTAINERS_HELPERS_TPP
#define FT_CONTAINERS_HELPERS_TPP
#include  <cstddef>
#include <iterator>
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
    
    template< class BidirIt1, class BidirIt2 >
    BidirIt2 copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last)
    {
      while (first != last) {
          *(--d_last) = *(--last);
      }
      return d_last;
    }

    struct true_type{static const bool value = true;};
    struct false_type{static const bool value = false;};

    template<typename T>
    struct is_integral : public false_type{};

    template<>
    struct is_integral<bool> : public true_type{};

    template<>
    struct is_integral<char> : public true_type{};

    // template<>
    // struct is_integral<char16_t> : public true_type{};

    // template<>
    // struct is_integral<char32_t> : public true_type{};

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


/*
* helper function to check if iterator is random access tagged
*/
    template <class Iterator> 
    struct is_input_iterator_tagged {
      static const bool value = false;
    };

    template <>
    struct is_input_iterator_tagged<std::input_iterator_tag> {
      static const bool value = true;
    };

/*
 * is_ft to check if vector is ft::vector or not
 */

template<class Type>
struct is_std : public true_type{};

// template<class Type>
// struct is_std<std::vector<Type> > : public false_type{};


/*
* helper function that return the min of two numbers
*/
    template <class T, class U> size_t min(T a, U b) {
      size_t x = static_cast<size_t>(a);
      size_t y = static_cast<size_t>(b);
      return (x > y ? y : x);
    }
}

#endif //FT_CONTAINERS_HELPERS_TPP

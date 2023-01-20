#ifndef ITERATOR_TRAITS
#define ITERATOR_TRAITS

#include <cstddef>
#include <stddef.h>
#include <iterator>

struct random_access_iterator_tag {};

template<class T>
struct iterator_traits {

  typedef typename T::difference_type difference_type;
  typedef typename T::value_type value_type;
  typedef typename T::pointer pointer;
  typedef typename T::reference reference;
  typedef typename T::iterator_category iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef random_access_iterator_tag iterator_category;
};

template<class T>
struct iterator_traits<const T*>
{
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef random_access_iterator_tag iterator_category;
};
#endif // !DEBUG

#ifndef ITERATOR_TRAITS
#define ITERATOR_TRAITS

#include <cstddef>
#include <stddef.h>

struct random_access_iterator_tag {};

template<class T>
struct iterator_traits {

  typedef typename T::ptrdiff_t difference_type;
  typedef typename T::value_type value_type;
  typedef typename T::pointer pointer;
  typedef typename T::reference reference;
  typedef typename T::iiterator_category iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
  typedef
};

#endif // !DEBUG

//
// Created by Hamza Chakoubi on 12/19/22.
//

#ifndef FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
template<typename T>
class reverse_iterator
{
    
public:
     // memer types
    typedef T iterator_type;
    typedef typename iterator_traits<T>::iterator_catorgory iterator_catorgory;
    typedef typename iterator_traits<T>::value_type value_type;
    typedef typename iterator_traits<T>::difference_type difference_type;
    typedef typename iterator_traits<T>::pointer pointer;
    typedef typename iterator_traits<T>::reference reference;


  // memeber functions
   reverse_iterator();
   reverse_iterator(iterator_type it);
   reverse_iterator(const reverse_iterator& it);
   reverse_iterator &operator=(reverse_iterator& rev_it);
   ~reverse_iterator();
    iterator_type base();
private:
  // data members
  pointer _it;
};

template<class T>
reverse_iterator<T>::reverse_iterator(): _it()
{
}

template<class T>
reverse_iterator<T>::~reverse_iterator()
{
  if (this->_it)
    delete this->_it;
}

template<class T>
reverse_iterator<T>::reverse_iterator(iterator_type it): _it(it)
{}

template<class T>
reverse_iterator<T>::reverse_iterator(const reverse_iterator<T>& rev_it): _it(rev_it._it)
{}


template<class T>
typename reverse_iterator<T>::iterator_type base()
{
  typename reverse_iterator<T>::pointer  it = new reverse_iterator<T>();
  return *it;
}
#endif //FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

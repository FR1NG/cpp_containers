//
// Created by Hamza Chakoubi on 12/19/22.
//

#ifndef FT_CONTAINERS_VECTOR_iterator_HPP
#define FT_CONTAINERS_VECTOR_iterator_HPP

#include "iterator_traits.hpp"

namespace ft {

template <typename Iterator> class iterator {

public:
  // memer types
  typedef Iterator iterator_type;
  typedef typename  ft::iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename  ft::iterator_traits<Iterator>::value_type value_type;
  typedef typename  ft::iterator_traits<Iterator>::difference_type difference_type;
  typedef typename  ft::iterator_traits<Iterator>::pointer pointer;
  typedef typename  ft::iterator_traits<Iterator>::reference reference;

  // memeber functions
  iterator(): _it(nullptr){}

  explicit iterator(Iterator it):_it(it){}

  template <class Iter> iterator (const iterator<Iter>& it): _it(it.base()){}

  ~iterator(){}

  iterator_type base() const {
    return this->_it;
  }

  // overloading operators
  template< class Iter >
  iterator& operator=( const  iterator<Iter>& it )
  {
    this->_it = it.base();
    return *this;
  }

  reference operator*() { 
    return (*_it);
  }

  const reference operator*() const { 
    return (*_it);
  }

   iterator operator+(difference_type n) const {
    return iterator(this->_it + n);
  }

   iterator operator++() {
    this->_it++;
    return *this;
  }

   iterator operator++(int) {
     iterator tmp  = *this;
    ++(*this);
    return tmp;
  }

   iterator operator+=(difference_type n)
  {
    this->_it += n;
    return (*this);
  }

   iterator operator-(difference_type n) const {
    return iterator(this->_it - n);
  }

  iterator &operator--() {
    this->_it--;
    return (*this);
  }

   iterator operator--(int) {
     iterator tmp = *this;
    --(*this);
    return tmp;
  }

   iterator &operator-=(difference_type n) {
    this->_it = this->_it - n;
    return (*this);
  }

  pointer operator->() { return &(operator*()); }

  const pointer operator->() const { return &(operator*()); }

  reference operator[](difference_type n) const { return this->_it[n]; }

private:
  // data members
  iterator_type _it;



// relational operators
template<class Iterator1, class Iterator2>
friend bool operator==(const  iterator<Iterator1> &lhs,
                const  iterator<Iterator2> &rhs) {
  return lhs.base() == rhs.base();
}

template<class Iterator1, class Iterator2>
friend bool operator!=(const  iterator<Iterator1> &lhs,
                const  iterator<Iterator2> &rhs) {
  return lhs.base() != rhs.base();
}

template<class Iterator1, class Iterator2>
friend bool operator<(const  iterator<Iterator1> &lhs,
               const  iterator<Iterator2> &rhs) {
  return lhs.base() < rhs.base();
}

template<class Iterator1, class Iterator2>
friend bool operator<=(const  iterator<Iterator1> &lhs,
                const  iterator<Iterator2> &rhs) {
  return lhs.base() <= rhs.base();
}

template<class Iterator1, class Iterator2>
friend bool operator>(const  iterator<Iterator1> &lhs,
               const  iterator<Iterator2> &rhs) {
  return lhs.base() > rhs.base();
}

template<class Iterator1, class Iterator2>
friend bool operator>=(const  iterator<Iterator1> &lhs,
                const  iterator<Iterator2> &rhs) {
  return lhs.base() >= rhs.base();
}

//template<class Iterator1>
friend iterator operator+(typename  iterator::difference_type n,
          const  iterator &it) {
  return iterator(it + n);
}

template <class It>
 friend typename iterator<It>::difference_type operator- (    const iterator<It>& lhs,    const iterator<It>& rhs)
{
    return  lhs.base() - rhs.base();
}

}; // class iterator

} // namespace ft
#endif // FT_CONTAINERS_VECTOR_iterator_HPP

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
    return iterator(this->_it + n);
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

  pointer operator->() const { return &(operator*()); }

  reference operator[](difference_type n) const { return this->_it[n]; }

private:
  // data members
  iterator_type _it;
}; // class iterator

// relational operators

template <class Iterator>
bool operator==(const  iterator<Iterator> &lhs,
                const  iterator<Iterator> &rhs) {
  return lhs.base() == rhs.base();
}

template <class Iterator>
bool operator!=(const  iterator<Iterator> &lhs,
                const  iterator<Iterator> &rhs) {
  return lhs.base() != rhs.base();
}

template <class Iterator>
bool operator<(const  iterator<Iterator> &lhs,
               const  iterator<Iterator> &rhs) {
  return lhs.base() < rhs.base();
}

template <class Iterator>
bool operator<=(const  iterator<Iterator> &lhs,
                const  iterator<Iterator> &rhs) {
  return lhs.base() <= rhs.base();
}

template <class Iterator>
bool operator>(const  iterator<Iterator> &lhs,
               const  iterator<Iterator> &rhs) {
  return lhs.base() > rhs.base();
}

template <class Iterator>
bool operator>=(const  iterator<Iterator> &lhs,
                const  iterator<Iterator> &rhs) {
  return lhs.base() >= rhs.base();
}

template <class Iterator>
iterator<Iterator>
operator+(typename  iterator<Iterator>::difference_type n,
          const  iterator<Iterator> &rev_it) {
  return rev_it + n;
}

template <class Iterator>
typename  iterator<Iterator>::difference_type
operator-(const  iterator<Iterator> &lhs,
          const  iterator<Iterator> &rhs) {
  return rhs.base() - lhs.base();
}
} // namespace ft
#endif // FT_CONTAINERS_VECTOR_iterator_HPP

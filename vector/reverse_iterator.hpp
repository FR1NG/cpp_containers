
//
// Created by Hamza Chakoubi on 12/19/22.
//

#ifndef FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <typename Iterator> class reverse_iterator {

public:
  // memer types
  typedef Iterator iterator_type;
  typedef typename  ft::iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename  ft::iterator_traits<Iterator>::value_type value_type;
  typedef typename  ft::iterator_traits<Iterator>::difference_type difference_type;
  typedef typename  ft::iterator_traits<Iterator>::pointer pointer;
  typedef typename  ft::iterator_traits<Iterator>::reference reference;

  // memeber functions
  reverse_iterator(): _it(nullptr){}

  explicit reverse_iterator(Iterator it):_it(it){}

  template <class Iter> reverse_iterator (const reverse_iterator<Iter>& it): _it(it.base()){}

  ~reverse_iterator(){}

  iterator_type base() const {
    iterator_type it = this->_it;
    it--;
    return it;
  }

  // overloading operators
  template< class Iter >
  reverse_iterator& operator=( const  reverse_iterator<Iter>& it )
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

   reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(this->_it - n);
  }

    reverse_iterator operator++() {
    this->_it--;
    return *this;
  }

    reverse_iterator operator++(int) {
     reverse_iterator tmp  = *this;
    ++(*this);
    return tmp;
  }

    reverse_iterator operator+=(difference_type n)
  {
    this->_it -= n;
    return (*this);
  }

    reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(this->_it + n);
  }

   reverse_iterator &operator--() {
    this->_it++;
    return (*this);
  }

    reverse_iterator operator--(int) {
     reverse_iterator tmp = *this;
    --(*this);
    return tmp;
  }

    reverse_iterator &operator-=(difference_type n) {
    this->_it = this->_it + n;
    return (*this);
  }

  pointer operator->() const { return &(operator*()); }

  reference operator[](difference_type n) const { return this->_it[n]; }

private:
  // data members
  iterator_type _it;



// relational operators

// friend bool operator==(const   reverse_iterator<Iterator> &lhs,
//                 const   reverse_iterator<Iterator> &rhs) {
//   return lhs.base() == rhs.base();
// }

// friend bool operator!=(const   reverse_iterator<Iterator> &lhs,
//                 const   reverse_iterator<Iterator> &rhs) {
//   return lhs.base() != rhs.base();
// }

// friend bool operator<(const  reverse_iterator<Iterator> &lhs,
//                const  reverse_iterator<Iterator> &rhs) {
//   return lhs.base() < rhs.base();
// }

// friend bool operator<=(const  reverse_iterator<Iterator> &lhs,
//                 const  reverse_iterator<Iterator> &rhs) {
//   return lhs.base() <= rhs.base();
// }

// friend bool operator>(const  reverse_iterator<Iterator> &lhs,
//                const  reverse_iterator<Iterator> &rhs) {
//   return lhs.base() > rhs.base();
// }

// friend bool operator>=(const  reverse_iterator<Iterator> &lhs,
//                 const  reverse_iterator<Iterator> &rhs) {
//   return lhs.base() >= rhs.base();
// }

// friend reverse_iterator<Iterator> operator+(typename  reverse_iterator<Iterator>::difference_type n,
//           const  reverse_iterator<Iterator> &rev_it) {
//   return rev_it + n;
// }

// friend typename  reverse_iterator<Iterator>::difference_type operator-(const  reverse_iterator<Iterator> &lhs,
//           const  reverse_iterator<Iterator> &rhs) {
//   return rhs.base() - lhs.base();
// }
}; // class iterator

} // namespace ft
#endif // FT_CONTAINERS_VECTOR_iterator_HPP

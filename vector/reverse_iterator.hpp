//
// Created by Hamza Chakoubi on 12/19/22.
//

#ifndef FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <typename T> class reverse_iterator {

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
  reverse_iterator(const reverse_iterator &it);
  reverse_iterator &operator=(reverse_iterator &rev_it);
  ~reverse_iterator();
  iterator_type base() {
    iterator_type tmp = this->_it;
    tmp--;
    return tmp;
  }
  // overloading operators
  reference operator*() const { return *(this->_it); }

  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator<T>(this->_it - n);
  }

  reverse_iterator &operator++() {
    this->_it--;
    return *this;
  }
  reverse_iterator &operator++(int) {
    reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator<T>(this->_it + n);
  }

  reverse_iterator &operator--() {
    this->_it++;
    return (*this);
  }

  reverse_iterator &operator--(int) {
    reverse_iterator tmp = *this;
    --(*this);
    return tmp;
  }

  reverse_iterator &operator-=(difference_type n) {
    this->_it = this->_it + n;
    return (*this);
  }

  pointer operator->() const { return &(operator*()); }

  reference operator[](difference_type n) const { return this->_it[-n - 1]; }

private:
  // data members
  pointer _it;
};

template <class T> reverse_iterator<T>::reverse_iterator() : _it() {}

template <class T> reverse_iterator<T>::~reverse_iterator() {
  if (this->_it)
    delete this->_it;
}

template <class T>
reverse_iterator<T>::reverse_iterator(iterator_type it) : _it(it) {}

template <class T>
reverse_iterator<T>::reverse_iterator(const reverse_iterator<T> &rev_it)
    : _it(rev_it._it) {}

template <class T> typename reverse_iterator<T>::iterator_type base() {
  typename reverse_iterator<T>::pointer it = new reverse_iterator<T>();
  return *it;
}

// relational operators

template <class Iterator>
bool operator==(const reverse_iterator<Iterator> &lhs,
                const reverse_iterator<Iterator> &rhs) {
  return lhs.base() == rhs.base();
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator> &lhs,
                const reverse_iterator<Iterator> &rhs) {
  return lhs.base() != rhs.base();
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator> &lhs,
               const reverse_iterator<Iterator> &rhs) {
  return lhs.base() < rhs.base();
}

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator> &lhs,
                const reverse_iterator<Iterator> &rhs) {
  return lhs.base() <= rhs.base();
}

template <class Iterator>
bool operator>(const reverse_iterator<Iterator> &lhs,
               const reverse_iterator<Iterator> &rhs) {
  return lhs.base() > rhs.base();
}

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator> &lhs,
                const reverse_iterator<Iterator> &rhs) {
  return lhs.base() >= rhs.base();
}

template <class Iterator>
reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n,
          const reverse_iterator<Iterator> &rev_it) {
  return rev_it + n;
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type
operator-(const reverse_iterator<Iterator> &lhs,
          const reverse_iterator<Iterator> &rhs) {
  return rhs.base() - lhs.base();
}
} // namespace ft
#endif // FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

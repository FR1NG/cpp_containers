//
// Created by Hamza Chakoubi on 12/19/22.
//

#ifndef FT_CONTAINERS_VECTOR_iterator_HPP
#define FT_CONTAINERS_VECTOR_iterator_HPP

#include "iterator_traits.hpp"

namespace ft {

template <typename T> class iterator {

public:
  // memer types
  typedef T iterator_type;
  typedef typename iterator_traits<T>::iterator_category iterator_category;
  typedef typename iterator_traits<T>::value_type value_type;
  typedef typename iterator_traits<T>::difference_type difference_type;
  typedef typename iterator_traits<T>::pointer pointer;
  typedef typename iterator_traits<T>::reference reference;

  // memeber functions
  iterator();
  iterator(iterator_type it);
  iterator(const iterator &it);
  iterator &operator=(iterator &rev_it);
  ~iterator();
  iterator_type base() {
    iterator_type tmp = this->_it;
    tmp--;
    return tmp;
  }
  // overloading operators
  reference operator*() const { return *(this->_it); }

  iterator operator+(difference_type n) const {
    return iterator<T>(this->_it - n);
  }

  iterator operator++() {
    this->_it--;
    return *this;
  }
  iterator operator++(int) {
    iterator tmp  = *this;
    ++(*this);
    return tmp;
  }

  iterator operator-(difference_type n) const {
    return iterator<T>(this->_it + n);
  }

  iterator &operator--() {
    this->_it++;
    return (*this);
  }

  iterator operator--(int) {
    iterator tmp = *this;
    --(*this);
    return tmp;
  }

  iterator &operator-=(difference_type n) {
    this->_it = this->_it + n;
    return (*this);
  }

  pointer operator->() const { return &(operator*()); }

  reference operator[](difference_type n) const { return this->_it[-n - 1]; }

private:
  // data members
  pointer _it;
};

template <class T> iterator<T>::iterator() : _it() {}

template <class T> iterator<T>::~iterator() {
}

template <class T>
iterator<T>::iterator(iterator_type it) : _it(it) {}

template <class T>
iterator<T>::iterator(const iterator<T> &rev_it)
    : _it(rev_it._it) {}

template <class T> typename iterator<T>::iterator_type base() {
  typename iterator<T>::pointer it = new iterator<T>();
  return *it;
}

// relational operators

template <class Iterator>
bool operator==(const iterator<Iterator> &lhs,
                const iterator<Iterator> &rhs) {
  return lhs.base() == rhs.base();
}

template <class Iterator>
bool operator!=(const iterator<Iterator> &lhs,
                const iterator<Iterator> &rhs) {
  return lhs.base() != rhs.base();
}

template <class Iterator>
bool operator<(const iterator<Iterator> &lhs,
               const iterator<Iterator> &rhs) {
  return lhs.base() < rhs.base();
}

template <class Iterator>
bool operator<=(const iterator<Iterator> &lhs,
                const iterator<Iterator> &rhs) {
  return lhs.base() <= rhs.base();
}

template <class Iterator>
bool operator>(const iterator<Iterator> &lhs,
               const iterator<Iterator> &rhs) {
  return lhs.base() > rhs.base();
}

template <class Iterator>
bool operator>=(const iterator<Iterator> &lhs,
                const iterator<Iterator> &rhs) {
  return lhs.base() >= rhs.base();
}

template <class Iterator>
iterator<Iterator>
operator+(typename iterator<Iterator>::difference_type n,
          const iterator<Iterator> &rev_it) {
  return rev_it + n;
}

template <class Iterator>
typename iterator<Iterator>::difference_type
operator-(const iterator<Iterator> &lhs,
          const iterator<Iterator> &rhs) {
  return rhs.base() - lhs.base();
}
} // namespace ft
#endif // FT_CONTAINERS_VECTOR_iterator_HPP

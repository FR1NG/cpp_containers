#pragma once

#include "iterator_traits.hpp"
#include <utility>

namespace ft {

template <typename NodeType> class map_iterator {

public:
  // memer types
  typedef NodeType iterator_type;
  typedef typename  ft::iterator_traits<NodeType>::iterator_category iterator_category;
  typedef typename  ft::iterator_traits<NodeType>::value_type value_type;
  typedef typename  ft::iterator_traits<NodeType>::difference_type difference_type;
  typedef typename  ft::iterator_traits<NodeType>::pointer pointer;
  typedef typename  ft::iterator_traits<NodeType>::reference reference;
  typedef typename value_type::data_pointer data_pointer;
  typedef typename value_type::first_type first_type;
  typedef typename value_type::second_type second_type;

  // memeber functions
  map_iterator(): _it(NULL){}

  explicit map_iterator(iterator_type it):_it(it){}

  template <class Iter>  map_iterator(const map_iterator<Iter>& it): _it(it.base()) {}

  ~map_iterator(){}

  iterator_type base() const {
    return this->_it;
  }

  // overloading operators
  template< class Iter >
  map_iterator& operator=( const  map_iterator<Iter>& it )
  {
    this->_it = it.base();
    return *this;
  }

  second_type operator*() { 
    return (_it->data()->second);
  }

  const second_type operator*() const { 
    return (_it->data()->second);
  }

   map_iterator operator++() {
    if (this->_it->isRoot() && this->_it->hasRight()) {
      this->_it = this->_it->getRight();
      while(this->_it->hasLeft())
        this->_it = this->_it->getLeft();
      return *this;
    }
    if (this->_it->isLeft()) {
      if (this->_it->hasRight()) {
        this->_it = this->_it->getRight();
        while (this->_it->hasLeft())
          this->_it = this->_it->getLeft();
      } else {
        if(!this->_it->isRoot())
          this->_it = this->_it->getParent();
      }
    }
    else if (this->_it->isRight()) {
      if (this->_it->hasRight())
        this->_it = this->_it->getRight();
      else {
        iterator_type tmp = this->_it; 
        while (!this->_it->isRoot() && this->_it->getParent()->getKey() < tmp->getKey())
          this->_it = this->_it->getParent();
        if(this->_it->hasParent())
          this->_it = this->_it->getParent();
      }
    }
    return *this;
  }

  map_iterator operator++(int) {
  map_iterator tmp = *this;

    ++(*this);
    return tmp;
  }

  map_iterator &operator--() {
    if (this->_it->isRoot() && this->_it->hasLeft()) {
      this->_it = this->_it->getLeft();
      while(this->_it->hasRight())
        this->_it = this->_it->getRight();
      return *this;
    }
    if (this->_it->isRight()) {
      if (this->_it->hasLeft()) {
        this->_it = this->_it->getLeft();
        while (this->_it->hasRight())
          this->_it = this->_it->getRight();
      } else {
        if(!this->_it->isRoot())
          this->_it = this->_it->getParent();
      }
    }
    else if (this->_it->isLeft()) {
      if (this->_it->hasLeft())
        this->_it = this->_it->getLeft();
      else {
        iterator_type tmp = this->_it; 
        while (!this->_it->isRoot() && tmp->getKey() < this->_it->getParent()->getKey())
          this->_it = this->_it->getParent();
        if(this->_it->hasParent())
          this->_it = this->_it->getParent();
      }
    }
    return *this;
  }

   map_iterator operator--(int) {
     map_iterator tmp = *this;
    --(*this);
    return tmp;
  }

  data_pointer operator->() { return (this->_it->data()); }

  const data_pointer operator->() const { return (this->_it->data()); }

private:
  // data members
  iterator_type _it;



}; // class iterator

// // relational operators
template<class Iterator1, class Iterator2>
bool operator==(const  map_iterator<Iterator1> &lhs,
                const  map_iterator<Iterator2> &rhs) {
  return lhs.base() == rhs.base();
}

template<class Iterator1, class Iterator2>
bool operator!=(const  map_iterator<Iterator1> &lhs,
                const  map_iterator<Iterator2> &rhs) {
  return (lhs.base() != rhs.base());
}

} // namespace ft

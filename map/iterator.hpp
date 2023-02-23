#pragma once

#include "../helpers/iterator_traits.hpp"
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

  // memeber functions
  map_iterator(): _it(NULL){}

  explicit map_iterator(iterator_type it):_it(it){}

  template <class Iter>  map_iterator(const map_iterator<Iter>& it): _it(it.base()){ 


  }

  ~map_iterator(){}

  iterator_type base() const {
    return this->_it;
  }

  // overloading operators
  // template< class Iter >
  // iterator& operator=( const  iterator<Iter>& it )
  // {
  //   this->_it = it.base();
  //   return *this;
  // }

  // reference operator*() { 
  //   return (*_it);
  // }

  // const reference operator*() const { 
  //   return (_it->data()->first);
  // }

  //  iterator operator+(difference_type n) const {
  //   return iterator(this->_it + n);
  // }

  //  map_iterator operator++() {
  // }

  map_iterator operator++(int) {
    map_iterator tmp = *this;

    if (this->_it->isLeft()) {
      if (this->_it->hasRight()) {
        this->_it = this->_it->getRight();
        while (this->_it->hasLeft())
          this->_it = this->_it->getLeft();
      } else {
        this->_it = this->_it->getParent();
      }
    }
    if (this->_it->isRight()) {
      if (this->_it->hasRight())
        this->_it = this->_it->getRight();
      else {
        for (int i = 0; i < 2; i++) {

          if (this->_it->hasParent())
            this->_it = this->_it->getParent();
        }
      }
    }
    if(!this->_it->hasParent() && this->_it->hasRight())
      this->_it = this->_it->getRight();
    return tmp;
  }

  //  iterator operator+=(difference_type n)
  // {
  //   this->_it += n;
  //   return (*this);
  // }

  //  iterator operator-(difference_type n) const {
  //   return iterator(this->_it - n);
  // }

  // iterator &operator--() {
  //   this->_it--;
  //   return (*this);
  // }

  //  iterator operator--(int) {
  //    iterator tmp = *this;
  //   --(*this);
  //   return tmp;
  // }

  //  iterator &operator-=(difference_type n) {
  //   this->_it = this->_it - n;
  //   return (*this);
  // }

  data_pointer operator->() { return (this->_it->data()); }

  // const pointer operator->() const { return &(operator*()->data()); }

  // reference operator[](difference_type n) const { return this->_it[n]; }

  // void test()
  // {
  //   typedef typename value_type::value_type* ptr;
  //   ptr p = this->_it->data() ;
  //   std::cout << p->first << std::endl;
  // }

private:
  // data members
  iterator_type _it;



// // relational operators
// template<class Iterator1, class Iterator2>
// friend bool operator==(const  iterator<Iterator1> &lhs,
//                 const  iterator<Iterator2> &rhs) {
//   return lhs.base() == rhs.base();
// }

template<class Iterator1, class Iterator2>
friend bool operator!=(const  map_iterator<Iterator1> &lhs,
                const  map_iterator<Iterator2> &rhs) {
  return lhs.base() != rhs.base();
}

// template<class Iterator1, class Iterator2>
// friend bool operator<(const  iterator<Iterator1> &lhs,
//                const  iterator<Iterator2> &rhs) {
//   return lhs.base() < rhs.base();
// }

// template<class Iterator1, class Iterator2>
// friend bool operator<=(const  iterator<Iterator1> &lhs,
//                 const  iterator<Iterator2> &rhs) {
//   return lhs.base() <= rhs.base();
// }

// template<class Iterator1, class Iterator2>
// friend bool operator>(const  iterator<Iterator1> &lhs,
//                const  iterator<Iterator2> &rhs) {
//   return lhs.base() > rhs.base();
// }

// template<class Iterator1, class Iterator2>
// friend bool operator>=(const  iterator<Iterator1> &lhs,
//                 const  iterator<Iterator2> &rhs) {
//   return lhs.base() >= rhs.base();
// }

// template<class Iterator1>
// friend iterator<Iterator1> operator+(typename  iterator<Iterator1>::difference_type n,
//           const  iterator<Iterator1> &it) {
//   return iterator<Iterator1>(it + n);
// }

// template <class It>
//  friend typename iterator<It>::difference_type operator-(    const iterator<It>& lhs,    const iterator<It>& rhs)
// {
//     return  lhs.base() - rhs.base();
// }

}; // class iterator

} // namespace ft

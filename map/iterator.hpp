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

  // memeber functions
  map_iterator(): _it(nullptr){}

  explicit map_iterator(iterator_type it):_it(it){
    this->_it = new Avl<int, int, std::pair<int, int>, std::less<int> >::Node();
    // std::cout << this->_it->getRoot()->getKey() << std::endl;
  }

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
  //   return (_it->data());
  // }

  //  iterator operator+(difference_type n) const {
  //   return iterator(this->_it + n);
  // }

  //  map_iterator operator++() {
  // }

  //  iterator operator++(int) {
  //    iterator tmp  = *this;
  //   ++(*this);
  //   return tmp;
  // }

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

  // pointer operator->() { return &(operator*()->data()); }

  // const pointer operator->() const { return &(operator*()); }

  // reference operator[](difference_type n) const { return this->_it[n]; }

private:
  // data members
  iterator_type _it;



// // relational operators
// template<class Iterator1, class Iterator2>
// friend bool operator==(const  iterator<Iterator1> &lhs,
//                 const  iterator<Iterator2> &rhs) {
//   return lhs.base() == rhs.base();
// }

// template<class Iterator1, class Iterator2>
// friend bool operator!=(const  iterator<Iterator1> &lhs,
//                 const  iterator<Iterator2> &rhs) {
//   return lhs.base() != rhs.base();
// }

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

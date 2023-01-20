//
// Created by Hamza Chakoubi on 12/13/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "vector/helpers.tpp"
#include "vector/iterator.hpp"
#include "vector/reverse_iterator.hpp"
#include <exception>
#include <memory>

namespace ft {

template <typename IT> int distance(const IT &begin, const IT &end) {
  if (end > begin)
    return end - begin;
  return -1;
}

template <typename T, typename Allocator = std::allocator<T> > class vector {

public:
  typedef typename Allocator::value_type value_type;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef iterator<const_pointer> const_iterator;
  typedef ft::iterator<pointer> iterator;
  typedef ft::reverse_iterator<pointer> reverse_iterator;
  typedef ft::reverse_iterator<const_pointer> const_reverse_iterator;
  iterator _iterator;

  //        constructors [ begin ]
  vector() : _size(0), _capacity(0), _v(nullptr){};

  explicit vector(const Allocator &alloc) : _allocator(alloc), _v(nullptr) {}

  template <class InputIt>
  vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(),
         typename enable_if<!is_integral<InputIt>::value, InputIt>::type =
             InputIt())
      : _size(0), _capacity(0), _v(nullptr) {
    size_type count = ft::distance(first, last);
    this->_v = this->_allocator.allocate(count);
    this->_size = this->_capacity = count;
    InputIt it = first;
    size_type i = 0;
    while (it != last) {
      this->_allocator.construct(this->_v + i, *it);
      i++;
      it++;
    }
    
  }

  explicit vector(size_type count, const T &value = T(),
                  const Allocator &alloc = Allocator())
      : _allocator(alloc) {
    this->reserve(count);
    for (size_type i = 0; i < count; i++)
      this->_allocator.construct(this->_v + i, value);
    this->_size = count;
    this->_iterator.setPointer(this->_v);
  }

  vector(const vector &x) : _capacity(0), _size(0) {
    this->_size = x._size;
    this->_capacity = x._capacity;
    this->_v = this->_allocator.allocate(this->_capacity);
    //            this->_dup(this->_v, x._v, this->_size);
    this->_reconstruct(this->_v, x._v, this->_size);
  }
  //        constructors [ end ]

  void push_back(const T &val) {
    if (_size < _capacity) {
      _v[_size] = val;
      _size++;
    } else {
      if (_capacity == 0) {
        _v = _allocator.allocate(1);
        _v[0] = val;
        _size = _capacity = 1;
        // 
      } else {
        reserve(_capacity * 2);
        _v[_size] = val;
        _size++;
      }
    }
  }
  // operators [ begin ]

  vector &operator=(const vector &vec) {
    //        don't forget to destroy the old object
    if (&vec == this)
      return (*this);
    this->_size = vec._size;
    this->_capacity = vec._capacity;
    this->_v = this->_allocator.allocate(this->_capacity);
    this->_dup(this->_v, vec._v, this->_size);
    return (*this);
  }

  bool operator==(const vector &vec) {
    if (this->_size != vec._size)
      return false;
    for (int i = 0; i < this->_size; i++) {
      if (this->_v[i] != vec._v[i])
        return false;
    }
    return true;
  }

  bool operator!=(const vector &vec) { return !(*this == vec); }

  bool operator>(const vector &vec) {
    size_type i;

    i = 0;
    while (i < this->_size && i < vec._size) {
      if (this->_v[i] > vec._v[i])
        return true;
      i++;
    }
    if (this->_size > vec._size)
      return true;
    return false;
  }

  bool operator>=(const vector &vec) {
    size_type i;

    i = 0;
    while (i < this->_size && i < vec._size) {
      if (this->_v[i] > vec._v[i])
        return true;
      i++;
    }
    if (this->_size < vec._size)
      return false;
    return true;
  }

  bool operator<(const vector &vec) {
    size_type i;

    i = 0;
    while (i < this->_size && i < vec._size) {
      if (this->_v[i] < vec._v[i])
        return true;
      i++;
    }
    if (this->_size < vec._size)
      return true;
    return false;
  }

  bool operator<=(const vector &vec) {
    size_type i;

    i = 0;
    while (i < this->_size && i < vec._size) {
      if (this->_v[i] < vec._v[i])
        return true;
      i++;
    }
    if (this->_size > vec._size)
      return false;
    return true;
  }
  // operators [ end ]

  // capacity [ start ]
  bool empty() const {
    if (this->_size == 0)
      return true;
    return false;
  }

  size_type size() const { return this->_size; }

  size_type max_size() const {
    //            only for test edit later !!
    return this->_capacity;
  }

  void reserve(int newCapacity) {
    T *tmp = _allocator.allocate(newCapacity);
    if (this->size() != 0) {
      this->_reconstruct(tmp, this->_v, this->_size);
      this->_destroy();
    }
    _capacity = newCapacity;
    _v = tmp;
    
  }

  void copy(T *newArray) {
    for (int i = 0; i < _size; i++)
      newArray[i] = _v[i];
  }

  size_type capacity() const { return this->_capacity; }
  // capacity [ end ]

  // modifiers [ start ]
  void clear() {
    for (size_type i = 0; i < this->size(); i++)
      this->_allocator.destroy(this->_v + i);
    this->_size = 0;
  }

  template <class InputIterator>
  void assign(InputIterator first, InputIterator last,
              typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                     InputIterator>::type = InputIterator()) {
    size_type size;

    size = ft::distance(first, last);
    if (size > this->capacity())
      this->reserve(size);

    InputIterator it = first;
    size_type i(0);
    while (it != last) {
      this->_v[i] = *it;
      i++;
      it++;
    }
    this->_size = size;
  }

  void assign(size_type n, const value_type &val) {
    if (n > this->capacity())
      this->reserve(n);

    for (size_type i = 0; i < this->size(); i++)
      this->_v[i] = val;
    for (size_type i = this->size(); i < n; i++)
      this->_allocator.construct(this->_v + i, val);
    this->_size = n;
  }
  // modifiers [ end ]

  // iterators [ begin ]
  iterator begin() { return iterator(this->_v); }

  iterator end() { return iterator(this->_v + this->size()); }

  const_iterator begin() const { return iterator(this->_v); }

  const_iterator end() const { return iterator(this->_v + this->size()); }

  // iterators [ end ]

  // reverse iterator [ begin ]
  reverse_iterator rend() { return reverse_iterator(this->_v); }
  reverse_iterator rbegin() { return reverse_iterator(this->_v + this->size()); }
  const_reverse_iterator rend() const { return reverse_iterator(this->_v); }
  const_reverse_iterator rbegin() const { return reverse_iterator(this->_v + this->size()); }
  // reverse iterator [ end ]

  //    destructor of the class
  ~vector() {
    for (size_type i = 0; i < this->size(); i++)
      this->_allocator.destroy(this->_v + i);
    this->_allocator.deallocate(this->_v, this->capacity());
  }

  /*
          =================================================
          ================[ element access ]===============
          =================================================
  */

  reference at(size_type pos);

  const_reference at(size_type pos) const;

  reference operator[](size_type pos);

  const_reference operator[](size_type pos) const;

  reference front();

  const_reference front() const;

  reference back();

  const_reference back() const;

  T *data();

  const T *data() const;

  /*
          =================================================
          ===================[ modifiers ]=================
          =================================================
  */

  iterator insert(const_iterator pos, const T &value);

  iterator insert(const_iterator pos, size_type count, const T &value);

private:
  allocator_type _allocator;
  value_type *_v;
  size_type _size;
  size_type _capacity;

  // others
  void _dup(value_type *dest, value_type *src, size_type size) {
    for (size_type i = 0; i < size; i++)
      dest[i] = src[i];
  }

  void _reconstruct(value_type *dest, value_type *src, size_type size) {
    for (size_type i = 0; i < size; i++)
      this->_allocator.construct(dest + i, src[i]);
  }

  void _destroy() {
    for (size_type i = 0; i < this->size(); i++)
      this->_allocator.destroy(this->_v + i);
    this->_allocator.deallocate(this->_v, this->capacity());
  }
};
}; // namespace ft

#include "vector/element_access.tpp"
#include "vector/modifiers.tpp"

#endif // FT_CONTAINERS_VECTOR_HPP

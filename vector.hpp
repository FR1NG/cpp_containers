//
// Created by Hamza Chakoubi on 12/13/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "dev/helper.h"
#include "vector/helpers.hpp"
#include "vector/iterator.hpp"
#include "vector/reverse_iterator.hpp"
#include <exception>
#include <iterator>
#include <limits>
#include <memory>
#include <stdexcept>
#include <type_traits>

namespace ft {
template <typename T, typename Allocator = std::allocator<T> > class vector {

public:
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef typename allocator_type::value_type value_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef ft::iterator<pointer> iterator;
  typedef ft::iterator<const_pointer> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  //        constructors [ begin ]
  vector() : _v(NULL), _size(0), _capacity(0){};

  explicit vector(const Allocator &alloc)
      : _allocator(alloc), _v(NULL), _size(0), _capacity(0) {}

  template <class InputIt>
  vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(),
         typename enable_if<!is_integral<InputIt>::value, InputIt>::type =
             InputIt())
      : _allocator(alloc), _v(NULL), _size(0), _capacity(0) {
    this->assign(first, last);
  }

  explicit vector(size_type count, const T &value = T(),
                  const Allocator &alloc = Allocator())
      : _allocator(alloc) {
    if(count != 0)
      this->_v = this->_allocator.allocate(count);
    for (size_type i = 0; i < count; i++)
      this->_allocator.construct(this->_v + i, value);
    this->_size = count;
    this->_capacity = count;
  }

  vector(const vector &x) : _allocator(x._allocator), _size(0) , _capacity(0){
    // this->_allocator = x._allocator;
    // this->_v = this->_allocator.allocate(this->_capacity);
    // for(size_type i = 0; i < x.size(); i++)
    //   this->_allocator.construct(this->_v + i, x.at(i));
    this->assign(x.begin(), x.end());
    this->_size = x._size;
    this->_capacity = x._capacity;
  }
  //        constructors [ end ]

  // ? element access [ begin ]
  reference at(size_type pos) {
    if (pos >= this->_size || pos < 0)
      throw std::out_of_range("pos is out of range");
    return this->_v[pos];
  }

  const_reference at(size_type pos) const {
    if (pos >= this->size() || pos < 0)
      throw std::out_of_range("pos is out of range");
    return this->_v[pos];
  }

  reference operator[](size_type pos) { return this->_v[pos]; }

  const_reference operator[](size_type pos) const { return this->_v[pos]; }

  reference front() { return this->_v[0]; }

  const_reference front() const { return this->_v[0]; }

  reference back() { return this->_v[this->size() - 1]; }

  const_reference back() const { return this->_v[this->size() - 1]; }

  pointer data() { return this->_v; }

  const_pointer data() const { return this->_v; }
  // ? element access [ end ]

  // ? modifiers [ begin ]
  void push_back(const value_type& val) {
    if (this->capacity() <= this->size())
    {
      if (this->capacity() == 0)
        this->reserve(1);
      else
       this->reserve(this->capacity() * 2);
    }
    this->_allocator.construct(this->_v + this->size(), val);
    this->_size++;
  }

  void pop_back() {
    if (this->size() > 0)
      this->_allocator.destroy(this->_v + this->size() - 1);
    this->_size--;
  }
  // ? modifiers [ end ]

  // ? operators [ begin ]
  vector &operator=(const vector &vec) {
    if (&vec == this)
      return (*this);

    size_type allocated_size = this->capacity() >= vec.size() ? this->capacity() : vec.size();
    this->_destroy();
    this->_allocator = vec._allocator;
    if (vec.size() > 0)
      this->_v = this->_allocator.allocate(allocated_size);
    for (size_type i = 0; i < vec.size(); i++)
      this->_allocator.construct(this->_v + i, vec.at(i));
    this->_size = vec.size();
    this->_capacity = vec.size() > 0 ? allocated_size : 0;
    return (*this);
  }

  // ? operators [ end ]

  //?  capacity [ start ]
  bool empty() const {
    if (this->_size == 0)
      return true;
    return false;
  }

  void resize(size_type n, value_type val = value_type()) {
    if (n < this->size()) {
      for (size_type i = n; i < this->size(); i++)
        this->_allocator.destroy(this->_v + i);
    } else {
      if (n > this->capacity()) {
        size_type allocated_size = n > capacity() * 2 ? n : capacity() * 2;
        this->reserve(allocated_size);
        for (size_type i = this->size(); i < n; i++)
          this->_allocator.construct(this->_v + i, val);
        this->_capacity = allocated_size;
      } else {
        for (size_type i = this->size(); i < n; i++)
          this->_allocator.construct(this->_v + i, val);
      }
    }
    this->_size = n;
  }

  size_type size() const { return this->_size; }

  size_type max_size() const {
    return ft::min(this->_allocator.max_size(), std::numeric_limits<difference_type>::max());
  }

  void reserve(size_type n) {
    if (n <= size())
      return;
    if (n > this->capacity()) 
    {
      pointer tmp = _allocator.allocate(n);
      if (this->capacity() != 0) 
      {
        this->_reconstruct(tmp, this->_v, this->_size);
        this->_destroy();
      }
      this->_capacity = n;
      this->_v = tmp;
    }
  }

  void copy(T *newArray) {
    for (int i = 0; i < _size; i++)
      newArray[i] = _v[i];
  }

  size_type capacity() const { return this->_capacity; }
  // ? capacity [ end ]

  // ? modifiers [ start ]
  void clear() {
    for (size_type i = 0; i < this->size(); i++)
      this->_allocator.destroy(this->_v + i);
    this->_size = 0;
  }

  template <class InputIterator>
  void assign(InputIterator first, InputIterator last,
              typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                     InputIterator>::type = InputIterator()) {
    if (is_input_iterator_tagged<typename std::iterator_traits<
            InputIterator>::iterator_category>::value) {
      vector tmp;
      while (first != last) {
        tmp.push_back(*first);
        first++;
      }
      if (tmp.size() > this->capacity()) {
        this->_destroy();
        this->_v = this->_allocator.allocate(tmp.size());
        this->_size = tmp.size();
        this->_capacity = tmp.size();
        for (size_type i = 0; i < tmp.size(); i++)
          this->_allocator.construct(this->_v + i, tmp.at(i));
      } else {
        size_type counter = 0;
        while (counter < this->size()) {
          this->_allocator.destroy(this->_v + counter);
          this->_allocator.construct(this->_v + counter, tmp.at(counter));
          counter++;
        }
        while (counter < tmp.size()) {
          this->_allocator.construct(this->_v + counter, tmp.at(counter));
          counter++;
        }
        this->_size = tmp.size();
      }
    } else {
      // if(first > last)
      //   throw std::length_error("first iterator is greater then last");
      size_type size = ft::distance(first, last);
      if (size > this->capacity()) {
        this->_destroy();
        this->_v = this->_allocator.allocate(size);
        this->_capacity = size;
      } else if (this->size() > 0) {
        for (size_type i = 0; i < this->size(); i++)
          this->_allocator.destroy(this->_v + i);
      }

      size_type i = 0;
      for (InputIterator it = first; it != last; it++, i++)
        this->_allocator.construct(this->_v + i, *it);
      this->_size = size;
    }
  }

  void assign(size_type n, const value_type &val) {
    if(n <= this->capacity())
    {
      for(size_type i = 0; i < this->size(); i++)
       this->_allocator.destroy(this->_v + i);
      for(size_type i = 0; i < n; i++)
        this->_allocator.construct(this->_v + i, val);
    } else {
      this->_destroy();
      this->_v = this->_allocator.allocate(n);
      this->_capacity = n;
      for(size_type i = 0; i < n; i++)
        this->_allocator.construct(this->_v + i, val);
    }
    this->_size = n;
  }

  iterator insert(iterator position, const value_type &val) {
    size_type dist = std::distance(this->begin(), position);
    if (position == this->end() && !this->empty()) {
      this->push_back(val);
    } else {
      if (this->empty()) {
        this->push_back(val);
        return this->begin();
      } else {
        iterator it = this->end();
        value_type tmp = *(this->rbegin());
        size_type i = this->size() - 1;

        for (; i > 0 && i > dist; i--) {
          this->_allocator.destroy(this->_v + i);
          this->_allocator.construct(this->_v + i, this->_v[i - 1]);
        }
        this->_allocator.destroy(this->_v + i);
        this->_allocator.construct(this->_v + i, val);
        this->push_back(tmp);
      }
    }
    return this->begin() + dist;
  }

  void insert(iterator position, size_type n, const value_type &val) {
    if (n == 0)
      return;
    if (n + this->size() > this->capacity() || this->capacity() == 0) {
      size_type allocated_size;
      size_type old_size = this->size();
      iterator it = this->begin();
      size_type current = 0;
      pointer tmp;

      this->size() + n > this->capacity() * 2
          ? allocated_size = this->size() + n
          : allocated_size = this->capacity() * 2;
      tmp = this->_allocator.allocate(allocated_size);
      while (it < position) {
        this->_allocator.construct(tmp + current, *it);
        it++;
        current++;
      }
      for (size_type counter = 0; counter < n; counter++) {
        this->_allocator.construct(tmp + current, val);
        current++;
      }
      while (it < this->end()) {
        this->_allocator.construct(tmp + current, *it);
        it++;
        current++;
      }

      this->_destroy();
      this->_size = old_size + n;
      this->_capacity = allocated_size;
      this->_v = tmp;
    } else {
      size_type copy_from = this->size() - 1;
      size_type copy_to = copy_from + n;
      size_type stop = std::distance(this->begin(), position);
      while (copy_from >= stop) {
        if (copy_to < this->size())
          this->_allocator.destroy(this->_v + copy_to);
        this->_allocator.construct(this->_v + copy_to,
                                   *(this->begin() + copy_from));
        copy_from--;
        copy_to--;
      }
      for(size_type i = stop; i < stop + n; i++)
        {
          if (i < this->size())
            this->_allocator.destroy(this->_v + i);
          this->_allocator.construct(this->_v + i, val);
        }
      this->_size += n;
    }
  }


  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last,
              typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                     InputIterator>::type = InputIterator()) {
    if(first == last)
      return;
    if(is_input_iterator_tagged<typename std::iterator_traits<InputIterator>::iterator_category>::value)
    {
      vector v = _push_input(first, last);
      insert(position, v.begin(), v.end());
      return;
    }
    if (!_is_constructable(first, last))
      throw std::bad_alloc();
    size_type number = ft::distance(first, last);
    if (this->capacity() == 0) {
      this->_v = this->_allocator.allocate(number);
      size_type counter = 0;
      for (InputIterator it = first; it != last; it++, counter++)
        this->_allocator.construct(this->_v + counter, *it);
      this->_capacity = this->_size = number;
      return;
    }
    if (this->size() + number > this->capacity()) {
      size_type allocated_size = this->size() + number > this->capacity() * 2
                                     ? this->size() + number
                                     : this->capacity() * 2;
      pointer tmp = this->_allocator.allocate(allocated_size);
      size_type count = 0;
      iterator it = this->begin();
      size_type old_size = this->size();

      for (; it != position; it++, count++)
        this->_allocator.construct(tmp + count, *it);
      for (InputIterator Iit = first; Iit != last; Iit++, count++)
        this->_allocator.construct(tmp + count, *Iit);
      for (; it != this->end(); it++, count++)
        this->_allocator.construct(tmp + count, *it);
      this->_destroy();
      this->_size = old_size + number;
      this->_capacity = allocated_size;
      this->_v = tmp;
    } else {
      size_type copy_from = this->size() - 1;
      size_type copy_to = copy_from + number;
      size_type stop = std::distance(this->begin(), position);
      while (copy_from >= stop) {
        if (copy_to < this->size())
          this->_allocator.destroy(this->_v + copy_to);
        this->_allocator.construct(this->_v + copy_to,
                                   *(this->begin() + copy_from));
        copy_from--;
        copy_to--;
      }
      for(size_type i = stop; i < stop + number; i++)
        {
          if (i < this->size())
            this->_allocator.destroy(this->_v + i);
          this->_allocator.construct(this->_v + i, *first);
          first++;
        }
      this->_size += number;
    }
  }

  iterator erase(iterator position) {
    size_type index = std::distance(this->begin(), position);

    for (size_type i = index; i < this->size() - 1; i++) {
      this->_allocator.destroy(this->_v + i);
      this->_allocator.construct(this->_v + i, this->_v[i + 1]);
    }
    this->_allocator.destroy(this->_v + this->size() - 1);
    this->_size--;
    return this->begin() + index;
  }


  iterator erase (iterator first, iterator last)
  {
    size_type range = std::distance(first, last);
    size_type first_index = std::distance(this->begin(), first);
    size_type position = first_index;
    size_type move_from = first_index + range;

    if(range == 0)
      return this->begin();
    for(size_type i = move_from; i != this->size(); i++, first_index++)
    {
      this->_allocator.destroy(this->_v + first_index);
      this->_allocator.construct(this->_v + first_index, this->_v[i]);
    }
    for(size_type i = this->size() - range; i < this->size(); i++)
      this->_allocator.destroy(this->_v + i);
    this->_size -= range;
    return this->begin() + position;   
  }

  void swap(vector &x) {
    std::swap(this->_capacity, x._capacity);
    std::swap(this->_size, x._size);
    std::swap(this->_allocator, x._allocator);
    std::swap(this->_v, x._v);
  }
  // ? modifiers [ end ]

  // ? iterators [ begin ]
  iterator begin() { return iterator(this->_v); }

  iterator end() { return iterator(this->_v + this->size()); }

  const_iterator begin() const { return const_iterator(this->_v); }

  const_iterator end() const { return const_iterator(this->_v + this->size()); }
  // ? iterators [ end ]

  // reverse iterator [ begin ]
  reverse_iterator rend() { return reverse_iterator(this->begin()); }

  reverse_iterator rbegin() { return reverse_iterator(this->end()); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(this->begin());
  }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(this->end());
  }
  // reverse iterator [ end ]

  //    destructor of the class
  ~vector() {
    this->clear();
    if (this->capacity() > 0) {
       this->_allocator.deallocate(this->_v, this->capacity());
    }
  }

  allocator_type get_allocator() const { return this->_allocator; }

private:
  allocator_type _allocator;
  pointer _v;
  size_type _size;
  size_type _capacity;

  // others
  void _dup(value_type *dest, value_type *src, size_type size) {
    for (size_type i = 0; i < size; i++)
      dest[i] = src[i];
  }

  void _reconstruct(pointer dest, pointer src, size_type size) {
    for (size_type i = 0; i < size; i++)
      this->_allocator.construct(dest + i, src[i]);
  }

  void _destroy() {
    for(size_type i = 0; i < this->size(); i++)
      this->_allocator.destroy(this->_v + i);
    if (this->capacity() > 0)
      this->_allocator.deallocate(this->_v, this->capacity());
  }


  template<class InputIteator>
  vector _push_input(InputIteator first, InputIteator last)
{
    vector v;
    while (first != last) {
      v.push_back(*first);
      first++;
    }
    return v;
  }
  template<class Iter>
  bool _is_constructable(Iter first, Iter last)
  {
    bool result = true;
    pointer tmp = this->_allocator.allocate(1);

    while(first != last)
      {
        try {
          this->_allocator.construct(tmp, *first);
          this->_allocator.destroy(tmp);
        } catch(...)
        {
          result = false;
        }
        first++;
      }
    this->_allocator.deallocate(tmp, 1);
    return result;
  }
};

/*
* none_member functions
*/

/*
* relational operators
*/
template <class T, class Alloc>
bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  if (lhs.size() != rhs.size())
    return false;
  for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++) {
    if (lhs.at(i) != rhs.at(i))
      return false;
  }
  return true;
}

template <class T, class Alloc>
bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  typename vector<T, Alloc>::size_type i;

  i = 0;
  while (i < lhs.size() && i < rhs.size()) {
    if (lhs.at(i) > rhs.at(i))
      return true;
    i++;
  }
  if (lhs.size() > rhs.size())
    return true;
  return false;
}

template <class T, class Alloc>
bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  typename vector<T, Alloc>::size_type i;

  i = 0;
  while (i < lhs.size() && i < rhs.size()) {
    if (lhs.at(i) < rhs.at(i))
      return false;
    i++;
  }
  if (lhs.size() < rhs.size())
    return false;
  return true;
}

template <class T, class Alloc>
bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  typename vector<T, Alloc>::size_type i;

  i = 0;
  while (i < lhs.size() && i < rhs.size()) {
    if (lhs.at(i) < rhs.at(i))
      return true;
    i++;
  }
  if (lhs.size() < rhs.size())
    return true;
  return false;
}

template <class T, class Alloc>
bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
  typename vector<T, Alloc>::size_type i;

  i = 0;
  while (i < lhs.size() && i < rhs.size()) {
    if (lhs.at(i) > rhs.at(i))
      return false;
    i++;
  }
  if (lhs.size() > rhs.size())
    return false;
  return true;
}


/*
 * swap function
 */

template <class T, class Alloc>
void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
  x.swap(y);
}
}; // namespace ft

// namespace std {
// /*
//  * swap function
//  */

// template <class T, class Alloc>
// void swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y) {
//   x.swap(y);
// }
// }; // namespace std

#endif // FT_CONTAINERS_VECTOR_HPP

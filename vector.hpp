//
// Created by Hamza Chakoubi on 12/13/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include "vector/helpers.tpp"
#include "vector/vector_iterator.hpp"

namespace ft {

//    hello world
    template<typename IT>
    int distance(const IT &begin, const IT &end) {
        if (end > begin)
            return end - begin;
        return -1;
    }

    template<typename T, typename Allocator = std::allocator <T> >
    class vector {

    public:
        typedef vector_iterator<T> iterator;
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        //    typedef pointer
        //    typedef const_pointer
        typedef const vector_iterator<T> const_iterator;
        //    typedef reverse_iterator
        //    typedef const_reverse_iterator
        iterator _iterator;

        //        constructors [ begin ]
        vector() : _size(0), _capacity(0), _v(nullptr) {};

        explicit vector(const Allocator &alloc) : _allocator(alloc) {}

        explicit vector(
                size_type count,
                const T &value = T(),
                const Allocator &alloc = Allocator(),
                typename ft::enable_if<true, int>::type x = 1
        ) : _allocator(alloc) {
            std::cout << "integral constructor" << std::endl;
            this->reserve(count);
            for (size_type i = 0; i < count; i++)
                this->_v[i] = value;
            this->_size = count;
        }

        template<class InputIt>
        vector(InputIt first, InputIt last, const Allocator &alloc = Allocator()): _size(0), _capacity(0), _v(nullptr) {
            std::cout << "non integral constructor" << std::endl;
            std::cout << ft::is_integral<T>::value << std::endl;
//            InputIt it = first;
//            while ( it != last )
//            {
//                this->push_back(*it);
//                it++;
//            }
        }

        vector(const vector &x) {
            this->_size = x._size;
            this->_capacity = x._capacity;
            this->_v = this->_allocator.allocate(this->_capacity);
            vector::dup(this->_v, x._v, this->_size);
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
                    this->_iterator.setPointer(_v);
                } else {
                    reserve(_capacity * 2);
                    _v[_size] = val;
                    _size++;
                }
            }
        }


        void test() {
            for (int i = 0; i < this->_size; i++)
                std::cout << _v[i] << std::endl;
            std::cout << "capacity " << this->_capacity << " size " << this->_size << std::endl;
        }
// operators [ begin ]

        vector &operator=(const vector &vec) {
//        don't forget to destroy the old object
            if (&vec == this)
                return (*this);
            this->_size = vec._size;
            this->_capacity = vec._capacity;
            this->_v = this->_allocator.allocate(this->_capacity);
            vector::dup(this->_v, vec._v, this->_size);
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

        bool operator!=(const vector &vec) {
            return !(*this == vec);
        }

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

        size_type size() const {
            return this->_size;
        }

        size_type max_size() const {
//            only for test edit later !!
            return this->_capacity;
        }

        void reserve(int newCapacity) {
            T *tmp = _allocator.allocate(newCapacity);
            if (this->capacity() != 0) {
                copy(tmp);
                _allocator.deallocate(_v, this->_capacity);
            }
            _capacity = newCapacity;
            _v = tmp;
            this->_iterator.setPointer(_v);
        }

        void copy(T *newArray) {
            for (int i = 0; i < _size; i++)
                newArray[i] = _v[i];
        }

        size_type capacity() const {
            return this->_capacity;
        }
// capacity [ end ]


// modifiers [ start ]
        void clear() {
            _allocator.destroy(_v);
            _allocator.deallocate(_v, this->_capacity);
        }
// modifiers [ end ]


// iterators [ begin ]
        iterator begin() {
            return this->_iterator;
        }

        iterator end() {
            return this->_iterator + this->_size;
        }

        const_iterator begin() const {
            return this->_iterator;
        }

        const_iterator end() const {
            return this->_iterator + this->_size;
        }

//        reverse iterator to be edited later and also add const one;
        iterator rend() {
            return this->_iterator;
        }

        iterator rbegin() {
            return this->_iterator + (this->_size - 1);
        }
// iterators [ end ]



//others
        static void dup(value_type *dest, value_type *src, size_type size) {
            for (size_type i = 0; i < size; i++)
                dest[i] = src[i];
        }

//    destructor of the class
        ~vector() {
            _allocator.deallocate(_v, this->capacity());
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
    };
};

#include "vector/element_access.tpp"
#include "vector/modifiers.tpp"

#endif //FT_CONTAINERS_VECTOR_HPP
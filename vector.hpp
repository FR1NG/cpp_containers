//
// Created by Hamza Chakoubi on 12/13/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP
#include <iostream>
#include <memory>

template<typename T>
class Vector {
private:
    typedef T value_type;
    typedef std::allocator<T> allocator_type;
    typedef   std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
//    typedef pointer
//    typedef const_pointer
//    typedef iterator
//    typedef const_iterator
//    typedef reverse_iterator
//    typedef const_reverse_iterator
    allocator_type _allocator;
    value_type * _v;
    size_type _size;
    size_type _capacity;

public:
    Vector(): _size(0), _capacity(0)
    {};
    void push_back(const T& val) {
        if (_size < _capacity)
        {
            _v[_size] = val;
            _size++;
        }
        else
        {
            if(_capacity == 0)
            {
                _v = _allocator.allocate(1);
                _v[0] = val;
                _size = _capacity = 1;
            }
            else {
                reserve(_capacity * 2);
                _v[_size]  = val;
                _size++;
            }
        }
    }

    void reserve(int newCapacity) {
        T* tmp = _allocator.allocate(newCapacity);
        _capacity = newCapacity;
        copy(tmp);
        _allocator.destroy(_v);
        _v = tmp;
    }

    void copy(T* newArray) {
            for(int i = 0; i < _size; i++)
                newArray[i] = _v[i];
    }

    void test()
    {
        for(int i = 0; i < _size; i++)
            std::cout << _v[i] << std::endl;
        std::cout << "capacity " << this->_capacity << " size " << this->_size << std::endl;
    }
// operators [ begin ]

    Vector& operator=(const Vector& vec)
    {
        if(&vec == this)
            return (*this);
        this->_size = vec._size;
        this->_capacity = vec._capacity;
        this->_v = this->_allocator.allocate(this->_capacity);
        Vector::dup(this->_v, vec._v, this->_size);
        return (*this);
    }

    bool    operator==(const Vector& vec)
    {
        if(this->_size != vec._size)
            return false;
        for(int i = 0; i < this->_size; i++)
        {
            if(this->_v[i] != vec._v[i])
                return false;
        }
        return true;
    }
    bool operator!=(const Vector &vec)
    {
        return !(*this == vec);
    }
// operators [ end ]
    static void dup(value_type *dest, value_type *src, size_type size)
    {
        for(size_type i = 0; i < size; i++)
            dest[i] = src[i];
    }
//    destructor of the class
~Vector() {
        _allocator.destroy(_v);
    }
};


#endif //FT_CONTAINERS_VECTOR_HPP

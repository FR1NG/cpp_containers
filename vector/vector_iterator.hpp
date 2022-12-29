//
// Created by Hamza Chakoubi on 12/17/22.
//

#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_ITERATOR_HPP
#include "vector.hpp"

template <class T>
class vector_iterator {
private:
    typedef T* pointer;
    typedef T& reference;
    pointer ptr;

public:
    vector_iterator(){};
    vector_iterator(T* it){
        this->ptr = it;
    };

    T* getPointer() const {
        return this->ptr;
    }

    void    setPointer(T* ptr)
    {
        this->ptr = ptr;
    }


//    overloading operators


    bool    operator==(const vector_iterator<T>& it)
    {
        return (this->ptr == it.ptr);
    }

    bool    operator>=(const vector_iterator<T>& it)
    {
        return (this->ptr >= it.ptr);
    }

    bool    operator<=(const vector_iterator<T>& it)
    {
        return (this->ptr <= it.ptr);
    }

    bool    operator>(const vector_iterator<T>& it)
    {
        return (this->ptr > it.ptr);
    }

    bool    operator<(const vector_iterator<T>& it)
    {
        return (this->ptr < it.ptr);
    }

    bool    operator!=(const vector_iterator<T>& it)
    {
        if(*this == it)
            return false;
        return true;
    }

    vector_iterator& operator=(const vector_iterator<T>& it) {
        if (this == &it)
            return *this;
        this->ptr = it.ptr;
        return *this;
    }

    vector_iterator& operator++() {
        ptr++;
        return *this;
    }

    vector_iterator operator++(int) {
        vector_iterator tmp = *this;
        ++(*this);
        return tmp;
    }


    vector_iterator& operator--() {
        ptr--;
        return *this;
    }

    vector_iterator operator--(int) {
        vector_iterator tmp = *this;
        --*this;
        return tmp;
    }

    reference operator*() const {
        return *(this->ptr);
    }

    vector_iterator operator+(size_t i)
    {
        vector_iterator iterator = *this;
        iterator.ptr += i;
        return iterator;
    }

//    to be looked at lather
    reference operator[](size_t i)
    {
        return  (*this + i);
    }
};

#endif //FT_CONTAINERS_VECTOR_ITERATOR_HPP

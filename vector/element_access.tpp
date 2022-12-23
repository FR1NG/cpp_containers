//
// Created by Hamza Chakoubi on 12/19/22.
//

#ifndef FT_CONTAINERS_ELEMENT_ACCESS_TPP
#define FT_CONTAINERS_ELEMENT_ACCESS_TPP
#include <exception>
#include "vector.hpp"

namespace ft {

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::at( vector<T, Allocator>::size_type pos ) {
        if(pos > this->_size || pos < 0)
            throw std::out_of_range("pos is out of range");
        return this->_v[pos];
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::at( vector<T, Allocator>::size_type pos ) const {
        if(pos > this->_size || pos < 0)
            throw std::out_of_range("pos is out of range");
        return this->_v[pos];
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::operator[] (vector<T, Allocator>::size_type pos ) {
        return this->_v[pos];
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::front () const {
        return this->_v[0];
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::front () {
        return this->_v[0];
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::back () const {
        return this->_v[this->_size - 1];
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::back () {
        return this->_v[this->_size - 1];
    }


}

#endif //FT_CONTAINERS_ELEMENT_ACCESS_TPP

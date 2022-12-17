//
// Created by Hamza Chakoubi on 12/17/22.
//

#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_ITERATOR_HPP

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

    vector_iterator& operator=(const vector_iterator<T>& it) {
        if (this == &it)
            return this;
        this->ptr = it.ptr;
        return *this;
    }

    vector_iterator& operator++() {
        ptr++;
        return *this;
    }

    vector_iterator operator++(int) {
        vector_iterator tmp = *this;
        ++*this;
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
};

#endif //FT_CONTAINERS_VECTOR_ITERATOR_HPP

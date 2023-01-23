
//
// Created by Hamza Chakoubi on 12/19/22.
//

#ifndef FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

    template<typename Iterator>
    class reverse_iterator {

    public:
        // memer types
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;

        // memeber functions
        reverse_iterator() : _it() {}

        explicit reverse_iterator(Iterator it) : _it(it) {}

        template<class Iter>
        reverse_iterator(const reverse_iterator<Iter> &it): _it(it) {}

        ~reverse_iterator() {}

        iterator_type base() const {
            iterator_type it = this->_it;
            it--;
            return it;
        }


        // overloading operators
        template<class Iter>
        reverse_iterator &operator=(const reverse_iterator<Iter> &it) {
            this->_it = it.base();
            return *this;
        }

        reference operator*() {
            return (*_it);
        }

        const reference operator*() const {
            return (*_it);
        }

        reverse_iterator operator+(difference_type n) const {
            return reverse_iterator(this->_it - n);
        }

        reverse_iterator operator++() {
            this->_it--;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        reverse_iterator operator+=(difference_type n) {
            this->_it -= n;
            return (*this);
        }

        reverse_iterator operator-(difference_type n) const {
            return reverse_iterator(this->_it + n);
        }

        reverse_iterator &operator--() {
            this->_it++;
            return (*this);
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        reverse_iterator &operator-=(difference_type n) {
            this->_it = this->_it + n;
            return (*this);
        }

        pointer operator->() const { return &(operator*()); }

        reference operator[](difference_type n) const { return this->_it[n]; }

    private:
        // data members
        iterator_type _it;

        // relational operators
        template<class Iterator1, class Iterator2>
        friend bool operator==(const reverse_iterator<Iterator1> &lhs,
                               const reverse_iterator<Iterator2> &rhs) {
            return lhs.base() == rhs.base();
        }

        template<class Iterator1, class Iterator2>
        friend bool operator!=(const reverse_iterator<Iterator1> &lhs,
                               const reverse_iterator<Iterator2> &rhs) {
            return lhs.base() != rhs.base();
        }

        template<class Iterator1, class Iterator2>
        friend bool operator<(const reverse_iterator<Iterator1> &lhs,
                              const reverse_iterator<Iterator2> &rhs) {
            return lhs.base() < rhs.base();
        }

        template<class Iterator1, class Iterator2>
        friend bool operator<=(const reverse_iterator<Iterator1> &lhs,
                               const reverse_iterator<Iterator2> &rhs) {
            return lhs.base() <= rhs.base();
        }

        template<class Iterator1, class Iterator2>
        friend bool operator>(const reverse_iterator<Iterator1> &lhs,
                              const reverse_iterator<Iterator2> &rhs) {
            return lhs.base() > rhs.base();
        }

        template<class Iterator1, class Iterator2>
        friend bool operator>=(const reverse_iterator<Iterator1> &lhs,
                               const reverse_iterator<Iterator2> &rhs) {
            return lhs.base() >= rhs.base();
        }

        friend reverse_iterator operator+(typename reverse_iterator::difference_type n,
                                          const reverse_iterator &it) {
            return reverse_iterator(it + n);
        }

        template <class It>
        friend typename iterator<It>::difference_type operator- (    const iterator<It>& lhs,    const iterator<It>& rhs)
        {
            return  lhs.base() - rhs.base();
        }
    }; // class iterator

} // namespace ft
#endif // FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

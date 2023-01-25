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
// temporary 
#include <iostream>

namespace ft {

    template<typename IT>
    int distance(const IT &begin, const IT &end) {
        if (end > begin)
            return end - begin;
        return -1;
    }

    template<typename T, typename Allocator = std::allocator<T> >
    class vector {

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
        vector() : _v(nullptr), _size(0), _capacity(0) {};

        explicit vector(const Allocator &alloc) : _allocator(alloc), _v(nullptr), _size(0), _capacity(0) {}

        template<class InputIt>
        vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(),
               typename enable_if<!is_integral<InputIt>::value, InputIt>::type =
               InputIt()): _allocator(alloc), _v(nullptr), _size(0), _capacity(0) {
            size_type count = ft::distance(first, last);
            this->_v = this->_allocator.allocate(count);
            this->_size = this->_capacity = count;
            size_type i = 0;

            for (InputIt it = first; it != last; it++) {
                _allocator.construct(_v + i, *it);
                i++;
            }
        }

        explicit vector(size_type count, const T &value = T(),
                        const Allocator &alloc = Allocator())
                : _allocator(alloc) {
            this->_v = this->_allocator.allocate(count);
            for (size_type i = 0; i < count; i++)
                this->_allocator.construct(this->_v + i, value);
            this->_size = count;
            this->_capacity = count;
        }

        vector(const vector &x) : _size(0), _capacity(0) {
            this->_size = x._size;
            this->_capacity = x._capacity;
            this->_v = this->_allocator.allocate(this->_capacity);
            this->_reconstruct(this->_v, x._v, this->_size);
        }
        //        constructors [ end ]

        // ? element access [ begin ]
        reference at(size_type pos) {
            if (pos > this->_size || pos < 0)
                throw std::out_of_range("pos is out of range");
            return this->_v[pos];
        }

        const_reference at(size_type pos) const {
            if (pos > this->_size || pos < 0)
                throw std::out_of_range("pos is out of range");
            return this->_v[pos];
        }

        reference operator[](size_type pos) {
            return this->_v[pos];
        }

        const_reference operator[](size_type pos) const {
            return this->_v[pos];
        }

        reference front() {
            return this->_v[0];
        }

        const_reference front() const {
            return this->_v[0];
        }

        reference back() {
            return this->_v[this->size() - 1];
        }

        const_reference back() const {
            return this->_v[this->size() - 1];
        }

        pointer data() {
            return this->_v;
        }

        const_pointer data() const {
            return this->_v;
        }
        // ? element access [ end ]

        // ? modifiers [ begin ]
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
                    this->_allocator.construct(this->_v + this->size(), val);
                    _size++;
                }
            }
        }

        // ? modifiers [ end ]

        // ? operators [ begin ]
        vector &operator=(const vector &vec) {
            //        don't forget to destroy the old object
            if (&vec == this)
                return (*this);
            this->_size = vec._size;
            this->_capacity = vec._capacity;
            this->_v = this->_allocator.allocate(this->_capacity);
            this->_reconstruct(this->_v, vec._v, this->_size);
            return (*this);
        }

        bool operator==(const vector &vec) {
            if (this->_size != vec._size)
                return false;
            for (size_type i = 0; i < this->_size; i++) {
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
            while (i < this->size() && i < vec.size()) {
                if (this->_v[i] > vec._v[i])
                    return true;
                i++;
            }
            if (this->_size >= vec._size)
                return true;
            return false;
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
//            this->_allocator.deallocate(this->_v + n, this->size() - n);
            } else {
                if (n > this->capacity()) {
//                this->reserve(this->capacity() + n);
                    for (size_type i = this->size(); i < n; i++)
                        this->push_back(val);
//                    this->_allocator.construct(this->_v + i, val);
//                this->_capacity = n;
                } else {
                    for (size_type i = this->size(); i < n; i++)
                        this->_allocator.construct(this->_v + i, val);
                }
            }
            this->_size = n;
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
        // ? capacity [ end ]

        // ? modifiers [ start ]
        void clear() {
            for (size_type i = 0; i < this->size(); i++)
                this->_allocator.destroy(this->_v + i);
            this->_size = 0;
        }

        template<class InputIterator>
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

        iterator insert(iterator position, const value_type &val) {
            iterator it = this->end();
            it--;
            if (it >= position) {
                T last = this->_v[this->_size - 1];
                while (it > this->begin()) {
                    *(it + 1) = *it;
                    if (it == position) {
                        *it = val;
                        break;
                    }
                    it--;
                }
                this->push_back(last);
            } else
                this->push_back(val);
            return it;
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            if (n + this->size() > this->capacity())
            {
                size_type allocated_size;
                size_type  old_size = this->size();
                iterator it = this->begin();
                size_type current = 0;
                pointer tmp;

                this->size() + n > this->capacity() * 2
                    ? allocated_size = this->size() + n
                    : allocated_size = this->capacity() * 2;
                tmp = this->_allocator.allocate(allocated_size);
                while (it != position) {
                    this->_allocator.construct(tmp + current, *it);
                    it++;
                    current++;
                }
                for (size_type counter = 0; counter < n; counter++) {
                    this->_allocator.construct(tmp + current, val);
                    current++;
                }
                while(it != this->end())
                {
                    this->_allocator.construct(tmp + current, *it);
                    it++;
                    current++;
                }

                this->_destroy();
                this->_size = old_size + n;
                this->_capacity = allocated_size;
                this->_v = tmp;
            }
            else
            {
                // ! try to ask about if position greater than end;
                if (position >= this->end())
                {
                    for (size_type i = 0; i < n; i++)
                        this->_allocator.construct(this->_v + this->size() + i, val);
                }
                else
                {
                    iterator end = this->end() - 1;
                    size_type last_index = this->size() + n - 1;
                    while (end != position - 1) {
                        this->_allocator.construct(this->_v + last_index, *end);
                        end--;
                        last_index--;
                    }
                    for (size_type i = 0;  i < n ; i++) {
                        *(position) = val;
                        position++;
                    }
                }
                this->_size += n;
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {
                size_type number = std::distance(first, last);
            if (this->size() + number > this->capacity())
            {
                size_type allocated_size = this->size() + number > this->capacity() * 2
                        ? this->size() + number
                        : this->capacity() * 2;
                pointer tmp = this->_allocator.allocate(allocated_size);
                size_type count = 0;
                iterator it = this->begin();
                size_type old_size = this->size();

                for(; it != position; it++, count++)
                    this->_allocator.construct(tmp + count, *it);
                for (InputIterator Iit = first; Iit != last; Iit++, count++)
                    this->_allocator.construct(tmp + count, *Iit);
                for (size_type i = 0; i < number; i++, count++)
                    this->_allocator.construct(tmp + count, *it);
                this->_destroy();
                this->_size = old_size + number;
                this->_capacity = allocated_size;
                this->_v = tmp;
            }
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

        reverse_iterator rbegin() { return reverse_iterator(this->end() - 1); }

        const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

        const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end() - 1); }
        // reverse iterator [ end ]

        //    destructor of the class
        ~vector() {
            for (size_type i = 0; i < this->size(); i++)
                this->_allocator.destroy(this->_v + i);
            this->_allocator.deallocate(this->_v, this->capacity());
        }

//    ! prototypes only
        void pop_back() {};

        void swap(vector &x) {
            (void) x;
        };

        iterator erase(iterator position) {
            (void) position;
            return iterator();

        }

        iterator erase(iterator first, iterator last) {
            (void) first;
            (void) last;
            return iterator();

        }

        allocator_type get_allocator() const {
            return this->_allocator;
        }


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

#endif // FT_CONTAINERS_VECTOR_HPP

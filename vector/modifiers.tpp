//
// Created by Hamza Chakoubi on 12/23/22.
//

#ifndef FT_CONTAINERS_MODIFIERS_TPP
#define FT_CONTAINERS_MODIFIERS_TPP

namespace ft {

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert( vector<T, Allocator>::const_iterator pos, const T& value )
    {
        vector<T, Allocator>::iterator it = this->end();
        it--;
        if(it >= pos)
        {
            T last = this->_v[this->_size - 1];
            while(it > this->begin())
            {
                *(it+1) = *it;
                if(it == pos)
                {
                    *it = value;
                    break;
                }
                it--;
            }
            this->push_back(last);
        }
        else
            this->push_back(value);
        return it;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert( vector<T, Allocator>::const_iterator pos, vector<T, Allocator>::size_type count, const T& value )
    {
        if(count < this->_capacity - this->_size)
        {
        vector<T, Allocator>::iterator new_end = this->end() + count - 1;
        vector<T, Allocator>::iterator end = this->end() - 1;
        vector<T, Allocator>::iterator new_pos = pos + count;
            if(pos >= this->end())
            {
                end++;
                for(vector<T, Allocator>::size_type i = 0; i < count; i++)
                {
                    *end = value;
                    end++;
                }
            }
            else
            {
                while (new_end >= this->begin()) {
                    if (new_pos == new_end) {
                        *new_end = *end;
                        end--;
                        new_end--;
                        for (vector<T, Allocator>::size_type i = 0; i < count; i++) {
                            *new_end = value;
                            new_end--;
                        }
                        break;
                    }
                    *new_end = *end;
                    end--;
                    new_end--;
                }
            }
            this->_size += count;
            return new_end;
        }
        else
        {
            T *tmp = this->_allocator.allocate(this->_size + count);
            vector<T, Allocator>::iterator begin = this->begin();
            vector<T, Allocator>::size_type counter = 0;
            while(begin < this->end() + count)
            {
                if(begin == pos)
                {
                    for(vector<T, Allocator>::size_type i = counter; i < counter + count; i++)
                        tmp[i] = value;
                    counter+=count;
                }
                tmp[counter] = *begin;
                begin++;
                counter++;
            }
            this->_allocator.destroy(this->_v);
            this->_allocator.deallocate(this->_v, this->_capacity);
            this->_v = tmp;
            this->_iterator.setPointer(tmp);
            this->_size += count;
            this->_capacity = this->size();
        }
        return pos;
    }
}


#endif //FT_CONTAINERS_MODIFIERS_TPP

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
}


#endif //FT_CONTAINERS_MODIFIERS_TPP

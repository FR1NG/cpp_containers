//
// Created by Hamza Chakoubi on 12/19/22.
//

#ifndef FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

template<typename T>
class reverse_iterator
{
    
public:
  reverse_iterator();
  reverse_iterator(reverse_iterator &&) = default;
  reverse_iterator(const reverse_iterator &) = default;
  reverse_iterator &operator=(reverse_iterator &&) = default;
  reverse_iterator &operator=(const reverse_iterator &) = default;
  ~reverse_iterator();

private:
  
};

reverse_iterator::reverse_iterator()
{
}

reverse_iterator::~reverse_iterator()
{
}
#endif //FT_CONTAINERS_VECTOR_REVERSE_ITERATOR_HPP

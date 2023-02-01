
#include <cstdlib>
#include <exception>
#include <iostream>
#include "vector.hpp"
#include "vector/iterator.hpp"
#include <string>
#include <vector>
#include "dev/helper.h"
#include <stack>

using std::cout;
using std::endl;
typedef ft::vector<int>::iterator iterator;
typedef ft::vector<int>::reverse_iterator  reverse_iterator;
typedef ft::vector<int>::const_reverse_iterator  const_reverse_iterator;
typedef  ft::vector<int> vector;
typedef std::vector<int>::iterator stditerator;
typedef std::vector<int>::reverse_iterator  stdreverse_iterator;
typedef  std::vector<int> stdvector;
//? to handle
/* ?
 * when capacity is zero
 *
 ? */

template <typename T>
std::vector<int> iterator_test(ft::vector<T> vector) {
    typename ft::vector<T>::iterator it;
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    it = vector.begin();
    v.push_back(*(++it));
    v.push_back(*(--it));
    v.push_back(*(it + 1));
    it += 1;
    v.push_back(*(it - 1));
    it -= 1;
    v.push_back(*it);
    return v;
}

void test()
{
  //   vector x;
  //   stdvector y;
  //   for (int i = 0; i < 500; ++i) {
  //       x.push_back(i);
  //       y.push_back(i);
  //   }

  // std::vector<int> ff = iterator_test(x);
  // vector test;
  // stdvector testjouj;

  // test = x;
  // testjouj = y;
  // print_vectors(testjouj, test, true);

      vector x(0, -1);
      stdvector y(0, -1);
  
      print_vectors(y, x, true);
}

int main()
{
  test();
  system("leaks test");
}




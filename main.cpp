
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

  stdvector sv;
  vector v;
  for(int i = 0; i < 3; i++)
    {
      sv.push_back(i);
      v.push_back(i);
    }

  stdvector sv2;
  vector v2;

  // sv2.reserve(30);
  // v2.reserve(30);
  // sv2.insert(sv2.begin() + 2, sv.begin(), sv.end());
  // v2.insert(v2.begin() + 2, v.begin(), v.end());
 
 // print_vectors(sv2, v2, true);
 //  sep();
 //  sv2.insert(sv2.begin() + 2, 0, 10);
 //  v2.insert(v2.begin() + 2, 0, 10);

 //  v2.insert(v2.begin(), 0, 64);
 //  v2.insert(v2.end(), 0, 64);
 //  v2.insert(v2.end(), 10, 64);
 //  v2.insert(v2.begin(), 5, -1);
 //  v2.insert(v2.begin() + 1, 1, -9);


 //  sv2.insert(sv2.begin(), 0, 64);
 //  sv2.insert(sv2.end(), 0, 64);
 //  sv2.insert(sv2.end(), 10, 64);
 //  sv2.insert(sv2.begin(), 5, -1);
 //  sv2.insert(sv2.begin() + 1, 1, -9);


  cout << *(sv2.insert(sv2.end(), 1337)) << " " << *(v2.insert(v2.end(), 1337)) <<endl;
  cout << *(sv2.insert(sv2.end(), 1337)) << " " << *(v2.insert(v2.end(), 1337)) <<endl;
  print_vectors(sv2, v2, true);
  
}

int main()
{
  test();
  // system("leaks test");
}




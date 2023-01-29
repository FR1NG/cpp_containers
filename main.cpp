
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

int main()
{
    vector x;
    stdvector y;
    for (int i = 0; i < 10; ++i) {
        x.push_back(i);
        y.push_back(i);
    }

  // print_vectors(y, x, true);
  // sep();
  // x.reserve(19);
  // y.reserve(19);
  // x.insert(x.begin() + 1,15);
  // y.insert(y.begin() + 1, 15);
  // print_vectors(y, x, true);

    stdvector sv;
    vector v;

    
    sv.swap(y);
    v.swap(x);
  
  print_vectors(sv, v, true);
  print_vectors(y, x, true);
}




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

void test()
{
  //   vector x;
  //   stdvector y;
  //   for (int i = 0; i < 10; ++i) {
  //       x.push_back(i);
  //       y.push_back(i);
  //   }

  // vector tv;
  // stdvector tsv;

  // tv.assign(1, 1337);
  // tsv.assign(1, 1337);
  // print_vectors(y, x, true);
  // print_vectors(tv, tsv, true);
  vector x;
  stdvector y;
  vector xprim(100, 100);
  stdvector yprim(100, 100);

  for (int i = 0; i < 10000; i++) {
    x.push_back(2);
    y.push_back(2);
  }
  for (int i = 0; i < 500; i++) {
    x.pop_back();
    y.pop_back();
  }
  x.assign(10, 15);
  y.assign(10, 15);
  x.assign(xprim.begin(), xprim.begin() + 5);
  y.assign(yprim.begin(), yprim.begin() + 5);
  print_vectors(y, y, true);
}

int main()
{
  test();
}




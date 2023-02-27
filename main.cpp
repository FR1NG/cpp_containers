
#include "dev/helper.h"
#include "helpers/pair.hpp"
#include "map.hpp"
#include "map/avl.hpp"
#include "vector.hpp"
#include "vector/iterator.hpp"
#include <cstddef>
// #include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
typedef ft::vector<int>::iterator iterator;
typedef ft::vector<int>::reverse_iterator reverse_iterator;
typedef ft::vector<int>::const_reverse_iterator const_reverse_iterator;
typedef ft::vector<int> vector;
typedef std::vector<int>::iterator stditerator;
typedef std::vector<int>::reverse_iterator stdreverse_iterator;
typedef std::vector<int> stdvector;
//? to handle
/* ?
 * when capacity is zero
 *
 ? */

int main() {

  std::vector<ft::pair<int, int>> pr;

  for (int i = 0; i < 14; i++)
    pr.push_back(ft::make_pair(i, i * 10));
  ft::map<int, int, std::less<int>, std::allocator<ft::pair<int, int> > > mp(
      pr.begin(), pr.end());
  // std::map<int, int, std::less<int>, std::allocator<std::pair<const int, int>
  // > > smp(pr.begin(), pr.end());

  // typedef std::map<int, int, std::less<int>, std::allocator<std::pair<const
  // int, int> > >::iterator  stdmapiterator;
  typedef ft::map<int, int, std::less<int>,
                  std::allocator<ft::pair<int, int>>>::iterator ftmapiterator;

  ft::pair<ftmapiterator, bool> p;
  p = mp.insert(ft::make_pair(12, 10));
  // ft::pair<ftmapiterator, bool> p = mp.insert(ft::make_pair(15, 10));

  std::cout << p.first->first << "    " << p.second << std::endl;
}

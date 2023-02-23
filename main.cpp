
#include "dev/helper.h"
#include "map.hpp"
#include "map/avl.hpp"
#include "vector.hpp"
#include "vector/iterator.hpp"
#include <cstddef>
// #include <cstdlib>
#include <exception>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <map>

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

void testMap() {
  std::map<int, int> m;

  m.insert(std::make_pair(10, 10));
  m.insert(std::make_pair(20, 10));
  m.insert(std::make_pair(5, 10));
  m.insert(std::make_pair(15, 10));
  m.insert(std::make_pair(22, 10));

  std::map<int,int>::iterator it = m.begin();
  while(it != m.end())
    {
      std::cout << "key : " << it->first << " value : " << it->second << std::endl;
      it++;
    }
  
}
void testAvl() {
 Avl<std::string, std::string, std::pair<std::string, std::string> > avl;

  avl.insert(std::make_pair("hello", "world"));
  std::cout << "size: " << avl.size() << " key " << avl.getRoot()->getKey() << " Value " << avl.getRoot()->getValue() << std::endl;
}

int main() {

  // testMap();
  std::vector<std::pair<int, int> > pr;
    
  for (int i = 0; i < 10; i++)
    pr.push_back(std::make_pair(i, i * 10));
  ft::map<int, int> mp(pr.begin(), pr.end());

  // std::cout << mp[4]  << std::endl;

  ft::map<int, int>::iterator it = mp.begin();
  // while(it != mp.end())
  //   {
  //     it++;
  //   }
  for(int i = 0; i < 10; i++, it++)
    std::cout << "key : " << it->first << " value: " << it->second << std::endl;


  // it.test();
  // it++;
  // it++;
  // std::cout << it->second << std::endl;

  // std::cout << mp.getTree()->getBiggest()->getKey() << std::endl;

}

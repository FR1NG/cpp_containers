
#include "vector.hpp"
#include "vector/reverse_iterator.hpp"
#include <iostream>
#include <string>
#include <vector>

void sep() { std::cout << "=============================" << std::endl; }

void test() {

  ft::vector<int> x;
  for(int i = 0; i < 10; i++)
    x.push_back(i + 1);
  ft::vector<int>::reverse_iterator it = x.rend();
  it--;
  std::cout << *it << std::endl;
  // rit++;
  // std::cout << *rit << std::endl;
  // std::reverse_iterator<int> z;
  // std::vector<int> w;
}

int main() {

  test();
  //    system("leaks progmar");
  // while(true);
}

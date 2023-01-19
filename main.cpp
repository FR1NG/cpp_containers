
#include "vector.hpp"
#include "vector/reverse_iterator.hpp"
#include <iostream>
#include <string>
#include <vector>

void sep() { std::cout << "=============================" << std::endl; }

void test() {

  ft::vector<std::string> x;
  ft::vector<std::string>::reverse_iterator rit = x.rend();
}

int main() {

  test();
  //    system("leaks progmar");
  // while(true);
}

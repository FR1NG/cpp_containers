
#include <iostream>
#include "vector.hpp"
#include "vector/iterator.hpp"
#include <string>
#include <vector>
#include "dev/helper.h"


// const std::string &test()
// {
//   const std::string str = "hello world";
//   return str;
// }

int main ()
{

 ft::vector<std::string> str;
  for(int i = 0; i< 12; i++)
    str.push_back("two hello world " + std::to_string(i + 1));

    // print_vector(str, true);
   typedef ft::vector<std::string>::const_iterator iterator;
  
  for(iterator it = str.begin(); it != str.end(); it++)
    std::cout << *it << std::endl;
}

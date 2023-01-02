#include "vector.hpp"

#include <vector>

#include "dev/helper.h"
#include <iterator>

#include <type_traits>

void sep()
{
    std::cout << "=============================" << std::endl;
}

template<typename T>
void test()
{
    std::vector<int> y(10, 10);

//   std::cout <<  ft::distance(y.begin(), y.end()) << std::endl;

    ft::vector<int> x(y.begin(), y.end());
    ft::vector<int> z(x);

    print_vector(z, true);

//    ft::enable_if<false, std::string>::type x = "10";

//    std::cout << x << std::endl;
}



int main() {

    test<int>();

}
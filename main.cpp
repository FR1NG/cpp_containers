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
    ft::vector<int> x(10, 10);
//    print_vector(x, true);

//    ft::enable_if<false, std::string>::type x = "10";

//    std::cout << x << std::endl;
}



int main() {

    test<int>();
//    system("leaks progmar");
}
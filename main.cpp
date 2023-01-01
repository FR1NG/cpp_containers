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
    ft::vector<int> x(y.begin(), y.end());
    std::vector<int> z(y.begin(), y.end());

    print_vector(y, true);
    print_vector(x, true);
    print_vector(z, true);

//    print_vector(x, true);

//    ft::enable_if<false, std::string>::type x = "10";

//    std::cout << x << std::endl;
}



int main() {

    test<int>();
//    system("leaks progmar");
}
#include "vector.hpp"

#include <vector>

#include "dev/helper.h"
#include <iterator>

#include <type_traits>

void sep()
{
    std::cout << "=============================" << std::endl;
}

void test()
{


    ft::vector<std::string> y;
    for(int i = 0; i < 10; i++)
        y.push_back("hello world: " + std::to_string(i));
    ft::vector<std::string> x(y.begin(), y.end());
    ft::vector<std::string> z(y.begin(), y.end());

    x.assign(y.begin(), y.end());
    z.assign(15, "negrito");
// !   x.assign(y.begin(), y.end());
// % dsfs 
// ? dsfs 
// tofix dsfs 
// todo
// tofix

// tofix this is to fix
    print_vector(z, true);
    sep();
    print_vector(x, true);

}



int main() {

    test();
    //    system("leaks progmar");
    //while(true);
}
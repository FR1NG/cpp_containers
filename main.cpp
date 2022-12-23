#include "vector/vector.hpp"


int main() {

    std::cout << "hello from progmar" << std::endl;

    ft::vector<int> x;

    x.push_back(10);
    x.push_back(15);

//    try {
//        ft::vector<int>::const_reference ref = x.at(0);
//        std::cout  << " well this is the const ref " << ref << std::endl;
//        std::cout << x.at(1) << std::endl;
//        std::cout << x.at(0) << std::endl;
//        std::cout << x.at(-1) << std::endl;
//    } catch (std::exception &e)
//    {
//        std::cout << e.what() << std::endl;
//    }

//    std::cout << x[1] << std::endl;
//    std::cout << x[0] << std::endl;
//
//    ft::vector<int>::const_reference ref = x[0];
//
//    std::cout << ref << std::endl;
//    std::cout << x.front() << std::endl;
//    std::cout << x.back() << std::endl;

    int *ptr = x.data();

    std::cout << ptr[1] << std::endl;
}
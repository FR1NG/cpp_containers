#include <iostream>

#include "trait.hpp"

int main()
{

    ft::enable_if<ft::is_integral<float>::value, float> x;
    std::cout << "is integral value: "<<  x  << std::endl;
}
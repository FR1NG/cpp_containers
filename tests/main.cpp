#include <iostream>

#include "trait.hpp"
#include "../dev/helper.h"
#include <vector>
#include <exception>


int main()
{

    std::vector<int> x(10, 10);

    print_vector(x, true);
    x.clear();
    print_vector(x, true);

}
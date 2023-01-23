//
// Created by Hamza Chakoubi on 12/30/22.
//

#ifndef FT_CONTAINERS_HELPER_H
#define FT_CONTAINERS_HELPER_H
#include <cmath>
#include <iostream>

void sep()
{
    std::cout << "===================================================" << std::endl;
}

template<typename T>
void print_vector(T &vec, bool printContent)
{
    std::cout <<  "capacity: " << vec.capacity() << " size: " << vec.size() << std::endl;
    std::cout << "=====================================" << std::endl;
    if (printContent)
    {
        for(typename T::iterator ix = vec.begin(); ix < vec.end(); ix++)
            std::cout << "value : " << *ix << std::endl;
    }
}


// int calculate(int x)
// {
    // return x == 9 ? 16 : pow(2, ceil(sqrtf(x)));
// }
#endif //FT_CONTAINERS_HELPER_H

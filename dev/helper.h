//
// Created by Hamza Chakoubi on 12/30/22.
//

#ifndef FT_CONTAINERS_HELPER_H
#define FT_CONTAINERS_HELPER_H
#include <cmath>
#include <iostream>
#include <iomanip>
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

template<class T, class U>
void print_vectors(T& v1, U& v2, bool printContent)
{
    std::cout <<  "capacity: " << v1.capacity() << " size: " << v1.size() << std::endl;
    std::cout <<  "capacity: " << v2.capacity() << " size: " << v2.size() << std::endl;
    std::cout << "=====================================" << std::endl;
    if (printContent)
    {
        typename T::iterator ix = v1.begin();
        typename U::iterator iy = v2.begin();
        while(ix != v1.end() && iy != v2.end())
        {
            std::cout << "vector 1 value : " << *ix  << std::setw(5) << "||"  << std::setw(20) << "vector 2 value : " << *iy ;
            std::cout << std::setw(10) <<  (*ix == *iy ? "\033[1;32m ok\033[0m" : "\033[1;31m failed\033[0m") << std::endl;
            ix++;
            iy++;
        }
    }
}

// int calculate(int x)
// {
    // return x == 9 ? 16 : pow(2, ceil(sqrtf(x)));
// }
#endif //FT_CONTAINERS_HELPER_H

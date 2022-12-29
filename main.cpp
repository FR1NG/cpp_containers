#include "vector/vector.hpp"

#include <vector>

int main() {

//    std::cout << "hello from progmar" << std::endl;
//
//    ft::vector<int> x;
//
//    x.push_back(10);
//    x.push_back(15);

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

//   x.insert(x.begin(), 10);

    {
        ft::vector<int> x;

        for (int i = 0; i < 3; i++)
            x.push_back((i + 1) * 10);

        ft::vector<int>::iterator it = x.begin();
        it++;
        x.insert(x.end(), 15);
        for (int i = 0; i < x.size(); ++i)
            std::cout << x[i] << std::endl;

        std::cout << "size : " << x.size() << std::endl;
        std::cout << "capacity : " << x.capacity() << std::endl;
    }
std::cout << "=============================" << std::endl;
    {
         std::vector<int> x;

        for (int i = 0; i < 3; i++)
            x.push_back((i + 1) * 10);

        std::vector<int>::iterator it = x.begin();
        it++;
        x.insert(x.end(), 15);
        for (int i = 0; i < x.size(); ++i)
            std::cout << x[i] << std::endl;

        std::cout << "size : " << x.size() << std::endl;
        std::cout << "capacity : " << x.capacity() << std::endl;
    }

}
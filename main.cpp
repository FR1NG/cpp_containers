#include "vector.hpp"

int main()
{
    Vector<int> v;

    Vector<int> j;

    v.push_back(10);
//    v.push_back(11);
//    j.push_back(5);

    j.push_back(10);
//    j.push_back(11);

    std::cout << (v > j) << std::endl;
}
#include "vector.hpp"

int main()
{
    Vector<std::string> v;

    v.push_back("hello world");

    Vector<std::string> j;

    j.push_back("hello world");
//    j.push_back("not equal");

    std::cout << (v != j) << std::endl;
}
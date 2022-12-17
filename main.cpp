#include "vector/vector.hpp"



int main()
{
    vector<std::string> x;

    for (int i = 0; i< 10; i++)
        x.push_back("hello world");

//    x.clear();
//
//    x.test();

    vector<std::string>::iterator it;
    it = begin;
    std::cout << *x.begin() << std::endl;
}
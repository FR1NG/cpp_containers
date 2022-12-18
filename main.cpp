#include "vector/vector.hpp"



int main()
{
    vector<std::string> x;

    for (int i = 0; i< 10; i++)
        x.push_back("hello world "+ std::to_string(i));

//    x.clear();
//
//    x.test();

//    vector<std::string>::iterator it;
//    it = x.begin();
    for(vector<std::string>::iterator it = x.begin();it != x.end() ; it++)
    {
        std::cout << *it << std::endl;
    }
}
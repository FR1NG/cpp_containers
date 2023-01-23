
#include <iostream>
#include "vector.hpp"
#include "vector/iterator.hpp"
#include <string>
#include <vector>
#include "dev/helper.h"
#include <deque>


typedef ft::vector<std::string>::iterator iterator;
typedef std::vector<std::string>::iterator siterator;
typedef ft::vector<std::string>::reverse_iterator  reverse_iterator;
typedef  ft::vector<std::string> fvector;
typedef  std::vector<std::string> svector;

int _ratio = 1;

template<class T>
void testVec(T &vector)
{
    std::vector<int> v;
//    vector.assign(9900 * _ratio, 1);
    vector.resize(5000 * _ratio);
//    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
//    vector.resize(15300 * _ratio, T());
//    v.push_back(vector.size());
//    v.push_back(vector.capacity());
//    v.push_back(vector[65]);
    print_vector(v, true);
}

//void test()
//{
//    svector x;
//    for (int i = 0; i < 10; ++i) {
//        x.push_back("hello " + std::to_string(i + 1));
//    }
//    fvector y;
//    for (int i = 0; i < 10; ++i) {
//        y.push_back("hello " + std::to_string(i + 1));
//    }
//
//
//    siterator it1 = x.begin();
////
//    siterator  it2 = x.end();
//    iterator it3 = y.begin();
////
//    iterator  it4 = y.end();
//
////std::cout << "std : " << it1 - it2 << std::endl;
////std::cout << "std : " << it3 - it4 << std::endl;
//
//reverse_iterator z(y.rbegin());
//}

int main ()
{
//    svector x(10, "hello world");
//
//    std::vector<std::string>::reverse_iterator it(x.begin());
//    it--;
//    std::cout<< *it << "<< here" << std::endl;

//    fvector vec(10, "ft::vector");
//    ft::vector<std::string>::reverse_iterator  it(vec.begin());

//    std::vector<int> x(10,10);
//
//    std::vector<int>::reverse_iterator it(x.begin());
//    it--;
//    std::cout << *it <<std::endl;


}

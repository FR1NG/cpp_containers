
#include <iostream>
//#include "vector.hpp"
#include "vector/iterator.hpp"
#include <string>
#include <vector>
#include "dev/helper.h"
#include <deque>

using std::cout;
using std::endl;
//typedef ft::vector<std::string>::iterator iterator;
//typedef ft::vector<std::string>::reverse_iterator  reverse_iterator;
//typedef  ft::vector<std::string> vector;
typedef std::vector<std::string>::iterator stditerator;
typedef std::vector<std::string>::reverse_iterator  stdreverse_iterator;
typedef  std::vector<std::string> stdvector;


//template<class T>
//void testVec(T &vector)
//{
//    std::vector<int> v;
////    vector.assign(9900 * _ratio, 1);
//    vector.resize(5000 * _ratio);
////    vector.reserve(5000 * _ratio);
//    v.push_back(vector.size());
//    v.push_back(vector.capacity());
//    vector.resize(7000 * _ratio);
//    v.push_back(vector.size());
//    v.push_back(vector.capacity());
////    vector.resize(15300 * _ratio, T());
////    v.push_back(vector.size());
////    v.push_back(vector.capacity());
////    v.push_back(vector[65]);
//    print_vector(v, true);
//}


int main ()
{
    stdvector x;
    for (int i = 0; i < 5; ++i) {
        x.push_back("inserted");
    }
    print_vector(x, true);
    x.insert(x.end(), 2, "inserted");
    print_vector(x, true);
}


#include <iostream>
#include "vector.hpp"
#include "vector/iterator.hpp"
#include <string>
#include <vector>
#include "dev/helper.h"
#include <deque>

using std::cout;
using std::endl;
typedef ft::vector<std::string>::iterator iterator;
typedef ft::vector<std::string>::reverse_iterator  reverse_iterator;
typedef  ft::vector<std::string> vector;
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

//? to handle
/* ?
 * when capacity is zero
 *
 ? */

template<class T>
void test(int init, int size, T &vec)
{
    for (int i = 0; i < init; ++i) {
        vec.push_back("pushed " + std::to_string(i));
    }
//    print_vector(vec, true);
    vec.insert(vec.end() + 3, size, "inserted");
    print_vector(vec, true);
}

int main ()
{
//    stdvector x;
//    vector y;

//    test(9, 3, x);
//    sep();
//    test(9, 3, y);

//    test(9, 3, y);
//    for (reverse_iterator rit= y.rbegin() - 1;  rit != y.rend(); rit++) {
//        std::cout << *rit << std::endl;
//    }
//
//    sep();
//
//    for (iterator it = y.begin(); it != y.end() ; it++) {
//        std::cout << *it << std::endl;
//    }

int i = 0;
for(; i<10;i++)
    cout << i << endl;
}

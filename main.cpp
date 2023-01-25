
#include <iostream>
#include "vector.hpp"
#include "vector/iterator.hpp"
#include <string>
#include <vector>
#include "dev/helper.h"
#include <stack>

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
    stdvector sv;
    for (int i = 0; i < 10; ++i) {
        sv.push_back("key " + std::to_string(i));
//        mp["key " + std::to_string(i)] = "value " + std::to_string(i);
    }

    vector v(5, "hello");
    stdvector sv2(5, "hello");


    v.insert(v.begin(), sv.begin(), sv.end());
    sv2.insert(sv2.begin(), sv.begin(), sv.end());


print_vectors<stdvector, vector>(sv2, v, true);
}

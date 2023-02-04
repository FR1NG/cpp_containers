
#include "dev/helper.h"
#include "vector.hpp"
#include "vector/iterator.hpp"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
typedef ft::vector<int>::iterator iterator;
typedef ft::vector<int>::reverse_iterator reverse_iterator;
typedef ft::vector<int>::const_reverse_iterator const_reverse_iterator;
typedef ft::vector<int> vector;
typedef std::vector<int>::iterator stditerator;
typedef std::vector<int>::reverse_iterator stdreverse_iterator;
typedef std::vector<int> stdvector;
//? to handle
/* ?
 * when capacity is zero
 *
 ? */

#define _ratio 10000
std::vector<int> push_back_test(vector vector) {
    std::vector<int> v;
    for (int i = 0; i < 1; ++i) {
        vector.push_back(i);
    }
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

std::vector<int> insert_test_3() {
    std::vector<int> v;
  ft::vector<A> vv;
  ft::vector<B*> v1;

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
  
    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}

void insert_test_4() {
  std::vector<A> vv;
  ft::vector<A> ss;
  std::vector<B*> v1;
  std::vector<int> res1;
  std::vector<int> res2;

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
  
    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    v1.push_back(&(*k4));
    // res1.push_back(10);
    // res2.push_back(10);
   try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
   catch (...) {
       res1.push_back(vv.size());
       res1.push_back(vv.capacity());
   }
   try { ss.insert(ss.begin(), v1.begin(), v1.end()); }
   catch (...) {
       res2.push_back(ss.size());
       res2.push_back(ss.capacity());
   }
    print_vectors(res1, res2, false);

}

void test() {
//  vector v;
//  stdvector sv;
//  v.push_back(137);
//  sv.push_back(137);
//  v.push_back(1337);
//  sv.push_back(1337);
//  v.push_back(1337);
//  sv.push_back(1337);
//  v.push_back(1337);
//  sv.push_back(1337);
//  v.insert(v.begin(), sv.begin(), sv.end());
//
//  print_vector(v, true);
 insert_test_4();
//  std::vector<int> y = insert_test_4();
//  print_vectors(y, x, true);
//  print_vectors(sv, v, true);

}

void jouj()
{
  test();
}

int main() {

  
  jouj();
 system("leaks test");
}

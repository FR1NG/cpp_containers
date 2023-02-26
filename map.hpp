#ifndef MAP_HPP
#define MAP_HPP
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include "map/avl.hpp"
#include "map/iterator.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
  public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef std::size_t size_type;
    typedef std::pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    // typedef look for it value_compare;
    typedef  Allocator allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef Avl<key_type, mapped_type, value_type, key_compare> tree;
    typedef map_iterator<typename tree::Node*> iterator;
  private:
    tree* tree_;
    allocator_type allocator_;
    key_compare key_compare_;

  public:
    explicit map(const key_compare &comp = key_compare(),
 const allocator_type &alloc = allocator_type()): tree_(new tree()), allocator_(alloc), key_compare_(comp) {}

    template <class InputIterator>
    map(InputIterator first, InputIterator last,
        const key_compare &comp = key_compare(),
        const allocator_type &alloc = allocator_type()):tree_(new tree()), allocator_(alloc), key_compare_(comp) {
        while (first != last) {
          tree_->insert(std::make_pair(first->first, first->second));
          first++;
        }
  }

    // map(const map &x) {}

  T operator[](const Key& key) {
    typename Avl<key_type, mapped_type, value_type>::node_pointer node = tree_->getRoot();
    while(node)
      {
        if (node->getKey() == key)
          return node->getValue();
        if (key_compare_(key, node->getKey()))
          node = node->getLeft();
        else
          node = node->getRight();
      }
    if(!node)
      throw std::runtime_error("not found");
    return node->getValue();
  }

  /*
   * modifiers
   */
  size_type erase( const Key& key ) {
    this->tree_->deleteNode(key);
    return 0;
  }

  /*
  * iteartors part
  */
  iterator begin() {
    return iterator(this->tree_->getSmallest());
  }

  iterator end() {
    return iterator(this->tree_->getEnd());
  }

  tree* getTree() {

    return this->tree_;
  }


  //  all test goes here 
  bool rootIsRoot() {
    return this->tree_->getRoot()->isRoot();
  }
};
}; // end of namespace  ft

#endif // !MAP_HPP

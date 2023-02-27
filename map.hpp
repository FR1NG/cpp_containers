#ifndef MAP_HPP
#define MAP_HPP
#include <cstddef>
#include <memory>
#include <stdexcept>
// #include <string>
// #include <utility>
#include "helpers/pair.hpp"
#include "map/avl.hpp"
#include "map/iterator.hpp"
#include "vector/iterator.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef std::size_t size_type;
  typedef typename Allocator::value_type value_type;
  typedef Compare key_compare;
  // typedef look for it value_compare;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef Avl<key_type, mapped_type, value_type, key_compare, Allocator> tree;
  typedef typename tree::node_pointer node_pointer;
  typedef typename tree::Node node_type;
  typedef map_iterator<typename tree::Node *> iterator;

private:
  tree *tree_;
  allocator_type allocator_;
  key_compare key_compare_;

public:
  explicit map(const key_compare &comp = key_compare(),
               const allocator_type &alloc = allocator_type())
      : tree_(new tree()), allocator_(alloc), key_compare_(comp) {}

  template <class InputIterator>
  map(InputIterator first, InputIterator last,
      const key_compare &comp = key_compare(),
      const allocator_type &alloc = allocator_type())
      : tree_(new tree()), allocator_(alloc), key_compare_(comp) {
    while (first != last) {
      this->tree_->insert(value_type(first->first, first->second));
      first++;
    }
  }

  map(const map &x)
      : tree_(new tree()), allocator_(x.allocator_),
        key_compare_(x.key_compare_) {
    for (iterator it = x.begin(); it != x.end(); it++)
      this->tree_->insert(value_type(it->first, it->second));
  }

  T operator[](const Key &key) {
    typename Avl<key_type, mapped_type, value_type>::node_pointer node =
        tree_->getRoot();
    while (node) {
      if (node->getKey() == key)
        return node->getValue();
      if (key_compare_(key, node->getKey()))
        node = node->getLeft();
      else
        node = node->getRight();
    }
    if (!node)
      throw std::runtime_error("not found");
    return node->getValue();
  }

  /*
   * modifiers
   */
  size_type erase(const Key &key) {
    this->tree_->deleteNode(key);
    return 0;
  }

  pair<iterator, bool> insert(const value_type &val) {
    node_pointer node = this->tree_->insert(val);

    if (!node) {
      node_pointer exist = this->tree_->findNode(val.first);
      return pair<iterator, bool>(iterator(exist), false);
    }
    return pair<iterator, bool>(iterator(node), true);
  }

  /*
   * iteartors part
   */
  iterator begin() { return iterator(this->tree_->getSmallest()); }

  iterator end() { return iterator(this->tree_->getEnd()); }

  //  all test goes here [=========
  bool rootIsRoot() { return this->tree_->getRoot()->isRoot(); }

  tree *getTree() { return this->tree_; }
  // end of test ==========]
};
}; // end of namespace  ft

#endif // !MAP_HPP

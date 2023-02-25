#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>
#include <utility>

template <class Key, class Value, class Type, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, Value> > >
class Avl {
public:
  typedef Type value_type;
  typedef value_type *pointer;
  typedef value_type &reference;
  typedef Allocator allocator_type;
  typedef size_t size_type;
  // Node class [ begin ] ==========================
  class Node {
  private:
    pointer data_;
    Node *left_;
    Node *right_;
    Node *parent_;
    Compare comparer_;

  public:
    typedef Type value_type;
    typedef value_type *data_pointer;
    typedef value_type &reference;
    typedef Key first_type;
    typedef Value second_type;

    Node(Compare &comp = Compare())
        : data_(NULL), left_(NULL), right_(NULL), parent_(NULL),
          comparer_(comp) {}

    Node(value_type data)
        : data_(new value_type(data)), left_(NULL), right_(NULL), parent_(NULL),
          comparer_(Compare()) {}

    value_type *data() { return this->data_; }

    Node *getLeft() const { return this->left_; }

    Node *getRight() const { return this->right_; }

    Node *getParent() const { return this->parent_; }

    bool hasRight() const { return this->right_; }

    bool hasLeft() const { return this->left_; }

    bool hasParent() const { return this->parent_; }

    bool isLeft() const {
      return (this->hasParent() && this == this->getParent()->getLeft());
    }

    bool isRight() const {
      return (this->hasParent() && this == this->getParent()->getRight());
    }

    bool isRoot() const {
      return (!this->hasParent());
    }

    void setLeft(Node *node) {
      this->left_ = node;
      if (node)
        node->setParent(this);
    }

    void setRight(Node *node) {
      this->right_ = node;
      if (node)
        node->setParent(this);
    }

    void setParent(Node *node) { this->parent_ = node; }

    Key getKey() const {
      if (!data_)
        throw std::runtime_error("trying to get key of null node");
      return this->data_->first;
    }

    Value getValue() const {
      if (!data_)
        throw std::runtime_error("trying to get value of null node");
      return this->data_->second;
    }

    bool operator<(const Node &node) {
      return comparer_(this->getKey(), node.getKey());
    }

    bool operator==(const Node &node) {
      return (this->getKey() == node.getKey());
    }
    ~Node() { delete data_; }
  };
  // node class [ end ] =================================

public:
  typedef Node *node_pointer;

private:
  Node *root_;
  size_type size_;
  allocator_type allocator_;
  node_pointer smallest_;
  node_pointer biggest_;

  void recursive_insert_(Node *node, Node *parent) {
    if (*node == *parent) {
      throw std::runtime_error("duplicated key");
    } else if (*node < *parent) {
      if (parent->getLeft())
        recursive_insert_(node, parent->getLeft());
      else
        parent->setLeft(node);
    } else {
      if (parent->getRight())
        recursive_insert_(node, parent->getRight());
      else
        parent->setRight(node);
    }
  }

public:

  Avl() : root_(NULL), size_(0), smallest_(NULL), biggest_(NULL) {}

  Avl(const value_type data) : root_(new Node(data)), size_(1), smallest_(NULL), biggest_(NULL) {} 

  size_type size() const { return this->size_; }

  node_pointer getRoot() const { return this->root_; }

  node_pointer getSmallest() const { return this->smallest_; }

  node_pointer getBiggest() const { return this->biggest_; }

  node_pointer insert_node(Node *newNode) {
    node_pointer root = this->root_;
    if (!root) {
      root_ = newNode;
      this->smallest_ = newNode;
      this->biggest_ = newNode;
      this->size_++;
      return newNode;
    }
    if (this->size() == 1) {
      if (*newNode < *root)
        root->setLeft(newNode);
      else if (*newNode == *root)
        throw std::runtime_error("duplicated key");
      else
        root->setRight(newNode);
      this->size_++;
    } else {
      this->recursive_insert_(newNode, root);
      this->size_++;
    }
    if(!this->smallest_)
      this->smallest_ = newNode;
    else if (newNode < this->smallest_)
        this->smallest_ = newNode;
    if(!this->biggest_)
      this->biggest_ = newNode;
    else if (this->biggest_ < newNode)
        this->biggest_ = newNode;
    return newNode;
  }

  Node *insert(const value_type data) {
    Node *newNode = new Node(data);
    try {
      newNode = insert_node(newNode);
      this->rebalence(newNode);
    } catch (...) {
      delete newNode;
      return NULL;
    }
    return newNode;
  }

  Node *insert(const Key &key, Value &value) {
    value_type data = this->allocator_.allocate(1);
    this->allocator_.construct(data, std::make_pair(key, value));
    return this->insert(data);
  }

  void rebalence(Node *node) {
    Node *currentNode = node;
    int factor = 0;
    int childFactor = 0;
    while (currentNode) {
      factor = this->getBalenceFactor(currentNode);
      if (factor > 1) {
        childFactor = this->getBalenceFactor(currentNode->getLeft());
        if (childFactor < 0) {
          this->rotateLeftRight(currentNode->getLeft());
        } else {
          this->rotateRight(currentNode);
        }
      } else if (factor < -1) {
        if (childFactor > 0) {
          this->rotateRightLeft(currentNode->getRight());
        } else {
          this->rotateLeft(currentNode);
        }
      }
      currentNode = currentNode->getParent();
    }
  }

  static int height(Node *node) {
    if (!node)
      return -1;
    int leftheight = height(node->getLeft());
    int rightheight = height(node->getRight());
    if (leftheight > rightheight)
      return leftheight + 1;
    return rightheight + 1;
  }
  static int getBalenceFactor(Node *node) {
    return (height(node->getLeft()) - height(node->getRight()));
  }

  void setRoot(Node *node) { 
    this->root_ = node;
    node->setParent(NULL);
  }

  Node *rotateLeft(Node *node) {
    // ! dont forget to handle if the parent is null;
    // getting the parent and the right child
    Node *child = node->getRight();
    Node *parent = node->getParent();

    // assinging the child to his el grande padre to become his padre
    if (parent) {
      node == parent->getRight() ? parent->setRight(child)
                                 : parent->setLeft(child);
    }

    if (child)
      node->setRight(child->getLeft());
    if (child)
      child->setLeft(node);
    node->setParent(child);
    if (child)
      child->setParent(parent);
    if (child && !child->getParent())
      this->setRoot(child);
    return node->getParent();
  }

  Node *rotateRight(Node *node) {
    Node *child = node->getLeft();
    Node *parent = node->getParent();

    node->setLeft(child ? child->getRight() : NULL);
    if (child)
      child->setParent(parent);
    if (parent) {
      node == parent->getRight() ? parent->setRight(child)
                                 : parent->setLeft(child);
    }
    if (child)
      child->setRight(node);
    node->setParent(child);
    if (child && !child->getParent())
      this->setRoot(child);
    return node->getParent();
  }

  Node *rotateLeftRight(Node *node) {
    Node *tmp = this->rotateLeft(node);
    return this->rotateRight(tmp->getParent());
  }

  Node *rotateRightLeft(Node *node) {
    Node *tmp = this->rotateRight(node);
    return this->rotateLeft(tmp->getParent());
  }
};

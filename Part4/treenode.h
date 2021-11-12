#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template <typename T> class TreeNode {
public:
  T data;
  unique_ptr<TreeNode<T>> leftChild;
  unique_ptr<TreeNode<T>> rightChild;
  TreeNode<T> *parent;
  explicit TreeNode(T dataIn) : data(dataIn) { parent = nullptr; }
  void setLeftChild(TreeNode<T> *child) {
    leftChild.reset(child);
    child->parent = this;
  }
  void setRightChild(TreeNode<T> *child) {
    rightChild.reset(child);
    child->parent = this;
  }
  void write(ostream &s) const {
    if (leftChild)
      leftChild->write(s);

    s << " " << data << " ";

    if (rightChild)
      rightChild->write(s);
  }
  int max(int a, int b) {
    return ((a >= b)? a : b);
  }
  int maxDepth() {
    if (!(leftChild || rightChild))
      return 1;
    else
      return 1 + max(leftChild.get()->maxDepth(), rightChild.get()->maxDepth());
  }
};

template <typename T> class TreeNodeIterator {
public:
  TreeNode<T> *current;
  explicit TreeNodeIterator(TreeNode<T> *currentIn) : current(currentIn) {}
  T &operator*() { return current->data; }
  TreeNodeIterator<T> operator++() {
    TreeNode<T> *newNode = current;
    while (newNode->data < current->data) {
      if (newNode->rightChild) {
        if (newNode->rightChild.get() != current)
          newNode = newNode->rightChild.get();
      } else
        newNode = newNode->parent;
    }
    current = newNode;
    return current;
  }
  bool operator==(const TreeNodeIterator &other) {
    return (current == other.current);
  }
  bool operator!=(const TreeNodeIterator &other) {
    return (current != other.current);
  }
};

// do not edit below this line

#endif

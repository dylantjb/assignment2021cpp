#ifndef TREE_H
#define TREE_H

#include "treenode.h"
// TODO your code goes here:
template <typename T> class BinarySearchTree {
private:
  unique_ptr<TreeNode<T>> root;

public:
  BinarySearchTree() = default;
  void write(ostream &s) const { root->write(s); }
  TreeNode<T> *insert(T data) {
    TreeNode<T> *newRoot = new TreeNode<T>(data);
    if (root == nullptr) {
      root.reset(newRoot);
      return newRoot;
    }
    TreeNode<T> *now = root.get();

    while (now != nullptr) {
      if (now->data < data) {
        if (now->rightChild.get())
          now = now->rightChild.get();
        else {
          now->setRightChild(new TreeNode<T>(data));
        }
      } else if (data < now->data) {
        if (now->leftChild.get())
          now = now->leftChild.get();
        else {
          now->setLeftChild(new TreeNode<T>(data));
        }
      } else
        return now;
    }
    return nullptr;
  }

  TreeNode<T> *find(T data) {
    TreeNode<T> *current = root.get();
    if (current == nullptr)
      return current;
    else {
      while (current != nullptr) {
        if (data < current->data) {
          if (current->leftChild) {
            current = current->leftChild.get();
          } else {
            current = nullptr;
          }
        } else if (current->data < data) {
          if (current->rightChild) {
            current = current->rightChild.get();
          } else {
            current = nullptr;
          }
        } else {
          return current;
        }
      }
      return current;
    }
  }
  TreeNodeIterator<T> begin() {
    TreeNodeIterator<T> itr(root.get());
    if (itr.current == nullptr) {
      return itr;
    } else {
      while (itr.current->leftChild) {
        itr.current = itr.current->leftChild.get();
      }
      return itr;
    }
  }
  TreeNodeIterator<T> end() {
    TreeNodeIterator<T> itr = nullptr;
    return itr;
  }
};
// do not edit below this line

#endif

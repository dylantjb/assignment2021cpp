#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

// Do not add any #include statements here.  If you have a convincing need for
// adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:

#include <initializer_list>

template <typename T> class LinkedList {

private:
  Node<T> *head;
  Node<T> *tail;
  int count;

public:
  LinkedList() : head(nullptr), tail(nullptr), count(0) {}
  explicit LinkedList(std::initializer_list<T> initList)
      : head(nullptr), tail(nullptr), count(0) {
    for (T e : initList)
      push_back(e);
  }
  ~LinkedList() {
    Node<T> *current = head;
    Node<T> *next;
    while (current != nullptr) {
      next = current->next;
      delete current;
      current = next;
    }
  }
  NodeIterator<T> &insert(NodeIterator<T> &itr, T element) {
    Node<T> *pos = itr.getPtr();
    Node<T> *temp = new Node<T>(element);
    Node<T> *prev = pos->previous;

    temp->next = pos;
    temp->previous = prev;
    pos->previous = temp;

    if (prev == nullptr)
      head = temp;
    else
      prev->next = temp;
    count++;
    return NodeIterator<T>(temp);
  }
  NodeIterator<T> erase(NodeIterator<T> &itr) {
    Node<T> *pos = itr.getPtr();
    Node<T> *prev = pos->previous;
    Node<T> *next = pos->next;

    if (prev == nullptr) {
      head = next;
    } else
      prev->next = next;
    if (next == nullptr) {
      tail = prev;
    } else
      next->previous = prev;
    delete pos;
    count--;
    return NodeIterator<T>(next);
  }
  void push_front(T data) {

    Node<T> *temp = new Node<T>(data);
    if (count != 0) {
      temp->next = head;
      head->previous = temp;
    }
    head = temp;
    if (count == 0) {
      tail = temp;
    }
    count++;
  }
  void push_back(T data) {
    Node<T> *temp = new Node<T>(data);
    if (count == 0) {
      head = temp;
    } else {
      temp->previous = tail;
      tail->next = temp;
    }
    tail = temp;
    count++;
  }
  const T &front() const { return head->data; }
  const T &back() const { return tail->data; }
  int size() { return count; }
  NodeIterator<T> begin() { return NodeIterator<T>(head); }
  NodeIterator<T> end() { return NodeIterator<T>(nullptr); }
  void reverse() {
    Node<T> *current = head;
    Node<T> *next;
    Node<T> *prev;
    Node<T> *temp;
    while (current != nullptr) {
      next = current->next;
      prev = current->previous;
      current->previous = next;
      current->next = prev;
      current = next;
    }
    temp = head, head = tail, tail = temp;
  };
};

// do not edit below this line

#endif

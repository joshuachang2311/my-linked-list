//
// Created by Joshua2018 on 2019/11/6.
//

#ifndef MY_LINKED_LIST__LINKEDLIST_H_
#define MY_LINKED_LIST__LINKEDLIST_H_

#include <vector>
#include <iostream>
#include <string>

class nullptr_exception : public std::exception {
public:
    const char* what() {
        return "Cannot access member of a nullptr";
    }
};

template<typename ValueType>
class MyListNode {
public:
    MyListNode();
    MyListNode(ValueType value, MyListNode<ValueType> *next);
    ValueType value_;
    MyListNode<ValueType> *next_;
};

template<typename ValueType>
class MyLinkedList {
public:
    MyLinkedList<ValueType>();
    explicit MyLinkedList(const std::vector<ValueType> &values);
    void push_front(ValueType value);
    void push_back(ValueType value);
    ValueType front() const;
    ValueType back() const;
    void pop_front();
    void pop_back();
    unsigned int size() const;
    bool empty() const;
    void clear();
    void print();
private:
    MyListNode<ValueType> *front_;
    unsigned int size_;
};

#endif //MY_LINKED_LIST__LINKEDLIST_H_

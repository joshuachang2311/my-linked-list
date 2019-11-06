#include "linkedlist.h"
#include "linkedlist.hpp"

int main() {
    MyLinkedList<int> list = MyLinkedList<int>();
    list.push_back(7);
    list.push_back(8);
    list.push_front(9);
    list.push_back(10);
    list.pop_front();
    list.pop_back();
    list.push_front(13);
    list.push_back(14);
    list.clear();
    list.print();
    return 0;
}
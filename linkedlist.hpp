//
// Created by Joshua2018 on 2019/11/6.
//

#include "linkedlist.h"

template<typename ValueType>
MyListNode<ValueType>::MyListNode() {
    value_ = ValueType();
    next_ = nullptr;
}

template<typename ValueType>
MyListNode<ValueType>::MyListNode(ValueType value, MyListNode<ValueType> *next) {
    value_ = value;
    next_ = next;
}

template<typename ValueType>
MyLinkedList<ValueType>::MyLinkedList() {
    front_ = nullptr;
    size_ = 0;
}

template<typename ValueType>
MyLinkedList<ValueType>::MyLinkedList(const std::vector<ValueType> &values) {
    front_ = nullptr;
    size_ = 0;
    for (ValueType value : values) {
        this->push_back(value);
    }
}

template<typename ValueType>
void MyLinkedList<ValueType>::push_front(ValueType value) {
    auto *newFront = new MyListNode<ValueType>(value, nullptr);
    if (size_ == 0) {
        front_ = newFront;
    } else {
        auto *oldFront = new MyListNode<ValueType>(front_->value_, front_->next_);
        delete front_;
        newFront->next_ = oldFront;
        front_ = newFront;
    }
    size_ += 1;
}

template<typename ValueType>
void MyLinkedList<ValueType>::push_back(ValueType value) {
    auto *newBack = new MyListNode<ValueType>(value, nullptr);
    if (size_ == 0) {
        front_ = newBack;
    } else {
        MyListNode<ValueType> *current = front_;
        while (true) {
            if (current->next_ == nullptr) {
                current->next_ = newBack;
                break;
            }
            current = current->next_;
        }
    }
    size_ += 1;
}

template<typename ValueType>
ValueType MyLinkedList<ValueType>::front() const {
    if (size_ == 0) {
        throw nullptr_exception();
    } else {
        return front_->value_;
    }
}

template<typename ValueType>
ValueType MyLinkedList<ValueType>::back() const {
    if (size_ == 0) {
        throw nullptr_exception();
    } else {
        MyListNode<ValueType> *current = front_;
        while (true) {
            if (current->next_ == nullptr) {
                return current->value_;
            }
            current = current->next_;
        }
    }
}

template<typename ValueType>
void MyLinkedList<ValueType>::pop_front() {
    if (size_ == 0) {
        return;
    } else if (size_ == 1) {
        delete front_;
        size_ = 0;
        return;
    }
    auto *newFront = new MyListNode<ValueType>(front_->next_->value_, front_->next_->next_);
    delete front_;
    front_ = newFront;
    size_ -= 1;
}

template<typename ValueType>
void MyLinkedList<ValueType>::pop_back() {
    if (size_ == 0) {
        return;
    } else if (size_ == 1) {
        delete front_;
        size_ = 0;
        return;
    }
    MyListNode<ValueType> *current = front_;
    while (true) {
        if (current->next_->next_ == nullptr) {
            delete current->next_;
            current->next_ = nullptr;
            break;
        }
        current = current->next_;
    }
    size_ -= 1;
}

template<typename ValueType>
unsigned int MyLinkedList<ValueType>::size() const {
    return size_;
}

template<typename ValueType>
bool MyLinkedList<ValueType>::empty() const {
    return size_ == 0;
}

template<typename ValueType>
void MyLinkedList<ValueType>::clear() {
    while (!(this->empty())) {
        this->pop_front();
    }
}

template<typename ValueType>
void MyLinkedList<ValueType>::print() {
    if (size_ == 0) {
        std::cout << "MyLinkedList(0): []\n";
        return;
    }
    std::string listString;
    MyListNode<ValueType> *current = front_;
    while (current != nullptr) {
        listString += std::to_string(current->value_);
        listString += ", ";
        current = current->next_;
    }
    std::cout << "MyLinkedList(" << size_ << "): [" << listString.substr(0, listString.size() - 2) << "]\n";
}

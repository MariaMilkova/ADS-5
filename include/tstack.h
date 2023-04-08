// Copyright 2021 NNTU-CS

#include <iostream>

#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T arr[size];
    int top;

 public:
    TStack() {
        top = -1;
    }
    bool isFull() const {
        return top == size;
    }
    bool isEmpty() const {
        return top == -1;
    }
    void push(T value) {
        if (isFull()) {
            std::cout << "Stack is Full" << "\n";
        } else {
            arr[++top] = value;
        }
    }
    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is Empty!" << "\n";
            return -1;
        } else {
            return arr[top--];
        }
    }
    T get() {
        if (isEmpty()) {
            std::cout << "Stack is Empty!" << "\n";
            return -1;
        } else {
            return arr[top];
        }
    }
};

#endif  // INCLUDE_TSTACK_H_

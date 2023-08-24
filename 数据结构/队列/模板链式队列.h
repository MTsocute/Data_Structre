//
// Created by Momo on 2023/8/10.
//

#ifndef DATASTRUCTURE_模板链式队列_H
#define DATASTRUCTURE_模板链式队列_H

#include <iostream>

using namespace std;


template<class T>
class MyQueue {
public:
    MyQueue();

    ~MyQueue();

    bool isEmpty() const;

    void enQueue(T data);

    T deQueue();

    void traversal() const;

private:
    // 嵌套类作为节点
    class Node {
    public:
        T data;
        Node *next;

        // Constructor Function
        Node(const T value) : data(value) {
            this->next = nullptr;
        }
    };

    Node *head;
    Node *rear;
};


#endif //DATASTRUCTURE_模板链式队列_H

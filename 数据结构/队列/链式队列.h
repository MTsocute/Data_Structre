//
// Created by Momo on 2023/7/15.
//

#ifndef DATASTRUCTURE_链式队列_H
#define DATASTRUCTURE_链式队列_H

#include <iostream>

struct Node {
    int data;
    Node *next;
};

struct lQueue {
    int length;             // 队列长度
    Node *front, *rear;     // 队头、尾指针
};

void ini_queue(lQueue &q) {
    q.front = nullptr;
    q.rear = nullptr;
    q.length = 0;
}

Node *newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}


void enqueue(lQueue &q, int data) {
    Node *new_node = newNode(data);
    // 创建第一个节点
    if (q.rear == nullptr and q.front == nullptr and q.length == 0) {
        q.front = new_node;
        q.rear = new_node;
        q.length += 1;
    }
    // 不是第一个节点，新的节点在最后
    q.rear->next = new_node;
    q.rear = q.rear->next;
    q.length += 1;
}

void deque(lQueue &q) {
    if (q.rear == q.front)
        return;
    Node * cur = q.front->next;
    free(q.front);
    q.front = cur;
    q.length -= 1;
}

void traverse(lQueue &q) {
    if (q.rear == q.front and q.length == 0)  // 队列为空
        return;
    Node * cur = q.front;
    while (cur != nullptr) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    }
    std::cout << "END" << std::endl;
}

#endif //DATASTRUCTURE_链式队列_H

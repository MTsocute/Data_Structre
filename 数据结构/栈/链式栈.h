//
// Created by Momo on 2023/7/13.
//

#ifndef DATASTRUCTURE_链式栈_H
#define DATASTRUCTURE_链式栈_H

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct linkStack {
    int length;
    Node *top;
};

Node *new_node(int data);

void push(linkStack *&s, int data);

void ini_stack(linkStack *&s);

void ini_stack(linkStack *&s) {
    s->top = nullptr;
    s->length = 0;
}

// 创建一个新的节点
Node *new_node(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void push(linkStack *&s, int data) {
    Node * newNode = new_node(data);
    /* 这里非常的重要 */
    newNode->next = s->top;     // 新的节点承接以前的东西
    s->top = newNode;       // 栈顶指针指向新的节点，新节点就是最顶上的那个了
    s->length += 1;
}

int pop(linkStack *&s) {
   int returnValue = -1;

    if (s->top == nullptr) {
        cout << "Stack is empty";
        return returnValue;
    }

    returnValue = s->top->data;
    Node * cur = s->top->next;
    free(s->top);
    s->top = cur;
    return returnValue;
}

#endif //DATASTRUCTURE_链式栈_H

//
// Created by Momo on 2023/7/7.
//

#ifndef DATASTRUCTURE_循环链表_H
#define DATASTRUCTURE_循环链表_H

#include <iostream>

using namespace std;

// A Node of linked list
struct Node {
    int data;
    Node *next;
};

void insert(Node * &head, Node * &rear, int data);    // 这个是指针引用，head 是一个Node * 类型的指针变量的引用

void traverse(Node * &head);

Node * newNode(int data);

void combine(Node * &rearA, Node* &headA, Node * &headB, Node * &rearB);

void delete_at_tail(Node *&head, Node *&rear);

void delete_at_tail(Node *&head, Node *&rear) {
    if (head == nullptr and rear == nullptr) {
        cout << "Linked list is empty\n";
        return;
    }
    Node * cur = head;
    // stop at the front node of last node
    while(cur->next != rear)
        cur = cur->next;
    delete rear;
    rear = cur;
    rear->next = head;
}

void combine(Node * &rearA, Node* &headA, Node * &headB, Node * &rearB) {
    rearA->next = headB;
    rearB->next = headA;
}

void insert(Node * &head, Node * &rear, int data) {
    if (head == nullptr) {
        head = newNode(data);
        rear = head;
        head->next = head;  // 循环链表特性，最后一个节点指向自己
    }
    else {
        Node * cur = head;
        // 利用最后一个节点指向头来判断是不是最后一个节点
        while (cur->next != head)
            cur = cur->next;
        cur->next = newNode(data);
        rear = cur->next;      // 尾指针指向最后一个节点
        rear->next = head;     // 新加入的尾节点指向头节点
    }
}

void traverse(Node * &head) {
    if (head == nullptr) {
        cout << "链表为空" << endl;
        return;
    }

    Node * cur = head;
    while (cur->next != head) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << cur->data << endl;
}

Node * newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}


#endif //DATASTRUCTURE_循环链表_H


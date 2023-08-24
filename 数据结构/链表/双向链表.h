//
// Created by Momo on 2023/7/10.
//

#ifndef DATASTRUCTURE_双向链表_H
#define DATASTRUCTURE_双向链表_H

#include <iostream>

using namespace std;

// 双向链表节点
struct Node {
    int data;
    Node *prior;   // 指向前一个节点
    Node *next;    // 指向后一个节点
};

// 双向链表
struct dulLinkedList {
    Node *head;
    Node *tail;
    int length;
};


Node *create_node(int data);

void add_node(dulLinkedList &list, int data);

void traverse_from_head(dulLinkedList &list);

void traverse_from_end(dulLinkedList &list);

void delete_at_tail(dulLinkedList *list);

// delete the last node of linked list
void delete_at_tail(dulLinkedList *list) {
    if (list->length == 0) {
        cout << "Linked list is empty\n";
        return;
    }

    Node *pre = list->tail->prior;
    delete list->tail;
    list->tail = pre;
    list->tail->next = nullptr;
    list->length -= 1;
}

// create a node and return a pointer points to it
Node *create_node(int data) {
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->prior = nullptr;
    newNode->data = data;
    return newNode;
}

// add a new node to tail
void add_node(dulLinkedList &list, int data) {
    Node *newNode = create_node(data);     // a new node
    // Linked list is Empty
    if (list.length == 0) {
        // only one node, so head and tail are the same node
        list.head = newNode;
        list.tail = newNode;
        list.length += 1;
        return;
    }
    // Add the new node to the end
    newNode->prior = list.tail;
    list.tail->next = newNode;
    // update the last node is new node
    list.tail = newNode;
    list.length += 1;
}

// display all nodes of linked list
void traverse_from_head(dulLinkedList &list) {
    if (list.length == 0) {
        cout << "The linked list is empty" << endl;
        return;
    }
    Node *cur = list.head;

    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// display all nodes but reverse
void traverse_from_end(dulLinkedList &list) {
    if (list.length == 0) {
        cout << "The linked list is empty" << endl;
        return;
    }
    Node *cur = list.tail;

    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->prior;
    }
    cout << endl;
}

#endif //DATASTRUCTURE_双向链表_H

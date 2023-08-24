//
// Created by Momo on 2023/7/6.
//

#ifndef DATASTRUCTURE_链表_H
#define DATASTRUCTURE_链表_H

#include <iostream>
#include <ctime>

using namespace std;


const int OK = 1;
const int ERROR = 0;

using namespace std;

typedef int Status;

// Node data
struct Node {
    int data;
    struct Node *next;
};

// Manage Link List
struct linkList {
    int length;
    struct Node *head;
};

// Initial Link List
Status ini_link_list(linkList &list, int number) {
    srand(time(nullptr));       // initialize random seed
    if (list.head == nullptr)
    {
        list.head = new Node;
        list.head->data = rand() % 100 + 1;   // generate random number from 1 to 100
        list.head->next = nullptr;

        Node *cur = list.head;     // start from the head

        for (int i = 0; i < number; ++i) {
            cur->next = new Node;
            cur = cur->next;
            cur->data = rand() % 100 + 1;
            cur->next = nullptr;
            list.length++;
        }
        return OK;
    }
    // when the node is not empty, we'll rewrite all nodes exclude first one
    else if (list.head != nullptr and list.length == 1)
    {
        list.length--;              // rewrite the first node, and we can't let it be accounted twice
        Node *cur = list.head;      // skip first node
        for (int i = 0; i < number; ++i) {
            cur->next = new Node;
            cur = cur->next;
            cur->data = rand() % 100 + 1;
            cur->next = nullptr;
            list.length++;
        }
        return OK;
    }
    else    // 处理异常情况
        return ERROR;
}

// add a new node into the end of link list
Status add_to_list_tail(linkList &lList, int new_elem) {
    /* when the list is empty */
    if (lList.head == nullptr and lList.length == 0) {
        lList.head = new Node;
        lList.head->data = new_elem;
        lList.head->next = nullptr;
        lList.length = 1;
        return OK;
    }
    /* when the list is not empty */
    else if (lList.length > 0 and lList.head != nullptr) {
        Node *current = lList.head;
        // Use nullptr to find the end of link list
        while (current->next != nullptr)
            current = current->next;
        current->next = new Node;
        current->next->data = new_elem;
        current->next->next = nullptr;
        // update the length
        lList.length++;
        return OK;
    } else { return ERROR; }
}

// show all elements in link list
void show_linklist(linkList &head) {
    /* when the link list is empty */
    if (head.head == nullptr)
        cout << "The list is empty" << endl;
    // pass the data of the head node
    Node *current = head.head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// delete all nodes from link list
void delete_all(linkList &list) {
    if (list.head == nullptr)
        cout << "The list is empty" << endl;
    else {
        Node *cur = list.head, *pre = nullptr;
        // we don't have to del cur
        // when cur reaches to nullptr, pre will point to the last node
        while (cur != nullptr) {
            pre = cur;
            cur = cur->next;
            delete pre;
        }
        list.head = nullptr;
    }
    list.length = 0;
}

// insert a new node into link list (index from 0)
Status insert_into_linklist(linkList &list, int index, int newNumber) {
    // control range from 0 to length - 1
    if (index < 0 or index >= list.length)
        return ERROR;

    /* new node*/
    Node *newNode = new Node;
    newNode->data = newNumber;

    Node *cur = list.head, *pre = nullptr;

    // the place before we want to insert
    for (int i = 0; i < index; i++) {
        pre = cur;
        cur = cur->next;
    }

    // when the place is head node
    if (pre == nullptr) {
        list.head = newNode;
        newNode->next = cur->next;
        delete cur;
        list.length++;
        return OK;
    }
    // add the node to the list
    pre->next = newNode;
    newNode->next = cur;
    list.length++;  // update the length
    return OK;
}

// delete the node from link list (index from 0)
Status delete_from_linklist(linkList &list, int index) {
    if (index < 0 or index >= list.length)
        return ERROR;
    Node *cur = list.head, *pre = nullptr;
    for (int i = 0; i < index; ++i) {
        pre = cur;
        cur = cur->next;
    }

    // when we delete the first node
    if (pre == nullptr)
        list.head = cur->next;
    // delete the node of index
    else
        pre->next = cur->next;

    delete cur;     // free the memory
    list.length--;
    return OK;
}

#endif //DATASTRUCTURE_链表_H

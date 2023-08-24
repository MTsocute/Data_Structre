//
// Created by Momo on 2023/8/10.
//

#include "模板链式队列.h"

int main() {
    MyQueue<int> q;

    q.enQueue(10);
    q.enQueue(20);

    q.deQueue();
    q.traversal();
}


template<class T>
MyQueue<T>::MyQueue() : head(nullptr), rear(nullptr) {}


template<class T>
MyQueue<T>::~MyQueue() {
    while(!isEmpty())
        this->deQueue();
}


template<class T>
bool MyQueue<T>::isEmpty() const {
    if (head == rear)
        return true;
    else
        return false;
}


template<class T>
void MyQueue<T>::enQueue(T data) {
    Node * newNode = new Node(data);
    if (this->head == nullptr)
        head = rear = newNode;
    rear->next = newNode;
    rear = newNode;
}


template<class T>
T MyQueue<T>::deQueue() {
    if (!this->isEmpty()) {
        Node *temp = this->head;
        T temp_data = this->head->data;

        this->head = this->head->next;
        delete temp;

        return temp_data;
    }
}


template <class T>
void MyQueue<T>::traversal() const {
    Node * cur = this->head;

    if (cur == nullptr)
        return;

    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}
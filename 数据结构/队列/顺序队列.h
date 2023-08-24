//
// Created by Momo on 2023/7/14.
//

#ifndef DATASTRUCTURE_顺序队列_H
#define DATASTRUCTURE_顺序队列_H

#include <iostream>

#define MAXSIZE 5

struct seQueue {
    int data[MAXSIZE];
    int front;          // 头指针
    int rear;           // 尾指针
};

void ini_queue(seQueue &q) {
    q.front = 0;
    q.rear = 0;
}

/* 列表计算长度的特殊点所在 */
int queue_len(seQueue &q) {
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

// 往队列中插入元素 -> rear
void enqueue(seQueue &q, int e) {
    /* 灵魂所在的判断是否满列
     * 但是正因为 rear + 1 来判断是够满，所以总会空一个位置
     * */
    if ((q.rear + 1) % MAXSIZE == q.front)  // 满列
        return;
    q.data[q.rear] = e;     // 对尾插入数据
    // 我们要考虑到就是 rear < front, 我们也得保证它在 0 ~ 4 的范围内
    q.rear = (q.rear + 1) % MAXSIZE;
}

// 从队列中删除一个元素 -> front
int dequeue(seQueue & q) {
    int return_Value;
    if (q.rear == q.front)  // 空栈，不可删
        return -1;
    return_Value = q.data[q.front];
    q.data[q.front] = 0;
    q.front = (q.front + 1) % MAXSIZE;  // 头指针移动向下一个位置
    return return_Value;
}

void traverse(seQueue & q) {
    using std::cout;
    using std::endl;
    if (q.front == q.rear)  // 空队列
        return;
    cout << "Start -> ";
    if (q.rear > q.front) {
        for (int i = q.front; i < q.rear; ++i)
            cout << q.data[i] << " -> ";
        cout << "End" << endl;
    }
    else if (q.rear < q.front) {
        for (int i = q.front; i < q.rear + MAXSIZE; ++i)
            cout << q.data[i % MAXSIZE] << " -> ";
        cout << "End" << endl;
    }
}

#endif //DATASTRUCTURE_顺序队列_H

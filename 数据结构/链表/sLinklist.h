//
// Created by Momo on 2023/7/6.
//

#ifndef DATASTRUCTURE_静态链表_H
#define DATASTRUCTURE_静态链表_H

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_SIZE = 5;  // 静态链表的最大容量

// 节点结构体
typedef struct {
    int data;
    int cur;  // 指向下一个节点的索引
} Component, SLinkList[MAX_SIZE];

// 初始化静态链表
void initialize_SLL(SLinkList &list) {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        // 初始化游标
        list[i].cur = i + 1;  // 每个节点的next指针指向下一个节点
    }
    list[MAX_SIZE - 1].cur = 0;  // 最后一个节点的 cur 为 0，表示链表结束
    list[0].cur = -1;
}

// 备用空间 (如果还有空间，下一个空间的下标作为当前的游标，如果没有位置就返回 0)
int find_free_space(SLinkList &list) {
    int index = list[1].cur;    // 当前位置的游标
    if (list[1].cur != -1)       // 当前不是 -1 说明还有空间可以申请
        list[1].cur = list[index].cur;  // 指向下一个存储的位置
    return index;   // 如果没有存储空间的话，返回的就是 0，反之返回可用空间的下标 index
}

// 插入一个节点
void add_node_to_SLL(SLinkList &list, int e) {
    int free_index = find_free_space(list);     // 获取一个备用空间的位置
    // 如果没有备用空间
    if (free_index == 0) {
        cout << "The list is full" << endl;
        return;
    }
    list[free_index].data = e;  // 插入数据到可用空间当中

    if (list[0].cur == -1)  // 当链表数据为空的时候
        list[free_index].cur = -1;  // 相当链表 .next == null
    else
        list[free_index].cur = list[0].cur; // 获取小的位置的地址

    list[0].cur = free_index;   // 更新头指针的位置就是插入的那个位置
}

// 输出静态链表元素
void traverse_SLL(const SLinkList &list) {
    int head = list[0].cur;  // 从第一个节点开始遍历
    while (head != -1) {
        printf("%d --> ", list[head].data);  // 打印当前节点的数据
        head = list[head].cur;  // 移动到下一个节点
    }
    cout << "NULL" << endl;
}


#endif //DATASTRUCTURE_静态链表_H

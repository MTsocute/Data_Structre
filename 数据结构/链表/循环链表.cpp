//
// Created by Momo on 2023/7/7.
//

#include "循环链表.h"


int main() {
    Node * headA = nullptr;
    Node * rearA = nullptr;

    // 在循环链表中插入节点
    insert(headA, rearA, 1);
    insert(headA, rearA, 2);
    insert(headA, rearA, 3);
    insert(headA, rearA, 4);

//    Node * headB = nullptr;
//    Node * rearB = nullptr;
//
//    // 在循环链表中插入节点
//    insert(headB, rearB, 5);
//    insert(headB, rearB, 6);
//    insert(headB, rearB, 7);
//    insert(headB, rearB, 8);


    // 合并两个链表
//    combine(rearA, headA, headB, rearB);

    // 删除尾巴节点
    delete_at_tail(headA, rearA);

    // 打印循环链表的节点
    traverse(headA);

    return 0;
}
//
// Created by Momo on 2023/7/21.
//

#ifndef DATASTRUCTURE_CHILD_EXPRESS_H
#define DATASTRUCTURE_CHILD_EXPRESS_H
#include <iostream>
#include <cstdio>

#define MAX_SIZE 20
#define TElemType char

using std::cout;
using std::cin;
using std::endl;

//孩子表示法
typedef struct CTNode {
    int child;//链表中每个结点存储的不是数据本身，而是数据在数组中存储的位置下标
    struct CTNode * next;
}ChildPtr;
typedef struct {
    TElemType data;//结点的数据类型
    ChildPtr* firstchild;//孩子链表的头指针
}CTBox;
typedef struct {
    CTBox nodes[MAX_SIZE];//存储结点的数组
    int n, r;//结点数量和树根的位置
}CTree;

//孩子表示法存储普通树
CTree initTree(CTree tree);

void findKids(CTree tree, char a);

#endif //DATASTRUCTURE_CHILD_EXPRESS_H

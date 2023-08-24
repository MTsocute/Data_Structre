//
// Created by Momo on 2023/7/31.
//

#ifndef DATASTRUCTURE_十字链表_H
#define DATASTRUCTURE_十字链表_H

#include <iostream>

using std::cout;
using std::endl;

static int VexNum = 0;


/* 边表节点 */
struct ArcNode {
    char tailVex;   // 逆邻接表
    char headVex;   // 邻接表
    ArcNode *headLink;  // 逆邻接表指向的下一个顶点的指针
    ArcNode *tailLink;  // 邻接表指向的下一个顶点的指针
};

/* 顶点表 */
struct vList {
    char data;
    ArcNode *first_in;
    ArcNode *first_out;
};


void iniCrossingLinkedList(vList v[], const char v_data[], int v_num);

void releaseCrossingLinkedList(vList v[]);

void addODEdge(vList v[], int v1, int v2);

void addIDEdge(vList v[], int v1, int v2);

ArcNode * newODNode(char data);

ArcNode * newIDNode(char data);

#endif //DATASTRUCTURE_十字链表_H

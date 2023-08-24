//
// Created by Momo on 2023/7/31.
//

#include "十字链表.h"

void iniCrossingLinkedList(vList v[], const char v_data[], int v_num) {
    VexNum = v_num;

    for (int i = 0; i < VexNum; ++i) {
        v[i].data = v_data[i];
        v[i].first_in = nullptr;
        v[i].first_out = nullptr;
    }
}

void addODEdge(vList v[], int v1, int v2) {
    if (v1 >=0 and v1 < VexNum and v2 >=0 and v2 < VexNum) {
        ArcNode * newNode = newODNode(v[v2].data);
        if (v[v1].first_out == nullptr)
            v[v1].first_out = newNode;
        else {
            ArcNode * nextNode = v[v1].first_out;
            v[v1].first_out = newNode;
            newNode->tailLink = nextNode;
        }
    }
    addIDEdge(v, v2, v1);
}

void addIDEdge(vList v[], int v1, int v2) {
    if (v1 >=0 and v1 < VexNum and v2 >=0 and v2 < VexNum) {
        ArcNode * newNode = newIDNode(v[v2].data);
        if (v[v1].first_in == nullptr)
            v[v1].first_in = newNode;
        else {
            ArcNode * nextNode = v[v1].first_in;
            v[v1].first_in = newNode;
            newNode->headLink = nextNode;
        }
    }
}

void releaseCrossingLinkedList(vList v[]) {
    for (int i = 0; i < VexNum; ++i) {
        // 释放顶点的出边表节点
        ArcNode *outNode = v[i].first_out;
        while (outNode) {
            ArcNode *nextOutNode = outNode->tailLink;
            delete outNode;
            outNode = nextOutNode;
        }

        // 释放顶点的入边表节点
        ArcNode *inNode = v[i].first_in;
        while (inNode) {
            ArcNode *nextInNode = inNode->headLink;
            delete inNode;
            inNode = nextInNode;
        }
    }
}

ArcNode * newODNode(char data) {
    ArcNode * temp = new ArcNode;
    temp->tailVex = '\0';
    temp->headVex = data;
    temp->tailLink = nullptr;
    temp->headLink = nullptr;
    return temp;
}

ArcNode * newIDNode(char data) {
    ArcNode * temp = new ArcNode;
    temp->tailVex = data;
    temp->headVex = '\0';
    temp->tailLink = nullptr;
    temp->headLink = nullptr;
    return temp;
}
//
// Created by Momo on 2023/8/1.
//

#ifndef DATASTRUCTURE_邻接多重表_H
#define DATASTRUCTURE_邻接多重表_H

#include <iostream>

using namespace std;

static int vexNum = 0;
static int edgeNum = 0;

// 边
struct arcNode {
    char vex1;
    arcNode * vex1Edge;
    char vex2;
    arcNode * vex2Edge;
};

// 顶点表
struct vexList {
    char data;
    arcNode * firstNode;
};


void iniVexList(vexList v[], const char vexName[], int v_num, int e_num);

void addEdgeToGraph(vexList v[], int v1_index, int v2_index);

void printGraph(const vexList* graph);

arcNode * newNode(char v1, char v2);

#endif //DATASTRUCTURE_邻接多重表_H

//
// Created by Momo on 2023/8/1.
//

#include "邻接多重表.h"


void iniVexList(vexList v[], const char vexName[],
                int v_num, int e_num) {
    vexNum = v_num;
    edgeNum = e_num;

    for (int i = 0; i < vexNum; ++i) {
        v[i].data = vexName[i];
        v[i].firstNode = nullptr;
    }
}


arcNode * newNode(char v1, char v2) {
    auto * newArc = new arcNode;
    newArc->vex1 = v1;
    newArc->vex2 = v2;
    newArc->vex1Edge = nullptr;
    newArc->vex2Edge = nullptr;
    return newArc;
}


void addEdgeToGraph(vexList v[], int v1_index, int v2_index) {
    arcNode* newArc = newNode(v[v1_index].data, v[v2_index].data);

    /* 主要思路就是，我们建立边，边两头都是顶点
     * 两端顶点存自己上一次所在的边，没有就是 null，新的边的关系用头插插入
     * 顶点表就是指向最上层的边
     * */

    newArc->vex1Edge = v[v1_index].firstNode;
    v[v1_index].firstNode = newArc;

    newArc->vex2Edge = v[v2_index].firstNode;
    v[v2_index].firstNode = newArc;
}


void printGraph(const vexList* graph) {
    std::cout << "Adjacency Multi-List Representation of the Graph:" << std::endl;
    for (int i = 0; i < vexNum; i++) {
        std::cout << "Vertex " << graph[i].data << ": ";
        arcNode* current = graph[i].firstNode;
        while (current) {
            std::cout << "(" << current->vex1 << "," << current->vex2 << ") ";
            current = current->vex1Edge;
        }
        std::cout << std::endl;
    }
}
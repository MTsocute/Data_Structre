//
// Created by Momo on 2023/7/30.
//

#ifndef DATASTRUCTURE_邻接表_H
#define DATASTRUCTURE_邻接表_H

#include <iostream>
#include <queue>

#define MAX_VERTEXS 5
#define MAX_WEIGHTS 10086

using namespace std;

static int vertexNum = 0;
static int edgeNum = 0;


/* 边表 */
struct ArcNode {
    int weight;
    char adjVex;
    ArcNode * next;
};

/* 顶点表 */
struct VertexNode {
    char vertex;
    ArcNode * firstEdge;
};

void ini_Graph(VertexNode g[], const char vList [], int v_num, int e_num);

void createGraph(VertexNode g[], int v1_index, int v2_index);

void addEdgeWithWeight(VertexNode g[], int v1_index, int v2_index, int weight);

void destroyGraph(VertexNode g[]);

ArcNode * newArcNode(char v);

void DFS(const VertexNode g[], bool visited[], int i);

void depthFirstSearch(const VertexNode g[]);

void breadthFirstSearch(const VertexNode g[]);

void BFS(const VertexNode g[], bool visited[], queue<char> &q);

/**
 * @brief 传入顶点的字符，知道其在字符串的下标
 * @param g 邻接表
 * @param targetVertex 顶点的字符串
 * */
int findVertexIndex(const VertexNode g[], char targetVertex);

int findMiniIndex(const int adjVex[], const bool inMST[]);

void show_MST(const int  parent[], const int adjVexWeight[]);

void MiniSpanTreePrim(const VertexNode g[]);

#endif //DATASTRUCTURE_邻接表_H

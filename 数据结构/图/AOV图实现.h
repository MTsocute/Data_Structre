//
// Created by Momo on 2023/8/18.
//

#ifndef DATASTRUCTURE_AOV图实现_H
#define DATASTRUCTURE_AOV图实现_H

#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int MAX_VERTEX_NUMS = 10;

/* 边节点 */
struct EdgeNode {
    int adjVex;     // 存储邻接的顶点的下标位置
    int weight;
    EdgeNode *next;
};


/* 顶点需要有入度 */
struct VexNode {
    int in;
    char data;
    EdgeNode *firstNode;
};


/* 邻接表实现的有向图 */
struct graphAdjList {
    int edgeNum, vexNum;
    VexNode adjList[MAX_VERTEX_NUMS];  // 邻接表
};


/**
 * @brief 用于初始化图
 * */
void initGraphAdjList(graphAdjList &g, const char vex_data[], int e_num, int v_num);

/**
 * @brief 用于创建新的边
 * */
EdgeNode *newNode(graphAdjList &g, int to, int Weight = 0);


/**
 * @brief 创建带有权的边
 * */
void addEdgeWithWeight(graphAdjList &g, int from, int to, int Weight);


/**
 * @brief 创建没有权的边
 * */
void addEdgeWithoutWeight(graphAdjList &g, int from, int to);


/**
 * @brief 删除邻接表
 * */
void clearAdjList(graphAdjList &g);


/**
 * @brief AOV 排序图
 * */
void AOV_sort(graphAdjList &g);
void show_AOV_sort(const graphAdjList &g, const string &sort_seq);


/**
 * @brief 实现时间最早发生时间和最迟发生时间的数组
 * */
void calculateEarliestLatest(graphAdjList & g, int ve[], int vl[]);

/**
 * @brief 实现找到关键路径
 * */
void criticalPath(graphAdjList & g);


/**
 * @brief 输出关键路径
 * */
void printCriticalPath(const graphAdjList & g, const int ve[], const int vl[]);


#endif //DATASTRUCTURE_AOV图实现_H

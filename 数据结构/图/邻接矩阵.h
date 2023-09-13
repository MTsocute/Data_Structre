//
// Created by Momo on 2023/7/30.
//

#ifndef DATASTRUCTURE_邻接矩阵_H
#define DATASTRUCTURE_邻接矩阵_H

#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

const int MAX_VERTEX = 10;  // Greatest number of Graph
const int MAX_WEIGHT = 100000;  // Max weight to find minimum one

struct MGraph {
    char vertex[MAX_VERTEX];             // Edge Vertex
    int arc[MAX_VERTEX][MAX_VERTEX];     // Adjacency Matrix
};

/* 存储图的一条边 */
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

static int vertex_num = 0;  // 顶点的数量
static int arcNum = 0;      // 边的个数

/**
 * @brief 初始化图
 * @param g 图的结构体
 * @param e_num 边的数量
 * @param v_num 顶点的数量
 * @param vertex 存储顶点的一维数组
 * */
void initGraph(MGraph &g, const char vertex[], int v_num, int e_num);


/**
 * @brief 通过手动输入给顶点加边，形成图
 * @param g 图的结构体
 * */
void addEdge(MGraph &g);


/**
 * @brief 通过参数输入顶点的下标记，形成图
 * @param g 图的结构体
 * @param v1 第一个顶点的下标
 * @param v2 第二个顶点的下标
 * */
void addEdge2(MGraph &g, int v1, int v2);


/**
 * @brief 也是通过下标行程图，但是不是用 1 标记有联系关系，而是标记权
 * @param weight 两个顶点之间的权
 * */
void addEdgeWithWeight(MGraph &g, int v1, int v2, int weight);

/**
 * @brief 这个是网图，有方向的要注意
 * @param weight 两个顶点之间的权
 * @param v1 从哪里开始
 * @param v2 到哪里结束
 * */
void addWeightNet(MGraph &g, int v1, int v2, int weight);

/**
 * @brief 打印邻接矩阵（字符串图形化显示）
 * @param graph 图的结构体
 * */
void printAdjacencyMatrix(const MGraph &graph);


/**
 * @brief 使用这个接口实现深度遍历数组
 * @param g 放入邻接矩阵
 * */
void depthFirstSearch(const MGraph &g);


/**
 * @brief 使用这个接口实现深度遍历数组
 * @param g 放入邻接矩阵
 * @param i 从哪里开始遍历的
 * @param visited 查询试过被访问过的表
 * */
void DFS(const MGraph &g, bool visited[], int i);


/**
 * @brief 广度优先遍历的辅助方法
 * */
void BFS(const MGraph &g, bool visited[], int i, queue<char> &q);


/**
 * @brief 使用广度优先遍历的接口
 * @param g 邻接矩阵结构体
 * */
void breadthFirstSearch(const MGraph &g);


/**
 * @brief Prim算法实现最小生成树
 * */
void MiniSpanTree_Prim(const MGraph &g);

int findMinKey(const int adjVex[], const bool inMST[]);

void show_MST(const MGraph &g, const int parent[]);


/**
 * @brief 转换邻接矩阵成为边的结构体
 * @param g 邻接矩阵
 * */
Edge *adjMatrixToEdgeList(const MGraph &g);


/**
 * @brief 展示边表中的所有边
 * @param edgeLists 边表
 * */
void printEdgeData(const Edge *edgeLists);


/**
 * @brief Kruskal 最小树生成
 * @param edgeLists 边表
 * */
Edge *kruskal_MST(Edge *edgeLists);


/**
 * @brief 辅助边表实现按 weight 升序
 * @param edgeList 边表
 * @param start 数组的开始index
 * @param end 数组的结尾index
 * */
void quickSort(Edge *edgeList, int start, int end);


/**
 * @brief 寻找某一个节点的更节点 index
 * @param cur 需要找根节点的节点 index
 * @param parent 父节点集，用于寻找根节点
 * */
int findRoot(const int parent[], int cur);


/**
 * @brief Kruskal方法下的最小树的输出
 * */
void printMSTByKruskal(Edge *MST);


/**
 * @brief 这里不是那么严谨，我们的图是所有点都有联系的，然后我们算的是所有点之间的最小路径
 * @param scr 出发点的下标位置
 * */
void dijkstra(MGraph &g, int src);

void printShortestPaths(MGraph &g, int adjVex[], int src);

/**
 * @brief 弗洛伊德最短路径算法实现
 * */
void floydWarshall(MGraph &g);

void printMatrix(const int dist[][vertex_num]);

#endif //DATASTRUCTURE_邻接矩阵_H

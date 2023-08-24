//
// Created by Momo on 2023/7/30.
//

//#include "邻接多重表.h"
//#include "邻接表.h"
#include "邻接矩阵.h"
#include "AOV图实现.h"

void demo1() {
    char vertexList[MAX_VERTEX] =
            {'A', 'B', 'C', 'D', 'E', 'F'};

    MGraph g = {};  // 邻接矩阵
//    initGraph(g, vertexList, 6, 9);
//    addEdgeWithWeight(g, 0, 1, 34);
//    addEdgeWithWeight(g, 0, 2, 46);
//    addEdgeWithWeight(g, 0, 5, 19);
//    addEdgeWithWeight(g, 1, 4, 12);
//    addEdgeWithWeight(g, 2, 3, 17);
//    addEdgeWithWeight(g, 2, 5, 25);
//    addEdgeWithWeight(g, 3, 4, 38);
//    addEdgeWithWeight(g, 3, 5, 25);
//    addEdgeWithWeight(g, 4, 5, 26);

//    initGraph(g, vertexList, 3, 3);
//
//    addEdgeWithWeight(g,0, 1, 5);
//    addEdgeWithWeight(g,0, 2, 12);
//    addEdgeWithWeight(g,1, 2, 47);

//    MiniSpanTree_Prim(g);
}

void demo2() {
    char vertexList[MAX_VERTEX] =
            {'A', 'B', 'C', 'D', 'E', 'F'};
//    VertexNode graph[MAX_VERTEXS];  // 邻接表
//    ini_Graph(graph, vertexList, 3, 3);
//    addEdgeWithWeight(graph, 0, 1, 5);
//    addEdgeWithWeight(graph, 0, 2, 12);
//    addEdgeWithWeight(graph, 1, 2, 47);

//    breadthFirstSearch(graph);

//    MiniSpanTree_Prim(g);

//    MiniSpanTreePrim(graph);
//
//    destroyGraph(graph);

}

// 使用 Floyd 算法构建最小路径
void demo3() {
    char charVex[3] = {'a', 'b', 'c'};
    MGraph g = {};
    initGraph(g, charVex, 3, 5);

    addWeightNet(g, 0, 1, 4);
    addWeightNet(g, 1, 0, 6);
    addWeightNet(g, 0, 2, 11);
    addWeightNet(g, 2, 0, 3);
    addWeightNet(g, 1, 2, 2);

//    printAdjacencyMatrix(g);

    floydWarshall(g);
}

// 实现 Dijskra 算法
void demo4() {
    char vertexList[MAX_VERTEX] =
            {'A', 'B', 'C', 'D', 'E', 'F'};

    MGraph g = {};  // 邻接矩阵
    initGraph(g, vertexList, 5, 6);

    addWeightNet(g, 0, 1, 2);
    addWeightNet(g, 0, 2, 4);
    addWeightNet(g, 1, 2, 1);
    addWeightNet(g, 1, 3, 7);
    addWeightNet(g, 2, 3, 3);
    addWeightNet(g, 2, 4, 5);
    addWeightNet(g, 3, 4, 1);

//    printAdjacencyMatrix(g);

    dijkstra(g, 0);
}

// 实现 AOV 排序
void demo5() {
    char vex_data[5] = {'A', 'B', 'C', 'D', 'E'};
    graphAdjList g = {0, 0, {}};
    initGraphAdjList(g, vex_data, 5, 4);

    addEdgeWithoutWeight(g, 0, 1);
    addEdgeWithoutWeight(g, 0, 2);
    addEdgeWithoutWeight(g, 1, 2);
    addEdgeWithoutWeight(g, 1, 3);
    addEdgeWithoutWeight(g, 2, 3);

    AOV_sort(g);

    clearAdjList(g);
}

// 实现关键路径
void demo6() {
    char vex_data[6] =
            {'A', 'B', 'C', 'D', 'E', 'F'};
    graphAdjList g = {0, 0, {}};
    initGraphAdjList(g, vex_data, 8, 6);

    addEdgeWithWeight(g, 0, 1, 3);
    addEdgeWithWeight(g, 0, 2, 2);

    addEdgeWithWeight(g, 1, 3, 2);
    addEdgeWithWeight(g, 1, 4, 3);

    addEdgeWithWeight(g, 2, 3, 4);
    addEdgeWithWeight(g, 2, 5, 3);

    addEdgeWithWeight(g, 3, 5, 2);
    addEdgeWithWeight(g, 4, 5, 1);

    criticalPath(g);
}

int main() {
    demo6();
    return 0;
}
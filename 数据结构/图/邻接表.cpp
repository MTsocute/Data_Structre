//
// Created by Momo on 2023/7/30.
//

#include "邻接表.h"

void ini_Graph(VertexNode g[], const char vList [], int v_num, int e_num) {
    vertexNum = v_num;
    edgeNum = e_num;
    // 初始化变边表的数据
    for (int i = 0; i < vertexNum; ++i) {
        g[i].vertex = vList[i];
        g[i].firstEdge = nullptr;
    }
}

void createGraph(VertexNode g[], int v1_index, int v2_index) {
    if (v1_index >= 0 and v1_index < vertexNum
        and v2_index >= 0 and v2_index < vertexNum) {
        // 建立与顶点之间的边关系
        ArcNode * newNode = newArcNode(g[v2_index].vertex);
        // 处理为空的情况
        if (g[v1_index].firstEdge == nullptr) {
            g[v1_index].firstEdge = newNode;
        }
        // 新的顶点就插入到最前面的位置(快)
        else {
            ArcNode * head = g[v1_index].firstEdge;
            ArcNode * rear = head->next;
            head->next = newNode;
            newNode->next = rear;
        }
    }
}

ArcNode * newArcNode(char v) {
    ArcNode * temp = new ArcNode;
    temp->adjVex = v;
    temp->next = nullptr;
    return temp;
}

void destroyGraph(VertexNode g[]) {
    if (g == nullptr)
        return;

    for (int i = 0; i < vertexNum; ++i) {
        ArcNode* pre = g[i].firstEdge;
        while (pre != nullptr) {
            ArcNode* cur = pre->next;
            delete pre;
            pre = cur;
        }
        g[i].firstEdge = nullptr; // 将顶点的 firstEdge 置空
    }
}

void depthFirstSearch(const VertexNode g[]) {
    bool visited[MAX_VERTEXS] = {false};

    for (int i = 0; i < vertexNum; ++i)
        if (!visited[i])
            DFS(g, visited, i);
    cout << endl;
}

void DFS(const VertexNode g[], bool visited[], int i) {
    visited[i] = true;
    cout << g[i].vertex << " ";
    ArcNode * cur = g[i].firstEdge;

    // 不能把这个节点是否遍历过的判断放到这里，链表找不到前驱节点，就找不到后续位置
    // 那么我们遍历不到这个链表的最后一个位置，可能会遗落
    while (cur != nullptr) {
        // 我们顶点表字母排序是按顺序的，所以我们可以利用差算出他在那个位置
        int index = toupper(cur->adjVex) - 'A';
        if (!visited[index])
            DFS(g, visited, index);
        cur = cur->next;
    }
}

void breadthFirstSearch(const VertexNode g[]) {
    bool visited[MAX_VERTEXS] = {false};
    queue<char> q;
    for (int i = 0; i < vertexNum; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            cout << g[i].vertex << " ";
            q.push(g[i].vertex);
            BFS(g, visited, q);
        }
    }
    cout << endl;
}

void BFS(const VertexNode g[], bool visited[], queue<char> &q) {
    while (!q.empty()) {
        int cur_node_index = toupper(q.front()) - 'A';
        q.pop();
        ArcNode * node = g[cur_node_index].firstEdge;
        while (node != nullptr) {
            int index = toupper(node->adjVex) - 'A';
            if (!visited[index]) {
                visited[index] = true;
                cout << g[index].vertex << " ";
                q.push(g[index].vertex);
            }
            node = node->next;
        }
    }
}

int findVertexIndex(const VertexNode g[], char targetVertex) {
    for (int i = 0; i < vertexNum; ++i) {
        if (g[i].vertex == targetVertex)
            return i;  // 找到目标顶点，返回索引
    }
    return -1;  // 未找到目标顶点，返回 -1 表示错误
}

void addEdgeWithWeight(VertexNode g[], int v1_index, int v2_index, int weight) {
    if (v1_index >= 0 and v1_index < vertexNum
        and v2_index >= 0 and v2_index < vertexNum) {
        // 建立与顶点之间的边关系
        ArcNode * newNode = newArcNode(g[v2_index].vertex);
        newNode->weight = weight;
        // 处理为空的情况
        if (g[v1_index].firstEdge == nullptr) {
            g[v1_index].firstEdge = newNode;
        }
            // 新的顶点就插入到最前面的位置(快)
        else {
            ArcNode * head = g[v1_index].firstEdge;
            ArcNode * rear = head->next;
            head->next = newNode;
            newNode->next = rear;
        }
    }
}

void MiniSpanTreePrim(const VertexNode g[]) {
    int parent[vertexNum];          // 存储最小生成树的父节点
    int adjVexWeight[edgeNum];      // 存储顶点到最小生成树的最小权值
    bool inMST[vertexNum];          // 记录顶点是否在最小生成树中

    // 初始化
    for (int i = 0; i < vertexNum; ++i) {
        adjVexWeight[i] = MAX_WEIGHTS;
        inMST[i] = false;
        parent[i] = 0;
    }

    // 从顶点表开始
    adjVexWeight[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < vertexNum - 1; ++i) {
        // 从邻接点中找出权值最小的那个
        int min_index = findMiniIndex(adjVexWeight, inMST);

        cout << "min = " << min_index << endl;
        inMST[min_index] = true;
        ArcNode * edge =  g[min_index].firstEdge;   // 最小值的所有边

        while (edge != nullptr) {
            int e_index = findVertexIndex(g, edge->adjVex);
            if (!inMST[e_index] and edge->weight < adjVexWeight[e_index]) {
                parent[e_index] = min_index;
                adjVexWeight[e_index] = edge->weight;
            }
            edge = edge->next;
        }
    }
    show_MST(parent, adjVexWeight);
}

int findMiniIndex(const int adjVex[], const bool inMST[]) {
    int min_value = MAX_WEIGHTS;
    int min_index = -1;
    for (int i = 0; i < vertexNum; ++i) {
        if (inMST[i] == false and adjVex[i] < min_value) {
            min_value = adjVex[i];
            min_index = i;
        }
    }
    return min_index;
}

void show_MST(const int  parent[], const int adjVexWeight[]) {
    cout << "Edge    Weight" << endl;
    for (int i = 1; i < vertexNum; ++i) {
        cout << parent[i] << " - " << i << "    "
             << adjVexWeight[i] << endl;
    }
}
//
// Created by Momo on 2023/7/30.
//

#include "邻接矩阵.h"

void initGraph(MGraph &g, const char vertex[], int v_num, int e_num) {
    vertex_num = v_num;
    arcNum = e_num;
    // 给边数组初始化
    for (int i = 0; i < vertex_num; ++i)
        g.vertex[i] = vertex[i];
    // 初始化邻接矩阵
    for (int i = 0; i < vertex_num; ++i)
        for (int j = 0; j < vertex_num; ++j)
            g.arc[i][j] = 0;
}

void addEdge(MGraph &g) {
    // 输入每一个边的信息(利用对称矩阵的性质，我们只用初始化对角元素就行)
    for (int i = 0; i < arcNum; ++i) {
        int vi, vj;
        cout << "输入两个有邻接的顶点的编号" << " ( 0 ~ " << arcNum << "): ";
        cin >> vi >> vj;
        cin.ignore(10, '\n');
        if (vi < arcNum and vi >= 0 and vj < arcNum and vj >= 0) {
            g.arc[vi][vj] = 1;
            g.arc[vj][vi] = 1;
        }
    }
}

void addEdge2(MGraph &g, int v1, int v2) {
    // 无向图需要对称地设置两个方向的边
    if (v1 >= 0 && v1 < arcNum && v2 >= 0 && v2 < arcNum) {
        g.arc[v1][v2] = 1;
        g.arc[v2][v1] = 1;
    }
}

void addEdgeWithWeight(MGraph &g, int v1, int v2, int weight) {
    // 由于这个是针对于网图的，所以会是单边的
    if (v1 >= 0 && v1 < arcNum && v2 >= 0 && v2 < arcNum) {
        g.arc[v1][v2] = weight;
        g.arc[v2][v1] = weight;
    }
}

void addWeightNet(MGraph &g, int v1, int v2, int weight) {
    if (v1 >= 0 && v1 < arcNum && v2 >= 0 && v2 < arcNum) {
        g.arc[v1][v2] = weight;
    }
}

void printAdjacencyMatrix(const MGraph &graph) {
    int columnWidth = 3; // 定义每列的固定宽度

    // 打印顶点编号作为第一行
    cout << setw(columnWidth) << " ";
    for (int i = 0; i < vertex_num; ++i) {
        cout << setw(columnWidth) << graph.vertex[i];
    }
    cout << endl;

    // 打印邻接矩阵
    for (int i = 0; i < vertex_num; ++i) {
        cout << setw(columnWidth) << graph.vertex[i] << " ";
        for (int j = 0; j < vertex_num; ++j) {
            cout << setw(columnWidth) << graph.arc[i][j];
        }
        cout << endl;
    }
}

void depthFirstSearch(const MGraph &g) {
    bool visited[MAX_VERTEX] = {false};  // 对应顶点表，用于了解是否访问过了
    for (int i = 0; i < vertex_num; ++i)
        if (!visited[i])    // 防止二次被访问
            DFS(g, visited, i);
    std::cout << std::endl;
}

void DFS(const MGraph &g, bool visited[], int i) {
    visited[i] = true;  // 标记这个节点被遍历过了
    std::cout << g.vertex[i] << " ";
    // 遍历边表，找到和当前顶点的邻接顶点
    for (int j = 0; j < vertex_num; ++j) {
        // 确保遍历到的是邻接点且之前没有遍历过
        if (g.arc[i][j] == 1 and !visited[j])
            DFS(g, visited, j);
    }
}

void breadthFirstSearch(const MGraph &g) {
    bool visited[MAX_VERTEX] = {false};
    queue<char> q;

    for (int i = 0; i < vertex_num; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            cout << g.vertex[i] << " ";
            q.push(g.vertex[i]);    // 把当前访问的点放入队列
            BFS(g, visited, i, q);
        }
    }
    cout << endl;
}

void BFS(const MGraph &g, bool visited[], int i, queue<char> &q) {
    while (!q.empty()) {
        q.pop();    // 释放掉当前访问元素
        // 找从当前点的所有的邻接点
        for (int j = 0; j < vertex_num; ++j) {
            // 确保是临邻接点且没有访问过
            if (g.arc[i][j] == 1 and !visited[j]) {
                visited[j] = true;
                cout << g.vertex[j] << " ";
                q.push(g.vertex[j]);    // 放入邻接点
            }
        }
    }
}

int findMinKey(const int key[], const bool inMST[]) {
    int minKey = MAX_WEIGHT;
    int minIndex = -1;  // 存储最小值的下标

    for (int i = 0; i < vertex_num; ++i) {
        // 找出邻接点中最小的值的下标
        if (!inMST[i] && key[i] < minKey) {
            minKey = key[i];    // 动态比较，找到最小值
            minIndex = i;
        }
    }

    return minIndex;
}

void MiniSpanTree_Prim(const MGraph &g) {
    int parent[vertex_num];      // 存储最小生成树的父节点
    int adjVexWeight[arcNum];    // 存储顶点到最小生成树的最小权值
    bool inMST[vertex_num];      // 记录顶点是否在最小生成树中

    // 初始化
    for (int i = 0; i < vertex_num; ++i) {
        adjVexWeight[i] = MAX_WEIGHT;
        inMST[i] = false;
        parent[i] = -1;
    }

    adjVexWeight[0] = 0;     // 从第一个顶点开始构建最小生成树
    parent[0] = -1;          // 第一个顶点没有父节点

    // 最后一个元素和前一个建立联系，它不需要下一个元素，所以遍历个数是总数 - 1
    for (int count = 0; count < vertex_num - 1; ++count) {
        int u = findMinKey(adjVexWeight, inMST); // 获取当前顶点所在位置的最小权值的邻接点的下标
        inMST[u] = true;    // 把这个邻接点用于构造树，记录为访问过了
        // 遍历所有顶点找当前点的邻接点
        for (int v = 0; v < vertex_num; ++v) {
            // 确保是邻接点且没用于生成树且邻接点的权比上一次存储的权要小
            if (g.arc[u][v] != 0 && !inMST[v] &&
                g.arc[u][v] < adjVexWeight[v]) {
                parent[v] = u;  // 建立当前顶点和邻接点的关系
                adjVexWeight[v] = g.arc[u][v];   // 记录下来了这个节点的所有邻接点
            }
        }
    }
    show_MST(g, parent);
}

void show_MST(const MGraph &g, const int parent[]) {
    cout << "Edge    Weight" << endl;
    for (int i = 1; i < vertex_num; ++i) {
        cout << parent[i] << " - " << i << "    "
             << g.arc[parent[i]][i] << endl;
    }
}

Edge *adjMatrixToEdgeList(const MGraph &g) {
    if (vertex_num == 0 and arcNum == 0)
        return nullptr;

    int edge_num = 0;
    Edge *edgeLists = new Edge[arcNum];
    for (int i = 0; i < vertex_num; ++i) {
        // 只遍历上半三角形区域
        for (int j = i + 1; j < vertex_num; ++j) {
            if (g.arc[i][j] != 0) {
                edgeLists[edge_num].begin = i;
                edgeLists[edge_num].end = j;
                edgeLists[edge_num].weight = g.arc[i][j];
                edge_num++;
            }
        }
    }
    // 实现对权的排序
    quickSort(edgeLists, 0, arcNum - 1);
    return edgeLists;
}

void printEdgeData(const Edge edgeLists[]) {
    cout << "Begin\tEnd\t\tWeight\n";
    for (int i = 0; i < arcNum; ++i) {
        cout << edgeLists[i].begin << "\t\t"
             << edgeLists[i].end << "\t\t"
             << edgeLists[i].weight << endl;
    }
}

void quickSort(Edge *edgeList, int start, int end) {
    if (start >= end)
        return;
    int left = start;
    int right = end;
    // 用于比较的中间值
    int pivot = edgeList[(start + end) / 2].weight;

    while (left < right) {
        // 如果 pivot 左边的元素有大于右边的，就交换
        while (edgeList[left].weight < pivot) left++;
        while (edgeList[right].weight > pivot) right--;
        // 找的值在 pivot两边就交换，不然就不动
        // = 处理在同一个元素的问题，譬如停在 pivot 位置
        // 如果 left 没有 超过 right 说明还是 pivot 两边在交换
        if (left <= right) {
            swap(edgeList[left].weight, edgeList[right].weight);
            swap(edgeList[left].begin, edgeList[right].begin);
            swap(edgeList[left].end, edgeList[right].end);
            // 交换了这两个位置的值之后，跳过这两个位置
            left++, right--;
        }
    }
    quickSort(edgeList, start, right);
    quickSort(edgeList, left, end);
}

Edge *kruskal_MST(Edge *edgeLists) {
    // 记录节点的双亲
    int parent[vertex_num];

    // 存储最小树的边
    Edge *MST = new Edge[vertex_num - 1];

    // 初始化
    for (int i = 0; i < vertex_num; ++i)
        parent[i] = -1;

    // 遍历边表
    for (int i = 0, edge_num = 0; i < vertex_num; ++i) {
        // 找到边两端节点的根节点
        int root_vex1_index = findRoot(parent, edgeLists[i].begin);
        int root_vex2_index = findRoot(parent, edgeLists[i].end);

        // 如果根节点不相同，说明没有形成回路，我们建立新的连接
        if (root_vex1_index != root_vex2_index) {
            parent[root_vex2_index] = root_vex1_index;
            MST[edge_num++] = edgeLists[i];  // 把边存入最小树

            // 边的个数为顶点-1时，就是最小树生成的时候
            if (edge_num == vertex_num - 1) return MST;
        }
    }
    return nullptr;
}

int findRoot(const int parent[], int cur) {
    int root;
    while (cur != -1) {
        root = cur;
        cur = parent[cur];
    }
    return root;
}

void printMSTByKruskal(Edge *MST) {
    cout << "Edge\t" << "Weight\n";
    for (int i = 0; i < vertex_num - 1; ++i) {
        cout << MST[i].begin << " - "
             << MST[i].end << "\t"
             << MST[i].weight << endl;
    }
}

void dijkstra(MGraph &g, int src) {
    int parent[vertex_num];
    int adjVex[vertex_num];
    bool visited[vertex_num];

    // 初始化
    for (int i = 0; i < vertex_num; ++i) {
        parent[i] = 0;
        adjVex[i] = MAX_WEIGHT;
        visited[i] = false;
    }

    // 从 src 开始
    adjVex[src] = 0;
    parent[src] = -1;

    for (int i = 0; i < vertex_num - 1; ++i) {
        // 找到邻接顶点中最小的那个顶点
        int minVexIndex = findMinKey(adjVex, visited);
        visited[minVexIndex] = true;    // 标记为访问过了
        // 找最小点的邻接点
        for (int j = 0; j < vertex_num; ++j) {
            // 到新的邻接点的距离得是最短的
            if (!visited[j] and g.arc[minVexIndex][j] != 0
                and adjVex[j] != MAX_VERTEX and
                g.arc[minVexIndex][j] + adjVex[minVexIndex] < adjVex[j]) {
                parent[j] = minVexIndex;
                adjVex[j] = adjVex[minVexIndex] + g.arc[minVexIndex][j];
            }
        }
    }
    printShortestPaths(g, adjVex, src);
}

void printShortestPaths(MGraph &g, int adjVex[], int src) {
    cout << "From To  \tWeight\n";
    for (int i = 0; i < vertex_num; ++i)
        cout << g.vertex[src] << " - " << g.vertex[i]
             << "\t\t" << adjVex[i] << endl;
    cout << endl;
}

// 不知道发什么神经，下面的函数死活用不了
void printMatrix(const int dist[][vertex_num]) {
    for (int i = 0; i < vertex_num; ++i) {
        for (int j = 0; j < vertex_num; ++j) {
            if (dist[i][j] == MAX_WEIGHT)
                cout << "∞" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void floydWarshall(MGraph &g) {
    int dist[vertex_num][vertex_num];

    // 初始化 (除了轨 = 0，无连接的地方全部都是最大值)
    for (int i = 0; i < vertex_num; ++i)
        for (int j = 0; j < vertex_num; ++j) {
            if (i == j)
                dist[i][j] = 0;
            else if (g.arc[i][j] != 0)
                dist[i][j] = g.arc[i][j];
            else
                dist[i][j] = MAX_WEIGHT;
        }
    // 按照迭代实现最小路径
    for (int i = 0; i < vertex_num; ++i)    // 迭代的次数
        // 行和列的遍历用的循环
        for (int row = 0; row < vertex_num; ++row)
            for (int col = 0; col < vertex_num; ++col)
                // 根据迭代的规律来比较路线的值和原来的值那个更短，如果有某一个点不能走，就下一次
                if (dist[i][col] != MAX_VERTEX and dist[row][i] != MAX_VERTEX
                    and dist[row][col] > dist[i][col] + dist[row][i]) {
                    // 更新为更短的走法
                    dist[row][col] = dist[i][col] + dist[row][i];
                }
    // 看下结果
    cout << "  ";
    for (int i = 0; i < vertex_num; ++i)
        cout << g.vertex[i] << " ";
    cout << endl;
    for (int i = 0; i < vertex_num; ++i) {
        cout << g.vertex[i] << " ";
        for (int j = 0; j < vertex_num; ++j) {
            if (dist[i][j] == MAX_WEIGHT)
                cout << "∞" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

//
// Created by Momo on 2023/8/18.
//

#include "AOV图实现.h"


void initGraphAdjList(graphAdjList &g, const char vex_data[], int e_num, int v_num) {
    g.edgeNum = e_num;
    g.vexNum = v_num;

    // 给邻接表的顶点数组初始化
    for (int i = 0; i < g.vexNum; ++i) {
        g.adjList->firstNode = nullptr;
        g.adjList->in = 0;
        g.adjList[i].data = vex_data[i];
    }
}

void addEdgeWithoutWeight(graphAdjList &g, int from, int to) {
    if (from >= 0 and from < g.vexNum and to >= 0 and to < g.vexNum) {
        EdgeNode *cur = g.adjList[from].firstNode;
        auto *temp = newNode(g, to);
        if (cur == nullptr) {
            g.adjList[from].firstNode = temp;
        } else {
            // 在最后的位置插入新的边
            while (cur->next != nullptr)
                cur = cur->next;    // 暂停在最后一个位置
            cur->next = temp;
        }
    }
}

void addEdgeWithWeight(graphAdjList &g, int from, int to, int Weight) {
    if (from >= 0 and from < g.edgeNum and to >= 0 and to < g.edgeNum) {
        EdgeNode *cur = g.adjList[from].firstNode;
        auto *temp = newNode(g, to, Weight);
        if (cur == nullptr) {
            g.adjList[from].firstNode = temp;
        } else {
            // 在最后的位置插入新的边
            while (cur->next != nullptr)
                cur = cur->next;    // 暂停在最后一个位置
            cur->next = temp;
        }
    }
}

EdgeNode *newNode(graphAdjList &g, int to, int Weight) {
    auto *temp = new EdgeNode;
    temp->adjVex = to;
    g.adjList[to].in++;    // 更新到达顶点的入度
    temp->weight = Weight;
    temp->next = nullptr;
    return temp;
}

void clearAdjList(graphAdjList &g) {
    if (g.vexNum == 0 or g.edgeNum == 0)
        return;

    for (int i = 0; i < g.vexNum; ++i) {
        g.adjList[i].in = 0;    // 顶点表所有的入度更替为 0
        EdgeNode *pre = nullptr, *cur = g.adjList[i].firstNode;
        while (cur != nullptr) {
            pre = cur;
            cur = cur->next;
            delete pre;
        }
        g.adjList[i].firstNode = nullptr;
    }

    g.vexNum = 0;
    g.edgeNum = 0;
}

void AOV_sort(graphAdjList &g) {
    bool visited[g.vexNum];
    stack<int> s;
    string sort_seq;    // 用于记录AOV顺序

    for (int i = 0; i < g.vexNum; ++i)
        // 找顶点表中所有入度为 0 的顶点
        if (g.adjList[i].in == 0)
            s.push(i);  // 把那些点所在的 index 压入栈

    while (!s.empty()) {
        int top_element = s.top();
        s.pop();
        sort_seq.push_back(g.adjList[top_element].data);

        // 遍历入度 0 的顶点的所有邻接点
        EdgeNode *cur = g.adjList[top_element].firstNode, *pre = nullptr;
        while (cur != nullptr) {
            pre = cur;
            // 如果邻接点入度 - 1 之后 == 0，就是新的入度为 0 的点，压入栈中
            if ((--g.adjList[pre->adjVex].in) == 0)
                s.push(pre->adjVex);
            cur = cur->next;
        }
    }
    show_AOV_sort(g, sort_seq);
}

void show_AOV_sort(const graphAdjList &g, const string &sort_seq) {
    if (sort_seq.size() < g.vexNum)
        cout << "Loop\n";
    else {
        for (auto data: sort_seq)
            cout << data << " ";
        cout << endl;
    }
}

void criticalPath(graphAdjList &g) {
    // 计算最早最晚发生时间
    int ve[g.vexNum]; // 存储事件最早发生时间
    int vl[g.vexNum]; // 存储事件最迟发生时间

    calculateEarliestLatest(g, ve, vl);
}

void calculateEarliestLatest(graphAdjList &g, int ve[], int vl[]) {
    int count = 0;
    // 初始化
    for (int i = 0; i < g.vexNum; ++i) {
        ve[i] = 0;
        vl[i] = INT_MAX;
    }

    /* 计算事件最早发生时间 ve */
    stack<int> s;   // 存入度为 0 点的 index
    for (int i = 0; i < g.vexNum; ++i)
        if (g.adjList[i].in == 0)
            s.push(i);

    while (!s.empty()) {
        int top_element = s.top();
        s.pop();
        count++;

        EdgeNode *cur = g.adjList[top_element].firstNode;
        while (cur != nullptr) {
            // 当前的事件和下一件事件之间，下一件事件更大就存它
            // 事件有多个入度，所以会多次比较，存入最大的一个
            if (ve[cur->adjVex] < ve[top_element] + cur->weight)
                ve[cur->adjVex] = ve[top_element] + cur->weight;
            // 插入新的 in == 0 的点
            if ((--g.adjList[cur->adjVex].in) == 0)
                s.push(cur->adjVex);
            cur = cur->next;
        }
    }

    // 防止有回路的出现
    if (count < g.vexNum) {
        cout << "Loop\n";
        return;
    }

    /* 计算事件最迟发生时间 vl 倒过来重复一遍*/
    vl[g.vexNum-1] = ve[g.vexNum-1];

    s.push(g.vexNum-1);
    for (int i = g.vexNum - 1; i >= 0; --i) {
        EdgeNode * cur = g.adjList[i].firstNode;
        while (cur != nullptr) {
            if (vl[i] > vl[cur->adjVex] - cur->weight)
                vl[i] = vl[cur->adjVex] - cur->weight;
            cur = cur->next;
        }
    }
    // 输出关键路径
    printCriticalPath(g, ve, vl);
}

void printCriticalPath(const graphAdjList & g, const int ve[], const int vl[]) {
    cout << "Critical Path:\n";
    for (int i = 0; i < g.vexNum-1; ++i) {
        EdgeNode * cur = g.adjList[i].firstNode;
        while (cur != nullptr) {
            int ee = ve[i]; // 事件 i 的最早发生时间
            int el = vl[cur->adjVex] - cur->weight; // 邻接事件的最迟发生时间
            if (ee == el)
                cout << "(" << g.adjList[i].data << "->" << g.adjList[cur->adjVex].data << ") ";
            cur = cur->next;
        }
    }
    cout << endl;
}

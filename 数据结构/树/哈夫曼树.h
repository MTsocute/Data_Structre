//
// Created by Momo on 2023/7/27.
//

#ifndef DATASTRUCTURE_哈夫曼树_H
#define DATASTRUCTURE_哈夫曼树_H

#include <iostream>

using namespace std;

// 哈夫曼树的节点的结构
typedef struct TreeNode {
    char data;      // 存储的数据
    int weight;     // 这个数据的权重
    int parent;     // 这个节点的父节点在数组的索引
    int left;       // 这个节点的左子树索引
    int right;      // 这个节点的右子树索引
} * HTree;


// 初始化叶子结点
void ini_huffTree(HTree & ht, const char * cha,
                  const int * weights,  const int leaf_node_num) {
    const int total_nodes = 2 * leaf_node_num - 1;
    for (int i = 0; i < total_nodes; ++i) {
        if (i < leaf_node_num + 1) {
            ht[i].data = cha[i];
            ht[i].weight = weights[i];
            ht[i].parent = -1;
            ht[i].left = -1;
            ht[i].right = -1;
        } else {
            ht[i].parent = -1;
            ht[i].left = -1;
            ht[i].right = -1;
        }
    }
}


// 找到权重最小的两个节点
void findTwoMinNodes(HTree & nodes, int size, int& min1, int& min2) {
    min1 = min2 = -1;   // 用于保存两个最小的索引
    for (int j = 0; j < size; ++j) {
        if (nodes[j].parent == -1) {    // 找还没有成为叶子的节点
            // min1 会先找到最小的那个数的索引，min2 会停留在那个位置前面
            // 判断条件中涉及到了 == -1，防止 min 存不到值
            if (min1 == -1 || nodes[j].weight < nodes[min1].weight) {
                min2 = min1;    // min2 转变到从前面到 min1 最小的那个位置
                min1 = j;   // 更新到刚找到最小的那个位置
            }
            // min1 停滞的时候说明，新的值不是最小的值，但是我们可以和次小的值做比较
            else if (min2 == -1 || nodes[j].weight < nodes[min2].weight)
                min2 = j;
        }
    }
}


// 哈夫曼树构建函数
void buildHuffmanTree(HTree &nodes, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min1, min2;     // min1存最小，min2次小
        // 注意这里哈，增加一个新的值，就动态变化下长度
        findTwoMinNodes(nodes, size + i, min1, min2);

        // 合并两个节点为一个新节点
        nodes[size + i].data = '\0';
        nodes[size + i].weight = nodes[min1].weight + nodes[min2].weight;
        // 左节点为最小值，右节点为次小值索引
        nodes[size + i].left = min1;
        nodes[size + i].right = min2;
        // 存最小值双亲所在位置
        nodes[min1].parent = size + i;
        nodes[min2].parent = size + i;
    }
}


// 使用哈夫曼树创建哈夫曼编码
void huffmanCoding(HTree & hufTree, char * codes[], int size) {
    char * temp = new char[size];   // 创建一个临时数组存储编码
    temp[size-1] = '\0';    // n个叶子节点组成的最深树深度不会超过 n-1
    // 遍历每一个叶子结点
    for (int i = 0; i < size; ++i) {
        int start_index = size-1;   // 由于是从叶子到根，我们获取的第一个节点的编码其实是最后一个的位置
        int pos = i;    // 处理当前的节点
        int pre = hufTree[i].parent;     // 用于寻找父节点
        // 找到叶子结点的根节点为位置
        while (pre != -1) {
            // 如果是父节点的左子树编码就是 0，发之编码就是 1
            if (hufTree[pre].left == pos)
                temp[--start_index] = '0';
            else
                temp[--start_index] = '1';
            pos = pre;   // 当前节点移动到父节点位置
            pre = hufTree[pre].parent;    // 更新父亲节点位置
        }
        codes[i] = new char[size-start_index];  // 根据编码制作合适长度的容器(记得留'\0'一个位置)
        // 这里注意要根据字符串长度变化来决定首地址位置拷贝过去
        strcpy(codes[i], &temp[start_index]);
    }
    delete[] temp;      // 释放空间
}

#endif //DATASTRUCTURE_哈夫曼树_H

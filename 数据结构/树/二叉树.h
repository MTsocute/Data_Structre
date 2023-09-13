//
// Created by Momo on 2023/7/21.
//

#ifndef DATASTRUCTURE_二叉树_H
#define DATASTRUCTURE_二叉树_H
#include <iostream>
#include <cstring>

static const char END = '#';

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

struct binary_Tree {
    int total_node_number;
    TreeNode * root;
};

// 创建新的二叉树节点
TreeNode* createNode(int value);

// 向二叉树中插入新节点
void createBinTree(TreeNode*& root);

// 递归遍历二叉树（前序遍历）
void preorderTraversal(TreeNode* root);

// 递归遍历二叉树（中序遍历）
void inorderTraversal(TreeNode* root);

// 递归遍历二叉树（后序遍历）
void postorderTraversal(TreeNode* root);

#endif //DATASTRUCTURE_二叉树_H

//
// Created by Momo on 2023/7/24.
//

#ifndef DATASTRUCTURE_BTREE_H
#define DATASTRUCTURE_BTREE_H

#include <iostream>
#include "Tree.h"

// 定义二叉树节点结构体
typedef struct BinaryTreeNode {
    char data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
} BinaryTree;

// 创建节点
BinaryTreeNode *newBTNode(const char val) {
    BinaryTreeNode *tmp = new BinaryTreeNode;
    tmp->data = val;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}

// 构建二叉树
BinaryTree *ini_BTree() {
    BinaryTree *root = newBTNode('A');

    root->left = newBTNode('B');
    root->left->right = newBTNode('C');
    root->left->right->right = newBTNode('D');

    root->right = newBTNode('E');
    root->right->left = newBTNode('F');
    root->right->right = newBTNode('G');

    root->right->right->left = newBTNode('H');
    root->right->right->left->left = newBTNode('J');
    root->right->right->left->right = newBTNode('I');

    return root;
}

// 中间序遍历二叉树
void inOrderTravsal(BinaryTreeNode *root) {
    if (root == nullptr)
        return;
    inOrderTravsal(root->left);
    std::cout << root->data << " ";
    inOrderTravsal(root->right);
}

void postOrderTravsal(BinaryTreeNode *root) {
    if (root == nullptr)
        return;
    postOrderTravsal(root->left);
    postOrderTravsal(root->right);
    std::cout << root->data << " ";
}

// 删除一个二叉树
void deleteBinaryTree(BinaryTree * root) {
    if (root == nullptr)
        return;
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}

#endif //DATASTRUCTURE_BTREE_H

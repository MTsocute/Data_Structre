//
// Created by Momo on 2023/7/24.
//

#ifndef DATASTRUCTURE_TREE_BTTREE_FOREST_H
#define DATASTRUCTURE_TREE_BTTREE_FOREST_H

#include "BTree.h"
#include "Tree.h"

/**
 * @brief 树转换为二叉树(其实就是按照前序遍历生成二叉树)
 * @param root Tree的根节点
 * @return BinaryTreeNode * 指针 转换成的二叉树的节点
 * */
BinaryTree *treeToBinaryTree(Tree *root);


/**
 * @brief 二叉树转换成树
 * @param root 二叉树的根节点
 * @return Tree * 转换成树的根节点
 * */
 Tree * binaryToTree(BinaryTree * root);


/**
 * @brief 森林转换成二叉树
 * @param forest 森林就是树指针的数组
 * @return BinaryTreeNode *root
 * */
BinaryTreeNode *forestToBinaryTree(Tree **forest);


/**
 * @brief 二叉树转换成森林
 * @param root 二叉树的根结点
 * @return BinaryTreeNode *root 二叉树的根节点
 * */
Tree **BinaryTreeToforest(BinaryTree *root);


Tree **BinaryTreeToforest(BinaryTree * root, int * num = nullptr) {
    if (root == nullptr)
        return nullptr;
    int count = 0;  // 根据右子树数量而变动
    BinaryTree * pre = nullptr;
    BinaryTree * cur = root;
    Tree ** forest = nullptr;    // 容纳拆分开的右子树

    while (cur != nullptr) {
        // pre 就是我们要获取的部分
        pre = cur;
        cur = cur->right;   // 递归到下一个树
        pre->right = nullptr; // 断开和下一颗树的联系

        Tree ** temp = new Tree * [count + 1];

        /* 拷贝老的数据到新扩张大小的数组当中去 */
        for (int i = 0; i < count; ++i)
            temp[i] = forest[i];
        delete[] forest;
        forest = temp;

        forest[count++] = binaryToTree(pre);
    }
    *num = count;
    return forest;
}

Tree * binaryToTree(BinaryTree * root) {
    if (root == nullptr)
        return nullptr;
    Tree * TreeRoot = new TreeNode;
    TreeRoot->data = root->data;
    TreeRoot->firstChild = binaryToTree(root->left);
    TreeRoot->nextSibling = binaryToTree(root->right);

    return TreeRoot;
}

BinaryTree *treeToBinaryTree(Tree *root) {
    if (root == nullptr)
        return nullptr;
    BinaryTree *newRoot = new BinaryTreeNode;
    newRoot->data = root->data;
    newRoot->left = treeToBinaryTree(root->firstChild);
    newRoot->right = treeToBinaryTree(root->nextSibling);
    return newRoot;
}

BinaryTreeNode *forestToBinaryTree(Tree **forest) {
    // 检查是否 森林指针 或 第一个树为空
    if (!forest || !(*forest))
        return nullptr;

    // 将第一个树转换为二叉树
    BinaryTreeNode *curRoot, *root;
    curRoot = root = treeToBinaryTree(*forest);

    // 合并其他树为一个二叉树
    for (int i = 1; i < 3; i++) { // 假设森林中有三棵树，如果有更多，可以调整循环次数
        BinaryTreeNode *currentTree = treeToBinaryTree(forest[i]);
        if (currentTree) {
            curRoot->right = currentTree;
            curRoot = curRoot->right;
        }
    }
    return root;
}

#endif //DATASTRUCTURE_TREE_BTTREE_FOREST_H

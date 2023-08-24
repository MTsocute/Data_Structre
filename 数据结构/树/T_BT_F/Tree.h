//
// Created by Momo on 2023/7/24.
//

#ifndef DATASTRUCTURE_TREE_H
#define DATASTRUCTURE_TREE_H

#include <iostream>

// 定义树节点结构体
typedef struct TreeNode {
    char data;
    TreeNode *firstChild;
    TreeNode *nextSibling;
} TreeNode, Tree;

// 创建树的节点
TreeNode *newTNode(char val) {
    TreeNode *tmp = new TreeNode;
    tmp->data = val;
    tmp->firstChild = nullptr;
    tmp->nextSibling = nullptr;
    return tmp;
}

// 生成一个颗🌲(自定义)
Tree *ini_Tree() {
    TreeNode *A = newTNode('A');
    TreeNode *B = newTNode('B');
    TreeNode *C = newTNode('C');
    TreeNode *D = newTNode('D');
    TreeNode *E = newTNode('E');
    TreeNode *F = newTNode('F');
    TreeNode *G = newTNode('G');
    TreeNode *H = newTNode('H');
    TreeNode *I = newTNode('I');
    TreeNode *J = newTNode('J');

    // 构建树的结构
    A->firstChild = B;
    B->nextSibling = C;
    C->nextSibling = D;
    B->firstChild = E;
    E->nextSibling = F;
    F->nextSibling = G;
    C->firstChild = H;
    D->firstChild = I;
    I->nextSibling = J;

    return A;
}

// 生成一个森林🌳(自定义)
Tree **ini_forest() {
    TreeNode *A = newTNode('A');
    TreeNode *B = newTNode('B');
    TreeNode *C = newTNode('C');
    TreeNode *D = newTNode('D');
    TreeNode *E = newTNode('E');
    TreeNode *F = newTNode('F');
    TreeNode *G = newTNode('G');
    TreeNode *H = newTNode('H');
    TreeNode *I = newTNode('I');
    TreeNode *J = newTNode('J');
    // 第1个颗树
    Tree *tree_1 = A;
    tree_1->firstChild = B;
    B->nextSibling = C;
    C->nextSibling = D;

    // 第2个颗树
    Tree *tree_2 = E;
    tree_2->firstChild = F;

    // 第3个颗树
    Tree *tree_3 = G;
    tree_3->firstChild = H;
    H->nextSibling = I;
    H->firstChild = J;

    // 三颗树组成的森林
    Tree **forest = new TreeNode *[3];
    forest[0] = tree_1;
    forest[1] = tree_2;
    forest[2] = tree_3;
    return forest;
}

#endif //DATASTRUCTURE_TREE_H

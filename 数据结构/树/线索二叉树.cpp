//
// Created by Momo on 2023/7/21.
//

#include "线索二叉树.h"

int main() {
//    thread_TreeNode *root = nullptr;
//    createTree(root);

    thread_TreeNode *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('E');
    root->left->right = createNode('F');

    thread_TreeNode *pre = nullptr; // 辅助指针用于记录前继节点

    convert2ThreadTree(root, pre);

    // 中序遍历线索二叉树
    std::cout << "Inorder Traversal: ";
    in_order_traversal(root);
    std::cout << std::endl;


    return 0;
}
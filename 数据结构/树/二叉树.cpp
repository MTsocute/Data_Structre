//
// Created by Momo on 2023/7/21.
//

#include "二叉树.h"

using std::cout;
using std::endl;


int main() {
    TreeNode *root = nullptr;

    createBinTree(root);

    inorderTraversal(root);

    return 0;
}

TreeNode *createNode(int value) {
    TreeNode *newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void createBinTree(TreeNode *&root) {
    char temp;
    cout << "请输入一个节点 (char): ";
    std::cin >> temp;
    /* 如果是第一个节点的话，就直接结束了
     * 很像前序遍历二叉树，那就相当于终止某边遍历的条件
     * 利用这，我们可以按照前序
     * */
    if (temp == END)
        root = nullptr;
    else {
        root = new TreeNode;
        if (!root)  // 开辟内存失败
            exit(OVERFLOW);
        /* 前序遍历生成节点 */
        root->data = temp;  // 创建根节点
        createBinTree(root->left);
        createBinTree(root->right);
    }
}

void inorderTraversal(TreeNode *root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode *root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode *root) {
    if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

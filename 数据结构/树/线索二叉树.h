#ifndef DATASTRUCTURE_线索二叉树_H
#define DATASTRUCTURE_线索二叉树_H

#include <iostream>

const static char END = '#';

// Threaded Tree Node
struct thread_TreeNode {
    char data;
    thread_TreeNode *left;
    thread_TreeNode *right;
    bool leftThread;  // 是否为线索指针
    bool rightThread; // 是否为线索指针
};

typedef enum {
    Link, Thread
} PointerTag;

thread_TreeNode *createNode(char value) {
    thread_TreeNode *newNode = new thread_TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->leftThread = Link;
    newNode->rightThread = Link;
    return newNode;
}

/**
 * @brief 前序生成二叉树，用 # 表示下个节点为空
 * @param root 根节点的指针
 * */
void createTree(thread_TreeNode *&root) {
    char temp;
    std::cout << "请输入一个节点 (char): ";
    std::cin >> temp;
    if (temp == END)
        root = nullptr;
    else {
        // root = createNode(temp);
        root = new thread_TreeNode;
        if (!root)
            exit(OVERFLOW);
        root->data = temp;
        root->leftThread = Link;
        root->rightThread = Link;
        createTree(root->left);
        createTree(root->right);
    }
}

// 中序遍历树
void inOrderTraversal(const thread_TreeNode *root) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

/**
 * @brief 根据中间序遍历，创建线索二叉树
 * @param pre 前继后续的前一个位置的节点
 * @param root 根节点的指针
 * */
void convert2ThreadTree(thread_TreeNode* root, thread_TreeNode*& pre) {
    if (root == nullptr)
        return;

    // 1. 递归处理左子树
    convert2ThreadTree(root->left, pre);

    // 2. 处理当前节点
    // 2.1 如果当前节点的左孩子为空，说明当前节点没有左子树，可以将其左孩子指针指向中序遍历的前驱节点（pre）
    // 2.2 设置左线索标记
    if (root->left == nullptr) {
        root->left = pre;
        root->leftThread = Thread;
    }

    // 2.3 如果前驱节点（pre）的右孩子为空，说明前驱节点没有右子树，可以将其右孩子指针指向当前节点（root）
    // 2.4 设置右线索标记
    if (pre != nullptr && pre->right == nullptr) {
        pre->right = root;
        pre->rightThread = Thread;
    }

    // 2.5 更新前驱节点（pre）为当前节点（root）
    pre = root; // 就是中序遍历的时候当前节点的前一个节点，第一个的话就是 null

    // 3. 递归处理右子树
    convert2ThreadTree(root->right, pre);
}

/**
 * @brief 利用右孩子提供的线索，实现中序遍历
 * @param root 根节点指针
 * */
void in_order_traversal(thread_TreeNode *root) {
    thread_TreeNode *current = root;

    // 找到中序遍历下的第一个节点(最左边的那个)
    while (current->leftThread == Link)
        current = current->left;

    // 中需遍历找到最后一个节点停止
    while (current != nullptr) {
        std::cout << current->data << " ";  // 打印遇到的节点

        // 如果右指针是线索指针，直接跳转到后继节点
        if (current->rightThread == Thread)
            current = current->right;
        else {
            // 如果不是线索指针，那就是节点，找到这个节点右子树中的最左边的节点
            // 这个最左边的节点，对应的就是中序遍历的后一个节点
            current = current->right;   // 进入该节点的右子树
            // 防止进入线索导致的错误或者说进入叶子节点的null导致遍历不到后续
            while (current != nullptr && current->leftThread == Link)
                current = current->left;    // 找到最左边的那个节点
        }
    }
}

#endif //DATASTRUCTURE_线索二叉树_H

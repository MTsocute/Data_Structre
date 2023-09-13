//
// Created by Momo on 2023/9/4.
//

#ifndef DATASTRUCTURE_二叉排序树_H
#define DATASTRUCTURE_二叉排序树_H

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *lChild;
    Node *rChild;
};

//void BST_to_linkedList(Node *root, Node *& pre);

Node *newNode(const int &val);

void insert_BST(Node *&root, int val);

void traversal_BST(Node *&root);

void generate_BST(Node *&root, const vector<int> &arr);

void delete_BST(Node *&root);

Node *search_BST(Node *&root, int target);

void deleteNode_BST(Node *&root, int target);

void delete_node(Node *&delNode);

int get_height(Node *&branch);

bool is_AVL_Tree(Node *&root);



/**
 * @brief 给平衡二叉树插入一个新的节点
 * @param root 根节点
 * @param val 要插入的新的值
 * */
void insert_BST(Node *&root, int val) {
    if (root == nullptr) {
        Node *node = newNode(val);
        root = node;
    } else {
        if (val < root->val) { insert_BST(root->lChild, val); }
        else { insert_BST(root->rChild, val); }
    }
}


/**
 * @brief 再二叉排序树中查找一个值是否存在
 * @param root 根节点
 * @param target 要查找的点
 * @return Node 节点，找不到就是 nullptr
 * */
Node *search_BST(Node *&root, int target) {
    if (root == nullptr)
        return nullptr;
    else {
        if (root->val == target)
            return root;
            // 注意要返回哈，只递不归，以栈为坛，内存炮灰
        else if (target < root->val)
            return search_BST(root->lChild, target);
        else return search_BST(root->rChild, target);
    }
}

/**
 * @brief 把一个二叉排序树转变为一个双向链表
 * @param pre 指向中序前一个节点
 * */
void BST_to_linkedList(Node *root, Node *& pre) {
    if (root == nullptr) return;

    // 遍历到最左边的地方
    BST_to_linkedList(root, pre);

    // 最左边的节点作为双向链表的开头，pre 一开始是 null
    if (root->lChild == nullptr)
        root->lChild = pre;

    if (pre != nullptr and pre->rChild == nullptr)
        pre = root;

    pre = root;     // 变更 pre 为新的中序位置的节点
    BST_to_linkedList(root, pre);
}


/**
 * @brief 判断一个二叉树是否为平衡二叉树
 * @return bool 是平衡二叉树即 true，反之 false
 * */
bool is_AVL_Tree(Node *&root) {
    // 如果是一个空树，是平衡二叉树
    if (root == nullptr) return true;

    else {
        int left = get_height(root->lChild);
        int right = get_height(root->rChild);

        // 使用递归，查看所有的左右子树是不是都满足这个条件
        if (abs(left - right) <= 1)
            return is_AVL_Tree(root->lChild)
                   and is_AVL_Tree(root->rChild);
        else return false;
    }
}

int get_height(Node *&branch) {
    if (branch == nullptr)
        return 0;
    int left = get_height(branch->lChild);
    int right = get_height(branch->rChild);

    return max(left, right) + 1;
    // return max(get_height(branch->lChild, branch->rChild) + 1);
}


/* 找到要删除的节点，传递给用于删除的函数 */
void deleteNode_BST(Node *&root, int target) {
    if (root == nullptr) return;
    else {
        // 找到了要删除的节点了
        if (root->val == target)
            delete_node(root);
        else if (target < root->val)
            deleteNode_BST(root->lChild, target); // 在左子树中递归删除
        else
            deleteNode_BST(root->rChild, target); // 在右子树中递归删除
    }
}

void delete_node(Node *&delNode) {
    // 情况1：是叶子结点
    if (delNode->lChild == nullptr and delNode->rChild == nullptr) {
        delete delNode;
        delNode = nullptr;
    }
        // 情况2：左子树或右子树有一个是空的
    else if (delNode->lChild == nullptr) {
        Node *temp = delNode;
        delNode = delNode->rChild;
        delete temp;
    } else if (delNode->rChild == nullptr) {
        Node *temp = delNode;
        delNode = delNode->lChild;
        delete temp;
    }
        // 情况3：左右子树都存在
    else {
        Node *pre = delNode;
        Node *maxNode = delNode->lChild;    // 左转，去找左子树的最大值
        while (maxNode->rChild != nullptr) {
            pre = maxNode;  // 保持是最小右子树的前一节点
            maxNode = maxNode->rChild;
        }
        // 替换掉要删除位置的值为左子树的最大值
        delNode->val = maxNode->val;

        if (pre != delNode) {   // 说明找到了左子树的最大值
            // 由于最大值节点赋予给了删除点作为新的点，所以我们要把这个最大值点删除
            pre->rChild = maxNode->lChild;  // pre 重接右子树
            delete maxNode;
            maxNode = nullptr;
        } else {  // 这个时候说明左子树没有右子树，最大的就是中间的位置
            pre->lChild = maxNode->lChild;  // pre 重接左子树
            delete maxNode;
            maxNode = nullptr;
        }
    }
}

/**
 * @brief 初始化一个二叉排序树
 * @param root 二叉树的根节点
 * @param arr 用于生成树的数组
 * */
void generate_BST(Node *&root, const vector<int> &arr) {
    if (arr.empty())
        return;
    for (auto num: arr)
        insert_BST(root, num);
}

/* 中序遍历：从小到大输出二叉树 */
void traversal_BST(Node *&root) {
    if (root == nullptr)
        return;

    traversal_BST(root->lChild);
    cout << root->val << " ";
    traversal_BST(root->rChild);
}

/* 新增一个节点 */
Node *newNode(const int &val) {
    Node *temp = new Node{val, nullptr, nullptr};
    return temp;
}

/* 删除二叉排序树 */
void delete_BST(Node *&root) {
    if (root == nullptr)
        return;

    delete_BST(root->lChild);
    delete_BST(root->rChild);

    delete root;
}

#endif //DATASTRUCTURE_二叉排序树_H

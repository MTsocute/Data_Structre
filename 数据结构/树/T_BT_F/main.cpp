//
// Created by Momo on 2023/7/24.
//

#include "tree_btTree_Forest.h"

int main() {
    using std::cout;
    using std::endl;

    BinaryTree * Broot = ini_BTree();

    int num = 0, *number = &num;
    Tree ** demo = BinaryTreeToforest( Broot, number);

    for (int i = 0; i < num; ++i) {
        inOrderTravsal(treeToBinaryTree(demo[i]));
        cout << endl;
    }
    
    return 0;
}
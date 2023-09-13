//
// Created by Momo on 2023/9/4.
//

#include "二叉排序树.h"

int main() {
    Node *root = nullptr;
    vector<int> arr = {45, 67};

    generate_BST(root, arr);

//    if (search_BST(root, 120))
//        cout <<"The Value is indeed in the tree\n";
//    else
//        cout << "Data Not Found In the Tree\n";

    traversal_BST(root);
    cout << endl;

//    deleteNode_BST(root, 12);

//    traversal_BST(root);

    cout << "left branch depth = "
         << get_height(root->lChild) << endl;

    delete_BST(root);

    return 0;
}
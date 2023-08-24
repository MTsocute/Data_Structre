//
// Created by Momo on 2023/7/21.
//

#include "child_express.h"

CTree initTree(CTree tree) {
    printf("输入节点数量：\n");
    cin >> tree.n;
    for (int i = 0; i < tree.n; i++) {
        printf("输入第 %d 个节点的值：\n", i + 1);
        cin >> tree.nodes[i].data;
        tree.nodes[i].firstchild = new CTNode;
        tree.nodes[i].firstchild->next = nullptr;

        printf("输入节点 %c 的孩子节点数量：\n", tree.nodes[i].data);
        int Num;
        cin >> Num;
        if (Num != 0) {
            ChildPtr * p = tree.nodes[i].firstchild;
            for (int j = 0; j < Num; j++) {
                ChildPtr * newEle = new CTNode;
                newEle->next = nullptr;
                printf("输入第 %d 个孩子节点在顺序表中的位置", j + 1);
                cin >> newEle->child;
                p->next = newEle;
                p = p->next;
            }
        }
    }
    return tree;
}

void findKids(CTree tree, char a) {
    int hasKids = 0;
    for (int i = 0; i < tree.n; i++) {
        if (tree.nodes[i].data == a) {
            ChildPtr * p = tree.nodes[i].firstchild->next;
            while (p) {
                hasKids = 1;
                printf("%c ", tree.nodes[p->child].data);
                p = p->next;
            }
            break;
        }
    }
    if (hasKids == 0) {
        printf("此节点为叶子节点");
    }
}
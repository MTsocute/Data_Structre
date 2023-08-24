//
// Created by Momo on 2023/7/27.
//

#include "哈夫曼树.h"


int main() {
    char characters[] = { 'A', 'B', 'C', 'D', 'E' };
    int weights[] = { 5, 9, 12, 13, 16 };

    const int leaf_node_num = sizeof weights / sizeof weights[0];

    TreeNode hufTree[2 * leaf_node_num - 1];

    HTree ht = hufTree;

    ini_huffTree(ht, characters, weights, leaf_node_num);

    buildHuffmanTree(ht, leaf_node_num);

    char * codes[leaf_node_num];

    huffmanCoding(ht, codes, leaf_node_num);


    for (char * i : codes)
        cout << i << endl;
    return 0;
}
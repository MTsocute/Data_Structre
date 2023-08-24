//
// Created by Momo on 2023/7/6.
//

#include "sLinklist.h"

int main() {
    SLinkList SL;

    initialize_SLL(SL);

    for (int i = 0; i < 3; ++i)
        add_node_to_SLL(SL, i);

    traverse_SLL(SL);
    return 0;
}

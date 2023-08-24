//
// Created by Momo on 2023/7/10.
//

#include "双向链表.h"


int main() {

    dulLinkedList dullist = {nullptr, nullptr ,0};

    for (int i = 0; i < 4; ++i)
        add_node(dullist, i+1);

    delete_at_tail(&dullist);

    traverse_from_end(dullist);

    return 0;
}
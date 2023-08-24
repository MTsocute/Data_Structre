//
// Created by Momo on 2023/7/15.
//

#include "链式队列.h"

int main () {
    lQueue q = {};

    ini_queue(q);

    for (int i = 0; i < 10; ++i)
        enqueue(q, i+1);

    traverse(q);

    for (int i = 0; i < 2; ++i)
        deque(q);

    traverse(q);

    return 0;
}
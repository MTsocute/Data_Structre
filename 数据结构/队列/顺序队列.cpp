//
// Created by Momo on 2023/7/14.
//

#include "顺序队列.h"


int main() {
    using std::cout;
    using std::endl;

    seQueue q = {};

    ini_queue(q);

    for (int i = 0; i < MAXSIZE; ++i) {
        enqueue(q, i+1);
    }

    cout << "number of data: "
    << queue_len(q) << endl;

    traverse(q);

    for (int i = 0; i < 2; ++i)
        dequeue(q);

    cout << "number of data: "
    << queue_len(q) << endl;

    traverse(q);

    enqueue(q, 20);
    enqueue(q, 30);

    cout << "number of data: "
    << queue_len(q) << endl;

    traverse(q);

    return 0;
}
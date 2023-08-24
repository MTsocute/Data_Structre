//
// Created by Momo on 2023/7/13.
//

#include "顺序栈.h"


int main() {
    sqStack stack = {
        {1,2,3,4},
        3
    };

    sqStack * s = &stack;

    // push a new node to stack
    push(s, 10);

    // pop a data
//    pop(s);

    traverse(s);
    cout << "stack's len: " <<
    get_length(s) << endl;

    return 0;
}
//
// Created by Momo on 2023/7/14.
//
#include <iostream>

int fibonacci(int i) {
    if (i < 2)
        return i == 1 ? 0 : 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main() {
    for (int i = 40; i > 0; --i)
        std::cout << fibonacci(i) << std::endl;
}
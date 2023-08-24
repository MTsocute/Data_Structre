//
// Created by Momo on 2023/7/13.
//

#ifndef DATASTRUCTURE_顺序栈_H
#define DATASTRUCTURE_顺序栈_H
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#include <iostream>

using namespace std;

typedef int Status;

// 顺序栈
struct sqStack {
    int datas[MAXSIZE];
    int top;    // 栈顶指针
};

Status ini_stack(sqStack *&s);

Status push(sqStack *&s, int e);

Status pop(sqStack *&s);

Status is_stack_empty(sqStack *&s);

void traverse(sqStack *&s);

int get_length(sqStack *&s);

// 初始化栈
Status ini_stack(sqStack *&s) {
    // 如果栈不为空，那么就检查里面的要素，如果正确才给用
    if (s != nullptr) {
        if (get_length(s) == s->top + 1)
            return OK;
        else {
            cout << "Something wrong with top and data number\n";
            return ERROR;
        }
    }
    // 不存在就指定一个
    else {
        static sqStack stack = {{}, -1};
        s = &stack;
        cout << "Initialization Completed!\n";
        return OK;
    }
}

// 检查栈是否为空 top == -1, 但是如果没有初始化就是报错
Status is_stack_empty(sqStack *&s) {
    if(s == nullptr) {
        cout << "Stack doesn't exist\n";
        return ERROR;
    }
    if (s->top == -1)
        return OK;
    else
        return ERROR;
}

// 获取链表的长度
int get_length(sqStack *&s) {
    if(s == nullptr) {
        cout << "Stack doesn't exist\n";
        return ERROR;
    }
    if(!is_stack_empty(s))
        return s->top + 1;
    return 0;
}

// 插入栈
Status push(sqStack *&s, int e) {
    // 满栈直接结束
    if(s->top == MAXSIZE - 1) {
        cout << "Stack is full, you can't add new data.\n";
        return ERROR;
    }
    s->datas[++s->top] = e;
    return OK;
}

// 遍历栈
void traverse(sqStack *&s) {
    if (!is_stack_empty(s)) {
        cout << "Bottom -> ";
        for (int i = s->top; i >= 0; --i) {
            cout << s->datas[i] << " -> ";
        }
        cout << "Top" << endl;
    }
}

// 弹出栈
Status pop(sqStack *&s) {
    if(is_stack_empty(s)) {
        cout << "Stack is empty, there is no data to pop.\n";
        return ERROR;
    }
    s->datas[s->top--] = 0;
    return OK;
}

#endif //DATASTRUCTURE_顺序栈_H

//
// Created by Momo on 2023/7/17.
//

#ifndef DATASTRUCTURE_串_H
#define DATASTRUCTURE_串_H

#include <iostream>
#include <cstring>

/** 实现效果
 * 从 S 字符串中匹配，看有没有 T 这个子串
 * 如果有的话，返回在主串中第一次出现的开头位置
 * 反之，返回 -1
 * */

// 1、朴素 (Naive) 算法
int Index(const char *S, const char *T) {
    int index_main = 0;
    int index_sub = 0;

    int size_main = (int) strlen(S);
    int size_sub = (int) strlen(T);

    if (size_main < size_sub)
        return -1;

    // 如果主串遍历完了，或者说子串找到了，都结束
    // 不能是 or，不然哪怕子串遍历完了，主串可能没遍历完
    // 然后就导致循环继续，匹配对应不上
    while (index_sub < size_sub and index_main < size_main) {
        if (T[index_sub] == S[index_main]) {
            index_main++;
            index_sub++;
        } else {
            // 第一个位置匹配不上的时候，从第二个位置匹配
            index_main = index_main - index_sub + 1;
            index_sub = 0;
        }
    }
    if (index_sub == size_sub)
        return index_main - index_sub + 1;
    else
        return -1;
}

// 2、KMP 算法
int * buildNextArray(const char *pattern) {
    int par_len = strlen(pattern);
    int *next = new int[par_len];
    int pre = 0, rear = 1;
    next[0] = 0;

    while (rear < par_len) {
        // 匹配到了公共部分
        if (pattern[pre] == pattern[rear]) {
            next[rear] = pre + 1;   // pre 这里就是最大公共长度
            pre++;
            rear++;
        } else {
            // pre != 0 说明前面有一部分是匹配上的
            if (pre != 0) { // next 表记录了上一次的最大公共长度
                // 因为 pre != 0 就是有重合，而 next 记录的上一次公共部分和 rear 公共部分是相同的所以可以跳过
                // 一直重复比对，直到没有重复部分，既退回到开头(pre=0)
                pre = next[pre - 1];
            // 这个时候，开始和最后对不上，那就没有公共部分，比较其他的部分
            } else {
                next[rear] = 0;
                rear++;
            }
        }
    }
    return next;
}

/* 和主串比对的过程中，如果有对不上的时候，那我们就移动子串，从对不上的地方继续
 * 但是子串不一定需要从头开始比对，如果子串是有公共部分的话
 * 我们应该直接移动前后公共部分的长度
 * */
int Index_KMP(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int *next = buildNextArray(pattern);

    int i = 0, j = 0;   /* i 用于 text, j 用于 pattern */
    while (i < n && j < m) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            // j != 0 说明匹配上了一部分，但是有匹配不上的，所以要跳过一些减少匹配量
            // 跳过多少应该取决于 next 表
            if (j != 0)
                j = next[j - 1];   // 停止的位置对应就是 next 存储的位置
            else i++;    // 完全没有匹配上，从主串下个位置开始匹配
        }
    }

    delete[] next;

    if (j == m)
        return i - j + 1;
    else
        return -1;
}


#endif //DATASTRUCTURE_串_H

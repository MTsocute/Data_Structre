//
// Created by Momo on 2023/9/14.
//
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
static void shell_sort(vector<T> &v) {
    // 每一次的跳跃量
    for (int gap = v.size() / 2; gap > 0; gap /= 2) {
        // 把跳跃间隔之间的变量作为一个 "简单插入排序" 的子列
        for (int i = gap; i < v.size(); i++) {
            T key = v.at(i);
            int j = i - gap;    // 寻找 key 前面的元素
            while (j >= 0 and v.at(j) > key) {
                v.at(j + gap) = std::move(v.at(j)); // 向右移动
                j -= gap;
            }
            v.at(j + gap) = key;
        }
    }
}

int main() {
    vector<int> arr1 = {12, 11, 13, 5, 6};
    shell_sort(arr1);
    for (const auto &num: arr1)
        cout << num << " ";
    cout << endl;
    return 0;
}
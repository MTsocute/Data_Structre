//
// Created by Momo on 2023/9/13.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 从 key 位置开始，不断的之前元素是否比他大，如果是的话，我们把该元素右移动
 * 继续往前比较，总会有元素比 key 小的，我们停在那个位置的后一个位置
 * 比他大的全部都给移走了，腾出的空间就是给 key 的
 * 如果前面全部都比大的话，我们设置一个 >= 0 ，
 * 这样子 j 停止的时候是 -1 后面一个位置就是 0 ，即最开始的位置
 * */
template<class T>
void insertion_sort(vector<T> &v) {
    int n = v.size();

    for (int i = 1; i < n; ++i) {
        T key = v.at(i);
        int j = i - 1;

        // 将比 key 大的元素向右移动
        while (j >= 0 && v.at(j) > key) {
            v.at(j + 1) = v.at(j);
            j--;
        }

        // 右移停止，说明这个元素不比 key 大插入 key 到正确的位置
        // 前一个元素已经右移动了，我们插在这个位置的后一个
        // 如果前面没有一个元素比它大，j 是不动的，我们插入就是自己的位置
        v.at(j + 1) = key;
    }
}


int main() {
    vector<int> numbers = {7, 89, 31, 12, 14};

    insertion_sort(numbers);

    for (const auto &num: numbers)
        cout << num << " ";
    cout << endl;

    return 0;
}
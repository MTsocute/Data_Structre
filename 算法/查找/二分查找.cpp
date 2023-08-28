//
// Created by Momo on 2023/6/28.
//
#include <iostream>

using namespace std;

int binary_searh(const int * arr, int target, int len) {
    int low = 0;
    int high = len - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // 中间位置就是我们要找的时候
        if (arr[mid] == target)
            return mid;
        // 目标值 < 中间值
        else if (arr[mid] > target)
            high = mid - 1;     // 范围压缩到左边的位置
        // 目标值 > 中间值
        else
            low = mid + 1;      // 范围压缩到右边的位置
    }
    return 0;
}


int main() {
    int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    int target = 5;

    int index = binary_searh(arr, target, sizeof(arr) / sizeof(arr[0]));

    if (index != false)
        cout << "Index is " << index
        << ", No. " << index + 1 << " in array"
        << endl;
    else
        cout<< "Target isn't in array" << endl;

    return 0;
}
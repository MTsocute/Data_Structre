//
// Created by Momo on 2023/6/30.
//
#include <cstdio>

void selectionSort(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int min_idx = i;
        // 找到最小的那一个: 这个循环会一直比，然后找到对应最小的那个
        for (int j = i+1; j < len; ++j) {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        // 循环结束就是找打了最小的那个，我们交换位置
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

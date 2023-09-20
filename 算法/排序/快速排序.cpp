//
// Created by Momo on 2023/7/1.
//

#include <iostream>

using namespace std;

void quick_sort(int* arr, int start, int end){
    if(start >= end) return;    // 划分的子数组大小为0或1，已经完成排序
    int i = start, j = end, pivot = arr[(start + end) / 2];
    while(i < j) {
        // 这两个 while 是分开进行的，如果第一个while找到了比 pivot 小的数
        // 就会进行第二个 while 找到了比 pivot 大的数
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        // 说明还没有过完所有的数
        if(i <= j) {    // 这里是 = 处理重复的情况
            swap(arr[i], arr[j]);
            // 交换了以后防止这两个数再被遍历到，我们跳过他们
            i++; j--;
        }
    }

    quick_sort(arr, start, j);
    quick_sort(arr, i, end);
}


int main() {
    int a[] = {2,1,5,4,5,7,3, 6, 8} ;
    quick_sort(a, 0, (sizeof(a)/sizeof(int))-1);
    for (int i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}
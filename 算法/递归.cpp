//
// Created by Momo on 2023/7/1.
//
#include <iostream>

namespace recursion {
    void count(int i) {
        std::cout << "counting " << i << std::endl;
        if (i == 1)
            return;
        else
            count(i - 1);
    }

    // 利用递归遍历数组并求元素和
    int sum(const int *head, const int *end) {
        if (head == end)
            return 0;
        else
            return *head + sum(head + 1, end);
    }


    // 使用递归数组统计数组元素的个数
    int count_array(const int *head, const int *end) {
        if (head == end)
            return 0;
        else
            return 1 + count_array(head + 1, end);
    }

    // 使用递归找出数组中的最大值
    int find_max(const int *head, const int *end)
    {
      if (head == end)
          return *head;
      else
          return std::max(find_max(head+1, end), *head);
    }

}

int main() {
//    count(5);
    int arr[] = {20, 12, 6};

//    std::cout << sum(arr, arr + 3) << std::endl;
    // 使用统计递归数组
//    std::cout << recursion::count_array(arr, arr + 3) << std::endl;
    std::cout << recursion::find_max(arr, arr + 3) << std::endl;
    return 0;
}
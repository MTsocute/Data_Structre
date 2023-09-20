#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 下沉操作，用于调整堆 (建立大根堆)
void heapify(std::vector<int> &arr, int parent, int end) {
    int subTree = parent * 2 + 1; // 左子节点
    // 叶子结点不为空
    while (subTree <= end) {
        // 如果右子节点存在且右子节点 > 左子节点，就选择右子节点
        if (subTree < end && arr[subTree] < arr[subTree + 1]) subTree++;

        // 如果父节点 < 子节点，交换它们
        if (arr[parent] < arr[subTree]) swap(arr[parent], arr[subTree]);

        // 继续向下调整
        parent = subTree;   // 移动到交换的那个子树
        subTree = parent * 2 + 1;   // 获取那个子树的左子树
    }
}

// 堆排序函数
void heapSort(std::vector<int> &arr) {
    int n = (int) arr.size() - 1;   // 最后一个元素的位置

    // 建立大根堆
    for (int k = n / 2 - 1; k >= 0; k--)
        heapify(arr, k, n);

    // 排序
    for (int i = 0; i < n; i++) {
        /* 整个过程执行 i 次，所以我们要注意，动态变小 - i */
        // 交换堆顶元素与最后一个元素 --> 每一次把最大的往前送
        swap(arr[0], arr[n - i]);
        // 重新调整堆，排除最后一个元素
        heapify(arr, 0, n - 1 - i); // (n-1) 才是倒数第二个元素
    }
}

int main() {
    std::vector<int> arr = {49, 38, 65, 97, 76, 13, 69, 48};

    std::cout << "Original Array: ";
    for (const auto &num: arr)
        std::cout << num << " ";
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Sorted Array: ";
    for (const auto &num: arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}

import random


# 快速排序
def quick_sort(arr: list):
    # 如果只有一个元素或空，说明就是排序好的
    if len(arr) <= 1:
        return arr
    # 获取基准值
    pivot = random.choice(arr)  # 每一次把第一个作为基准值的话，最坏情况调用栈会很长，最好选中间的
    # 比基准值小的元素数组
    less = [i for i in arr[1:] if i < pivot]
    greater = [i for i in arr[1:] if i >= pivot]
    # 递归调用此函数以加速分成小到大或大到一个步骤
    return quick_sort(less) + [pivot] + quick_sort(greater)


def quick_sort_2(arr: list, start: int, end: int):
    if start >= end:
        return
    left: int = start
    right: int = end
    pivot: int = arr[(start + end) // 2]

    while left < right:
        while arr[left] < pivot:
            left += 1
        while arr[right] > pivot:
            right -= 1

        if left <= right:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1
    quick_sort_2(arr, start, right)
    quick_sort_2(arr, left, end)


if __name__ == '__main__':
    ls = [4, 2, 1, 3, 8, 10, 3, 4]
    print(quick_sort(arr=ls))

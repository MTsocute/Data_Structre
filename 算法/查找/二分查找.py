def binary_search(arr: list, target: int):
    low = 0
    high = len(arr) - 1

    while low <= high:
        # 中间元素的位置
        mid = (low + high) // 2

        # 检查中间元素是否是目标元素
        if arr[mid] == target:
            return mid

        # 如果中间元素大于目标元素，缩小查找范围至左半部分
        elif arr[mid] > target:
            high = mid - 1

        # 如果中间元素小于目标元素，缩小查找范围至右半部分
        else:
            low = mid + 1

    # 目标元素不存在于数组中
    return None


if __name__ == '__main__':
    arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    target = 5

    result = binary_search(arr, target)

    if result == None:
        print("目标元素不存在于数组中")
    else:
        print("目标元素位于索引", result)

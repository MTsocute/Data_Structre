def selection_sort(arr: list):
    n = len(arr)
    for i in range(n - 1):      # 执行次数 n-1
        min_idx = i
        for j in range(i + 1, n):       # 执行次数 (n-1) + .. + 1
            # 依次比较，找到依次相对最小的
            if arr[j] < arr[min_idx]:
                min_idx = j
        # 把最小的往前头移动
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


# Example usage
if __name__ == '__main__':
    arr = [64, 25, 12, 22, 11]
    sorted_arr = selection_sort(arr)
    print(sorted_arr)

def shell_sort(unordered_ls: list) -> None:
    n = len(unordered_ls)
    gap = n // 2
    while gap > 0:  # gap == 1 的时候，相当于直接插入排序
        for i in range(gap, n):
            key = unordered_ls[i]
            j = i - gap
            while (j >= 0 and unordered_ls[j] > key):
                unordered_ls[j + gap] = unordered_ls[j]
                j -= gap            
            unordered_ls[j + gap] = key
        gap //= 2

if __name__ == "__main__":
    ls = [30,120, 89, 1700, 78, 1290, 6790, 1888, 92, 109, 10, 40, 20, 50]
    shell_sort(ls)
    for i in ls:
        print(i, end=" ")
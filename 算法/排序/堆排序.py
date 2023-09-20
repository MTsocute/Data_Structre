#! python3

def heapify(big_root_heap: list, parent: int, end: int) -> None:
    """ 返回排序好的大根堆 """
    subTree: int = parent * 2 + 1
    while subTree <= end:
        if subTree < end and big_root_heap[subTree + 1] > big_root_heap[subTree]:
            subTree += 1
        if big_root_heap[parent] < big_root_heap[subTree]:
            big_root_heap[parent], big_root_heap[subTree] = big_root_heap[subTree], big_root_heap[parent]
        parent = subTree
        subTree = parent * 2 + 1


def heap_sort(unordered_ls: list) -> None:
    n: int = len(unordered_ls) - 1
    for f in range(int(n / 2) - 1, -1, -1):
        heapify(unordered_ls, f, n)

    for k in range(n):
        unordered_ls[0], unordered_ls[n - k] = unordered_ls[n - k], unordered_ls[0]
        heapify(unordered_ls, 0, n - 1 - k)


if __name__ == '__main__':
    ls: list = [10, 30, 80, 18, 31, 100, 21, 45, 39]
    heap_sort(ls)

    for i in ls:
        print(i, end=" ")

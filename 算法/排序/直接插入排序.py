def insert_sort(unordered_ls: list):
    for i in range(1, len(unordered_ls)):
        key = unordered_ls[i]
        j = i - 1

        # 把 key 前面比它大的元素 向右移动
        while j >= 0 and unordered_ls[j] > key:
            unordered_ls[j + 1] = unordered_ls[j]  # 前面的元素往后移动一个位置
            j -= 1;

        # 把 key 拆入到正确的位置
        unordered_ls[j + 1] = key


if __name__ == '__main__':
    ls = [10, 20, 11, 30, 50]
    insert_sort(ls)

    for i in ls:
        print(i, end=" ")

def merge_sort(unordered_ls: list) -> list:
    if len(unordered_ls) <= 1:
        return unordered_ls

    # 将列表分成两半
    mid = len(unordered_ls) // 2
    left_half = unordered_ls[:mid]
    right_half = unordered_ls[mid:]

    # 递归对左右两半进行归并排序
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    # 合并两个已排序的子列表
    return merge(left_half, right_half)


def merge(left: list, right: list) -> list:
    result = []     # 存储排序好的结果
    i = j = 0

    # 获取两个数组中小的部分排在 result list 里面
    # 获取完其中一个数组就结束
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # 这里写的非常巧妙，总有一个排序完了，所以我们获取其余部分是不会新增东西的
    # 没有排完的正好停在没有排序的位置，我们剩下的部分补充到数组中去
    result.extend(left[i:])
    result.extend(right[j:])
    return result


if __name__ == '__main__':
    arr = [12, 11, 13, 5, 6, 7]
    sorted_arr = merge_sort(arr)
    print(sorted_arr)

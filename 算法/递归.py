# 递归实现 从 i 开始倒计时
def count(i):
    print(i)  # 我们想实现的功能

    if i == 0:  # 基线条件：停止条件
        return
    else:  # 递归条件：自己调用自己的条件
        count(i - 1)


# 递归数组求数组元素的和
def sum(arr: list):
    if not arr:
        return 0
    else:
        return arr.pop(0) + sum(arr)


# 递归数组得数组元素个数
def count(arr: list):
    if arr:
        return 1 + count(arr[:-1])
    else:
        return 0


# 使用递归找出数组中最大的数
def find_biggest(arr: list):
    if len(arr) == 1:
        return arr[0]
    else:
        # return max(arr[0], find_biggest(arr[1:]))
        a = arr.pop(0)
        b = find_biggest(arr)
        return a if a >= b else b


if __name__ == '__main__':
    # count(10)
    ls = [12, 1, 12, 2]
    # print(sum(ls))
    print(find_biggest(ls))

def choose_sort(unordered_ls: list) -> None:
    for i in range(len(unordered_ls) - 1):
        min = i
        for j in range(i, len(unordered_ls)):
            if unordered_ls[j] < unordered_ls[min]:
                min = j
        if min != i:
            unordered_ls[min], unordered_ls[i] = unordered_ls[i], unordered_ls[min]


if __name__ == "__main__":
    ls = [20, 30, 10, 40, 50]
    choose_sort(ls)

    for i in ls:
        print(i, end=' ')

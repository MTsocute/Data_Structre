def bubble_sort(unsorted_ls: list):
    for i in range(len(unsorted_ls)-1):
        swapped: bool = False
        for j in range(i, len(unsorted_ls)-1-i):
            if unsorted_ls[j] > unsorted_ls[j + 1]:
                unsorted_ls[j], unsorted_ls[j + 1] = unsorted_ls[j + 1], unsorted_ls[j]
                swapped = True
            if swapped: break


if __name__ == '__main__':
    ls = [20, 10, 30, 40]
    bubble_sort(ls)
    for i in ls:
        print(f'{i} ', end='')
    print()
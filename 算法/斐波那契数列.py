def fibonacci_seq() -> list:
    arr = [0, 1]

    for index in range(2, 40):
        arr.append(arr[index - 2] + arr[index - 1])

    return arr


if __name__ == '__main__':
    ls: list = fibonacci_seq()
    for i in range(40):
        print(f'{ls[i]} ', end="")
    print()

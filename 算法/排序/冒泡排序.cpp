//
// Created by Momo on 2023/9/12.
//
#include <iostream>

using namespace std;

template<class T>
void bubble_sort(vector<T> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < v.size() - 1 - i; ++j)
            if (v.at(j) > v.at(j + 1)) {
                swap(v.at(j), v.at(j + 1));
                swapped = true;
            }
        // 如果冒泡了一轮，但是没有任何交换，我们可以提前退出
        if (swapped) break;
    }
}

template<class T>
void show_data(const vector<T> &v) {
    for (const auto &num: v)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> v{10, 2, 3, 12, 5, 9, 0};

    vector<string> vs{"you", "asshole", "bitch"};

    cout << "Original data: " << endl;
    show_data(v);

    bubble_sort(v);

    cout << "After Sorting: " << endl;
    show_data(v);

    return 0;
}
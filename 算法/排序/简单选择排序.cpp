#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
static void choose_sort(vector<T> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int min = i;
        for (int j = i; j < v.size(); j++)
            if (v[min] > v[j]) min = j;
        if (min != i) swap(v[min], v[i]);
    }
}

int main() {
    vector<int> v = {3, 1, 2, 4, 5};

    choose_sort(v);

    for (const auto &var: v)
        cout << var << " ";
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> vl(n1);
    vector<int> vr(n2);

    for (int i = 0; i < n1; ++i)
        vl[i] = v[l + i];

    for (int i = 0; i < n2; ++i)
        vr[i] = v[mid + 1 + i];

    int i = 0, j = 0, k = l;    // left 是每一次合并数组的最左边，我们依次排过来

    // 挑选两个数组中小的部分排序到前面
    while (i < n1 and j < n2) {
        // 这里控升｜降序
        if (vl[i] < vr[j]) {
            v[k] = vl[i];
            i++;
        } else {
            v[k] = vr[j];
            j++;
        }
        k++;
    }

    // 总有一个数组没有排序我完，然后排序那个数组
    while (i < n1) {
        v[k] = vl[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = vr[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &v, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge_sort(v, l, mid);
        merge_sort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}

int main() {
    vector<int> v = {10, 20, 40, 80, 5, 14, 30, 25};
    int n = static_cast<int>(v.size()) - 1; // 修正这里的数组长度

    merge_sort(v, 0, n);

    for (const auto &num: v)
        cout << num << " ";
    cout << endl;

    return 0;
}

/**
 * 算法君：一个专业的算法学习分享网站
 * 算法君：专业分享--数据剖析--算法精解
 * 算法君：http://www.suanfajun.com
 */

/*斐波那契查找法，前提是线性表必须有序,时间复杂度是O(logn)*/
#include<iostream>

const int MAXSIZE = 20;

void Fibonacci(int *f);


/*定义斐波那契查找法*/
int Fibonacci_Search(int *a, int n, int key) {
    int low, high, mid, i, k;
    int F[MAXSIZE];

    Fibonacci(F); //构造一个斐波那契数组F
    low = 1;   //最低下标记录为首位
    high = n;  //最高下标记录为末位
    k = 0;

    while (n > F[k])  //计算n位于斐波那契数列的位置
        k++;

    for (i = n; i < F[k] - 1; i++)  //将a的元素扩展到(某斐波那契数 - 1)，即F[k]-1
        a[i] = INT_MAX;

    while (low <= high) {
        mid = low + F[k - 1] - 1;   //计算当前分割的下标
        if (key < a[mid]) {
            high = mid - 1;
            k -= 1;
        } else if (key > a[mid]) {
            low = mid + 1;
            k -= 2;
        } else {
            if (mid <= n) return mid;   //若相当则说明mid即为查找到的位置
            else return n;     //若mid>n则说明是扩展的数值，返回n
        }
    }
    return -1;
}


/*用非递归法构造一个斐波那契数组*/
void Fibonacci(int *f) {
    f[0] = 1;
    f[1] = 1;

    for (int i = 2; i < MAXSIZE; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

int main() {
    int array[] = {0, 16, 24, 35, 47, 59, 62, 73, 88, 99};

    int number = Fibonacci_Search(array, sizeof(array) / sizeof(int), 99);
    std::cout << "位置是：array[" << number << "]\n";
    return 0;
}
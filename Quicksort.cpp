#include <iostream>
#include <vector>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 将给定数组a升序排序
// n：数组大小
// a：所给数组，大小为n
// 返回值：排序后的数组

int partition(vector<int>& a, int l, int r){
    int pivot = a[r];
    int i = l;
    //while 最好在最后写更新条件，要不然容易弄错
    while(l<=r){
        if (a[l] < pivot)
        {
            swap(a[i++], a[l]);
        }
        ++l;
    }
    swap(a[i], a[r]);
    return i;
}

void quicksort(vector<int>& a, int l, int r){
    if (l >= r)
    {
        return;
    }

    int pos = partition(a, l, r);
    //pos已就位
    quicksort(a, pos+1, r);
    quicksort(a, l, pos-1);
}

vector<int> getAnswer(int n, vector<int> a) {
    /* 请在这里设计你的算法 */
    quicksort(a, 0, n-1);
    return a;
}

// ================= 代码实现结束 =================

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    a = getAnswer(n, a);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
    return 0;
}

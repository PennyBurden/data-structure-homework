#include <iostream>
using namespace std;

int main() {
    //接收输入数据 
    int n, k;  // n: 蛋糕数量， k: 每个朋友最少得到的蛋糕重量
    int num = 0;  // 计数器，记录得到蛋糕的朋友数量
    int add = 0;  // 累加器，用于计算当前朋友已经得到的蛋糕重量
    cin >> n;
    cin >> k;
    int a[10000];  // 蛋糕重量数组
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];  // 接收蛋糕重量
    }

    // 遍历蛋糕数组，模拟蛋糕分配过程
    for (int i = 0; i < n; i++) {
        add += a[i];  // 累加当前蛋糕重量
        // 当当前朋友得到的蛋糕重量大于等于k时，计数器加一并重置累加器
        if (add >= k) {
            num++;
            add = 0;
        }
    }
    // 如果遍历完数组后累加器不为零，说明最后一位朋友得到的蛋糕重量小于k但不为零，将计数器加一
    if (add != 0) {
        num += 1;
    }

    // 输出得到蛋糕的朋友数量
    cout << num << endl;
    return 0;
}
#include <iostream>
#include <cstdlib>
using namespace std;

// 定义递归函数，计算多项式的值
double polynomial(int a[], int i, double x, int n)
{
    if (i > 0)
        return a[n - i] + polynomial(a, i - 1, x, n) * x; // 递归计算多项式值
    else
        return a[n]; // 递归结束条件，返回常数项
}

int main()
{
    double x;
    cout << "输入变量的值x:";
    cin >> x;
    int n;
    int i;
    cout << "输入多项式的阶次n:";
    cin >> n;
    int a[10];

    if (n > 9)
    {
        exit(0); // 如果多项式的阶次大于 9，退出程序
    }

    cout << "输入多项式的系数 a[0]--a[n]:";
    for (i = 0; i <= n; i++)
    {
        cin >> a[i]; // 输入多项式的系数
    }

    // 调用多项式计算函数并输出结果
    cout << "The polynomial value is " << polynomial(a, n, x, n) << endl;
    return 0;
}

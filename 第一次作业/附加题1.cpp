#include <iostream>
using namespace std;

int main()
{
    int n;
    int t;
    cin >> n; // 从标准输入读取 n 的值
    int a[100]; // 声明一个整数数组 a，用于存储结果
    int i;

    if (n > 99)
    {
        exit(0); // 如果 n 大于 99，退出程序
    }

    for (i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            a[i] = 1; // 对于 i 等于 0，a[i] 初始化为 1
        }
        else
        {
            t = 2 * i * a[i - 1]; // 计算新的 a[i] 值
            if (t > 65535)
            {
                exit(0); // 如果 t 大于 65535，退出程序
            }
            else
            {
                a[i] = 2 * i * a[i - 1]; // 更新 a[i] 的值
            }
        }
    }

    for (i = 0; i <= n; i++)
    {
        if (a[i] > 65535)
        {
            exit(0); // 如果 a[i] 大于 65535，退出程序
        }
        else
        {
            cout << a[i] << ' '; // 输出 a[i] 的值并添加空格
        }
    }

    return 0;
}

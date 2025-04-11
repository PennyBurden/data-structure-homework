

#include <iostream>
using namespace std;

// 定义一个结构体List，用于存储数据和长度
typedef struct List
{
    int data[128]; // 用于存储人员编号的数组
    int length;    // 数组的长度（未使用）
} List;

int main()
{
    List a1; // 创建一个List类型的结构体变量a1

    int n, m, i, j; // 声明整数变量n, m, i, j
    int num, count; // 声明整数变量num（剩余人数）和count（报数计数）
    count = 0; // 初始化报数计数

    cout << "请输入人数n：" << endl; // 提示用户输入人数n
    cin >> n; // 读取用户输入的人数n
    cout << "请输入报到的数m：" << endl; // 提示用户输入报到的数m
    cin >> m; // 读取用户输入的报到的数m
    num = n; // 初始化剩余人数为总人数n

    // 初始化a1的data数组，用于表示初始时的人员编号
    for (i = 1; i <= n; i++)
    {
        a1.data[i - 1] = i; // 初始化人员编号从1到n
    }

    bool a[128]; // 声明布尔数组a，用于表示每个人是否还在报到的循环中

    // 初始化布尔数组a，所有人初始都在报到循环中（1表示在，0表示出局）
    for (i = 0; i < n; i++)
    {
        a[i] = 1;
    }

    while (1) // 进入主循环
    {
        for (i = 0; i < n; i++) // 遍历所有人
        {
            if (a[i] == 1) // 如果该人仍在报到循环中
            {
                count++; // 增加报数计数
            }

            if (count == m) // 如果报数计数达到m
            {
                a[i] = 0; // 该人出局
                count = 0; // 重置报数计数
                num--; // 剩余人数减一
            }

            if (num == 1) // 如果只剩下一个人
            {
                for (i = 0; i < n; i++) // 找到最后留下的人
                {
                    if (a[i] == 1)
                    {
                        cout << "最后留下的人的编号是：" << i + 1 << endl; // 输出最后留下的人的编号
                        break;
                    }
                }
                break; // 退出循环
            }
        }

        if (num == 1) // 如果只剩下一个人，退出主循环
        {
            break;
        }
    }

    return 0;
}

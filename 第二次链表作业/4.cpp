#include<iostream>
using namespace std;

int main()
{
    int num;
    cin >> num; // 从标准输入读取整数N

    int the_numberof1[128] = { 0 }; // 初始化一个大小为100的整数数组b，并将所有元素初始化为0
    int the_numberof2[128] = { 0 }; // 初始化一个大小为100的整数数组c，并将所有元素初始化为0

    // 循环N次，处理N组输入数据
    for (int i = 0; i < num; i++)
    {
        int number;
        cin >> number; // 从标准输入读取整数n
        // 循环n次，处理n个整数数据
        for (int j = 0; j < number; j++)
        {
            int applefalls;
            cin >> applefalls; // 从标准输入读取整数aw

            // 如果b[i]为0，将其设置为aw的值
            if (the_numberof1[i] == 0)
            {
                the_numberof1[i] = applefalls;
            }
            // 如果aw小于等于0，将aw添加到b[i]
            else if (applefalls <= 0)
                the_numberof1[i] += applefalls;
            else
            {
                // 如果b[i]不等于aw，设置c[i]为1，并更新b[i]为aw
                if (the_numberof1[i] != applefalls)
                {
                    the_numberof2[i] = 1;
                    the_numberof1[i] = applefalls;
                }
            }
        }
    }
    int sum = 0;
    // 计算数组b中所有元素的总和
    for (int i = 0; i < num; i++)
    {
        sum += the_numberof1[i];
    }
    int a1 = 0;
    // 计算数组c中值为1的元素的数量
    for (int i = 0; i < num; i++)
    {
        if (the_numberof2[i] == 1)
            a1++;
    }
    int a2 = 0;
    // 检查特定条件下的数组c元素
    if (the_numberof2[0] == 1 && the_numberof2[1] == 1 && the_numberof2[num - 1] == 1)
        a2++;
    if (the_numberof2[0] == 1 && the_numberof2[num - 2] == 1 && the_numberof2[num - 1] == 1)
        a2++;
    for (int i = 2; i < num; i++)
    {
        if (the_numberof2[i] == 1 && the_numberof2[i - 1] == 1 && the_numberof2[i - 2] == 1)
            a2++;
    }
    // 输出计算结果
    cout << sum << ' ' << a1 << ' ' << a2;
}

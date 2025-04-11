#include <iostream>
using namespace std;

int main()
{
    int score = 0;   // 初始化得分为0
    int time = 2;    // 初始化时间为2
    int judge = 0;   // 初始化判断标志为0
    int num[30];     // 定义存储数字的数组
    int i = 0, length; // 初始化数组下标和数组长度

    cin >> num[0];    // 从标准输入读取第一个数字
    while (num[i] != 0)
    {
        i++;
        cin >> num[i]; // 读取直到遇到0，存储在数组中
    }
    length = i + 1;  // 计算数组的实际长度

    // 遍历数组中的数字
    for (i = 0; i < length; i++)
    {
        if (num[i] == 1)
        {
            score += 1;   // 如果数字为1，得分加1，重置判断标志
            judge = 0;
        }
        if (num[i] == 2)
        {
            if (judge == 0)
            {
                time = 2;     // 如果数字为2且判断标志为0，时间重置为2，得分加时间
                score += time;
                judge = 1;
                continue;
            }
            if (judge == 1)
            {
                time += 2;    // 如果数字为2且判断标志为1，时间加2，得分加时间
                score += time;
                continue;
            }
        }
    }

    cout << score; // 输出最终得分
}

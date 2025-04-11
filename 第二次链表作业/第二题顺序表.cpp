#include <iostream>
using namespace std;

// 定义一个结构体 List，用于存储数据和长度
typedef struct List
{
    int data[128];
    int length;
} List, * SList;

// 合并排序函数，将两个有序数组 a1 和 a2 合并到 a3 中，并排序 a3
int combinesort(SList a1, SList a2, SList& a3)
{
    int i = 0, j = 0;
    int temp;
    int str1, str2, str3;

    // 计算数组 a1 和 a2 的长度
    while (a1->data[i] != '\0')
    {
        i++;
    }
    str1 = i;

    while (a2->data[j] != '\0')
    {
        j++;
    }
    str2 = j;

    // 计算合并后的数组 a3 的长度
    str3 = str1 + str2;

    // 复制数组 a1 到 a3
    for (i = 0; i < str1; i++)
    {
        a3->data[i] = a1->data[i];
    }

    // 复制数组 a2 到 a3
    for (j = str1; j < str2 + str1; j++)
    {
        a3->data[j] = a2->data[j - str1];
    }

    // 使用冒泡排序算法对 a3 进行排序
    for (i = 0; i < str3; i++)
    {
        for (j = 0; j < str3; j++)
        {
            if (a3->data[i] > a3->data[j])
            {
                temp = a3->data[i];
                a3->data[i] = a3->data[j];
                a3->data[j] = temp;
            }
        }
    }
    return 0;
}

int main()
{
    List a1, a2, a3; // 定义三个结构体变量，用于存储数组和长度

    // 初始化数组 a1（假设 a1 是升序的数组）
    a1.length = 5;
    a1.data[0] = 1;
    a1.data[1] = 3;
    a1.data[2] = 5;
    a1.data[3] = 7;
    a1.data[4] = 9;

    // 初始化数组 a2（假设 a2 是升序的数组）
    a2.length = 4;
    a2.data[0] = 2;
    a2.data[1] = 4;
    a2.data[2] = 6;
    a2.data[3] = 8;

    // 初始化数组 a3，a3 的长度为 a1 和 a2 长度之和
    a3.length = a1.length + a2.length;

    // 调用合并排序函数将 a1 和 a2 合并为 a3
    combinesort(&a1, &a2, &a3);

    // 输出合并排序后的数组 a3
    cout << "合并排序后的数组 a3: ";
    for (int i = 0; i < a3.length; i++)
    {
        cout << a3.data[i] << " ";
    }
    cout << endl;

    return 0;
}

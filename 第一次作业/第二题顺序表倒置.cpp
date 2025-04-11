#include <iostream>
using namespace std;

// 定义包含整型数组和数组长度的结构
struct LNode
{
    int data[100]; // 整型数组，用于存储数据
    int length;     // 数组的有效长度
};

// 反转数组中的元素
void Reverse(LNode& L)
{
    int i, j;
    int a[L.length]; // 创建一个临时数组 a 用于存储反转后的数据

    // 从原数组 L.data 中倒序复制元素到临时数组 a
    for (i = 0; i < L.length; i++)
    {
        a[i] = L.data[L.length - 1 - i];
    }

    // 将临时数组 a 的元素复制回原数组 L.data，实现反转
    for (i = 0; i < L.length; i++)
    {
        L.data[i] = a[i];
    }
}

int main()
{
    LNode array;
    int n;

    // 读取数组长度
    cin >> n;

    // 读取数组元素
    for (int i = 0; i < n; i++)
    {
        cin >> array.data[i];
    }

    array.length = n; // 设置数组长度

    // 调用反转函数反转数组
    Reverse(array);

    // 输出反转后的数组
    for (int i = 0; i < array.length; i++)
    {
        cout << array.data[i] << " ";
    }

    return 0;
}

#include <iostream>
using namespace std;

// 定义一个结构体List，用于存储数据和长度
typedef struct List
{
    int data[128]; // 存储线性表的元素
    int length;    // 线性表的长度
} List;

// 冒泡排序函数，接收一个List的引用作为参数
void sort(List& L)
{
    int i, j;
    int temp;

    // 使用嵌套循环遍历线性表
    for (i = 0; i < L.length; i++)
    {
        for (j = 0; j < L.length; j++)
        {
            // 如果前一个元素大于后一个元素，交换它们
            if (L.data[i] > L.data[j])
            {
                temp = L.data[i];
                L.data[i] = L.data[j];
                L.data[j] = temp;
            }
        }
    }
}

int main()
{
    List a1; // 创建一个List类型的结构体变量a1
    int n;

    // 读取用户输入的线性表长度
    cout << "请输入线性表的长度: ";
    cin >> n;

    a1.length = n; // 设置线性表的长度

    // 读取线性表的元素值
    for (int i = 0; i < n; i++)
    {
        cout << "请输入第 " << i + 1 << " 个元素的值: ";
        cin >> a1.data[i];
    }

    cout << "原始线性表: ";
    for (int i = 0; i < n; i++)
    {
        cout << a1.data[i] << " ";
    }
    cout << endl;

    // 调用排序函数对线性表进行排序
    sort(a1);

    cout << "排序后的线性表: ";
    for (int i = 0; i < n; i++)
    {
        cout << a1.data[i] << " ";
    }
    cout << endl;

    return 0;
}

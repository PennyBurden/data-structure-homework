#include <iostream>
using namespace std;

// 定义顺序表结构
struct SeqList
{
    int data[128]; // 整型数组，用于存储数据
    int length;    // 数组的有效长度
};

// 删除顺序表中的重复元素
void delete_the_same(SeqList& L)
{
    int i, j, k;

    if (L.length <= 1)
    {
        return; // 如果数组长度小于等于1，无需删除重复元素
    }

    // 遍历数组元素
    for (i = 0; i < L.length; i++)
    {
        for (j = i; j < L.length; j++)
        {
            if (L.data[i] == L.data[j])
            {
                // 如果找到重复元素，向前移动元素以覆盖重复元素
                for (k = j; k < L.length - 1; k++)
                {
                    L.data[k] = L.data[k + 1];
                }

                if (j == L.length - 1)
                {
                    L.data[j] = 0; // 如果重复元素在数组末尾，将其置为0
                }

                L.length--; // 减少数组长度，因为有一个重复元素被删除
            }
        }
    }
}

int main()
{
    // 在主函数中使用 delete_the_same 函数来删除数组中的重复元素
    SeqList list;
    // 初始化数组并添加元素
    // ...

    // 调用 delete_the_same 函数删除重复元素
    delete_the_same(list);

    // 打印删除重复元素后的数组
    // ...

    return 0;
}

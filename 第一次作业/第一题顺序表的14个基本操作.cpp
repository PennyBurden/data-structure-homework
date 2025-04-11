#include <iostream>
using namespace std;

// 定义顺序表结构
typedef struct SeqList
{
    char* pData;      // 存储数据的指针
    int length;       // 当前数据的长度
    int size;         // 顺序表的总大小
} SeqList;

// 初始化顺序表
int InitList(SeqList& L)
{
    L.pData = (char*)malloc(LISTINITSIZE * sizeof(char)); // 分配顺序表内存
    if (L.pData == NULL)
        exit(0);

    L.size = LISTINITSIZE; // 初始化顺序表大小
    L.length = 0;         // 初始化数据长度为0
    return 1;              // 初始化成功
}

// 销毁顺序表
int DestoryList(SeqList& L)
{
    if (L.pData != NULL)
    {
        free(L.pData); // 释放顺序表内存
        L.pData = NULL;
    }

    L.size = 0;    // 重置顺序表大小
    L.length = 0;  // 重置数据长度
    return 1;       // 销毁成功
}

// 清空顺序表
int ClearList(SeqList& L)
{
    L.length = 0;   // 重置数据长度为0
    return 1;        // 清空成功
}

// 获取指定位置的元素
int GetElem(SeqList L, int i, char& e)
{
    if (i < 1 || i > L.length)
    {
        return 0; // 位置 i 不合法
    }
    e = L.pData[i - 1]; // 获取元素
    return 1;            // 获取成功
}

// 定位元素在顺序表中的位置
int LocateElem(SeqList L, char e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.pData[i] == e)
        {
            return i + 1; // 找到元素 e 在位置 i+1
        }
    }
    return 0; // 未找到元素 e
}

// 设置指定位置元素的值
int SetElem(SeqList& L, int i, char& e)
{
    if (i < 1 || i > L.length)
    {
        return 0; // 位置 i 不合法
    }
    char temp;
    temp = L.pData[i - 1];
    L.pData[i - 1] = e; // 设置新值
    e = temp;
    return 1;            // 设置成功
}

// 在指定位置插入元素
int InsertElem(SeqList& L, int i, char e)
{
    int j;
    char* newbase;
    if (i < 1 || i > L.length + 1)
    {
        return 0; // 位置 i 不合法
    }
    if (L.length >= L.size)
    {
        newbase = (char*)realloc(L.pData, (L.size + LISTINCREMENT) * sizeof(char)); // 重新分配内存
        if (newbase == NULL)
            exit(0);
        L.pData = newbase;
        L.size += LISTINCREMENT;
    }
    for (j = L.length - 1; j >= i - 1; j--)
        L.pData[j + 1] = L.pData[j]; // 向后移动元素以腾出位置
    L.pData[i - 1] = e; // 插入新元素
    L.length += 1;     // 长度加一
    return 1;           // 插入成功
}

// 获取顺序表的长度
int ListLength(SeqList& L)
{
    return L.length; // 返回顺序表长度
}

// 检查顺序表是否为空
bool ListEmpty(SeqList& L)
{
    if (L.length == 0)
    {
        return true; // 顺序表为空
    }
    else
    {
        return false; // 顺序表非空
    }
}

// 删除指定位置的元素
int DeleteElem(SeqList& L, int i, char& e)
{
    int j;
    if (i < 1 || i > L.length)
    {
        return 0; // 位置 i 不合法
    }
    e = L.pData[i - 1]; // 获取要删除的元素
    for (j = i; j < L.length; j++)
    {
        L.pData[j - 1] = L.pData[j]; // 向前移动元素以覆盖被删除的元素
    }
    L.length -= 1; // 长度减一
    return 1;       // 删除成功
}

// 获取指定元素的前驱元素
int PriorElem(SeqList& L, char cur_e, char& pre_e)
{
    int i;
    if (L.pData[0] == cur_e)
    {
        exit(0); // 头元素没有前驱元素
    }
    for (i = 0; i < L.length; i++)
    {
        if (L.pData[i] == cur_e)
        {
            pre_e = L.pData[i - 1]; // 获取前驱元素
            break;
        }
    }
    return 1; // 获取成功
}

// 获取指定元素的后继元素
int NextElem(SeqList& L, char cur_e, char& next_e)
{
    int i;
    if (L.pData[L.length - 1] == cur_e)
    {
        exit(0); // 尾元素没有后继元素
    }
    for (i = 0; i < L.length; i++)
    {
        if (L.pData[i] == cur_e)
        {
            next_e = L.pData[i + 1]; // 获取后继元素
            break;
        }
    }
    return 1; // 获取成功
}

// 遍历顺序表并输出元素
int ListTraverse(SeqList& L)
{
    if (L.length == 0)
    {
        exit(0); // 顺序表为空
    }
    int i;
    for (i = 0; i < L.length; i++)
    {
        cout << L.pData[i]; // 输出元素
    }
}

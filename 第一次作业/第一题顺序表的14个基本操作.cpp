#include <iostream>
using namespace std;

// ����˳���ṹ
typedef struct SeqList
{
    char* pData;      // �洢���ݵ�ָ��
    int length;       // ��ǰ���ݵĳ���
    int size;         // ˳�����ܴ�С
} SeqList;

// ��ʼ��˳���
int InitList(SeqList& L)
{
    L.pData = (char*)malloc(LISTINITSIZE * sizeof(char)); // ����˳����ڴ�
    if (L.pData == NULL)
        exit(0);

    L.size = LISTINITSIZE; // ��ʼ��˳����С
    L.length = 0;         // ��ʼ�����ݳ���Ϊ0
    return 1;              // ��ʼ���ɹ�
}

// ����˳���
int DestoryList(SeqList& L)
{
    if (L.pData != NULL)
    {
        free(L.pData); // �ͷ�˳����ڴ�
        L.pData = NULL;
    }

    L.size = 0;    // ����˳����С
    L.length = 0;  // �������ݳ���
    return 1;       // ���ٳɹ�
}

// ���˳���
int ClearList(SeqList& L)
{
    L.length = 0;   // �������ݳ���Ϊ0
    return 1;        // ��ճɹ�
}

// ��ȡָ��λ�õ�Ԫ��
int GetElem(SeqList L, int i, char& e)
{
    if (i < 1 || i > L.length)
    {
        return 0; // λ�� i ���Ϸ�
    }
    e = L.pData[i - 1]; // ��ȡԪ��
    return 1;            // ��ȡ�ɹ�
}

// ��λԪ����˳����е�λ��
int LocateElem(SeqList L, char e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.pData[i] == e)
        {
            return i + 1; // �ҵ�Ԫ�� e ��λ�� i+1
        }
    }
    return 0; // δ�ҵ�Ԫ�� e
}

// ����ָ��λ��Ԫ�ص�ֵ
int SetElem(SeqList& L, int i, char& e)
{
    if (i < 1 || i > L.length)
    {
        return 0; // λ�� i ���Ϸ�
    }
    char temp;
    temp = L.pData[i - 1];
    L.pData[i - 1] = e; // ������ֵ
    e = temp;
    return 1;            // ���óɹ�
}

// ��ָ��λ�ò���Ԫ��
int InsertElem(SeqList& L, int i, char e)
{
    int j;
    char* newbase;
    if (i < 1 || i > L.length + 1)
    {
        return 0; // λ�� i ���Ϸ�
    }
    if (L.length >= L.size)
    {
        newbase = (char*)realloc(L.pData, (L.size + LISTINCREMENT) * sizeof(char)); // ���·����ڴ�
        if (newbase == NULL)
            exit(0);
        L.pData = newbase;
        L.size += LISTINCREMENT;
    }
    for (j = L.length - 1; j >= i - 1; j--)
        L.pData[j + 1] = L.pData[j]; // ����ƶ�Ԫ�����ڳ�λ��
    L.pData[i - 1] = e; // ������Ԫ��
    L.length += 1;     // ���ȼ�һ
    return 1;           // ����ɹ�
}

// ��ȡ˳���ĳ���
int ListLength(SeqList& L)
{
    return L.length; // ����˳�����
}

// ���˳����Ƿ�Ϊ��
bool ListEmpty(SeqList& L)
{
    if (L.length == 0)
    {
        return true; // ˳���Ϊ��
    }
    else
    {
        return false; // ˳���ǿ�
    }
}

// ɾ��ָ��λ�õ�Ԫ��
int DeleteElem(SeqList& L, int i, char& e)
{
    int j;
    if (i < 1 || i > L.length)
    {
        return 0; // λ�� i ���Ϸ�
    }
    e = L.pData[i - 1]; // ��ȡҪɾ����Ԫ��
    for (j = i; j < L.length; j++)
    {
        L.pData[j - 1] = L.pData[j]; // ��ǰ�ƶ�Ԫ���Ը��Ǳ�ɾ����Ԫ��
    }
    L.length -= 1; // ���ȼ�һ
    return 1;       // ɾ���ɹ�
}

// ��ȡָ��Ԫ�ص�ǰ��Ԫ��
int PriorElem(SeqList& L, char cur_e, char& pre_e)
{
    int i;
    if (L.pData[0] == cur_e)
    {
        exit(0); // ͷԪ��û��ǰ��Ԫ��
    }
    for (i = 0; i < L.length; i++)
    {
        if (L.pData[i] == cur_e)
        {
            pre_e = L.pData[i - 1]; // ��ȡǰ��Ԫ��
            break;
        }
    }
    return 1; // ��ȡ�ɹ�
}

// ��ȡָ��Ԫ�صĺ��Ԫ��
int NextElem(SeqList& L, char cur_e, char& next_e)
{
    int i;
    if (L.pData[L.length - 1] == cur_e)
    {
        exit(0); // βԪ��û�к��Ԫ��
    }
    for (i = 0; i < L.length; i++)
    {
        if (L.pData[i] == cur_e)
        {
            next_e = L.pData[i + 1]; // ��ȡ���Ԫ��
            break;
        }
    }
    return 1; // ��ȡ�ɹ�
}

// ����˳������Ԫ��
int ListTraverse(SeqList& L)
{
    if (L.length == 0)
    {
        exit(0); // ˳���Ϊ��
    }
    int i;
    for (i = 0; i < L.length; i++)
    {
        cout << L.pData[i]; // ���Ԫ��
    }
}

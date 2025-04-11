#include <iostream>
using namespace std;

// ����һ���ṹ�� List�����ڴ洢���ݺͳ���
typedef struct List
{
    int data[128];
    int length;
} List, * SList;

// �ϲ����������������������� a1 �� a2 �ϲ��� a3 �У������� a3
int combinesort(SList a1, SList a2, SList& a3)
{
    int i = 0, j = 0;
    int temp;
    int str1, str2, str3;

    // �������� a1 �� a2 �ĳ���
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

    // ����ϲ�������� a3 �ĳ���
    str3 = str1 + str2;

    // �������� a1 �� a3
    for (i = 0; i < str1; i++)
    {
        a3->data[i] = a1->data[i];
    }

    // �������� a2 �� a3
    for (j = str1; j < str2 + str1; j++)
    {
        a3->data[j] = a2->data[j - str1];
    }

    // ʹ��ð�������㷨�� a3 ��������
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
    List a1, a2, a3; // ���������ṹ����������ڴ洢����ͳ���

    // ��ʼ������ a1������ a1 ����������飩
    a1.length = 5;
    a1.data[0] = 1;
    a1.data[1] = 3;
    a1.data[2] = 5;
    a1.data[3] = 7;
    a1.data[4] = 9;

    // ��ʼ������ a2������ a2 ����������飩
    a2.length = 4;
    a2.data[0] = 2;
    a2.data[1] = 4;
    a2.data[2] = 6;
    a2.data[3] = 8;

    // ��ʼ������ a3��a3 �ĳ���Ϊ a1 �� a2 ����֮��
    a3.length = a1.length + a2.length;

    // ���úϲ��������� a1 �� a2 �ϲ�Ϊ a3
    combinesort(&a1, &a2, &a3);

    // ����ϲ����������� a3
    cout << "�ϲ����������� a3: ";
    for (int i = 0; i < a3.length; i++)
    {
        cout << a3.data[i] << " ";
    }
    cout << endl;

    return 0;
}

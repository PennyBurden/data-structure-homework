#include <iostream>
using namespace std;

// �������������������鳤�ȵĽṹ
struct LNode
{
    int data[100]; // �������飬���ڴ洢����
    int length;     // �������Ч����
};

// ��ת�����е�Ԫ��
void Reverse(LNode& L)
{
    int i, j;
    int a[L.length]; // ����һ����ʱ���� a ���ڴ洢��ת�������

    // ��ԭ���� L.data �е�����Ԫ�ص���ʱ���� a
    for (i = 0; i < L.length; i++)
    {
        a[i] = L.data[L.length - 1 - i];
    }

    // ����ʱ���� a ��Ԫ�ظ��ƻ�ԭ���� L.data��ʵ�ַ�ת
    for (i = 0; i < L.length; i++)
    {
        L.data[i] = a[i];
    }
}

int main()
{
    LNode array;
    int n;

    // ��ȡ���鳤��
    cin >> n;

    // ��ȡ����Ԫ��
    for (int i = 0; i < n; i++)
    {
        cin >> array.data[i];
    }

    array.length = n; // �������鳤��

    // ���÷�ת������ת����
    Reverse(array);

    // �����ת�������
    for (int i = 0; i < array.length; i++)
    {
        cout << array.data[i] << " ";
    }

    return 0;
}

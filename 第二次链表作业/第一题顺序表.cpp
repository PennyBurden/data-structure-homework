#include <iostream>
using namespace std;

// ����һ���ṹ��List�����ڴ洢���ݺͳ���
typedef struct List
{
    int data[128]; // �洢���Ա��Ԫ��
    int length;    // ���Ա�ĳ���
} List;

// ð��������������һ��List��������Ϊ����
void sort(List& L)
{
    int i, j;
    int temp;

    // ʹ��Ƕ��ѭ���������Ա�
    for (i = 0; i < L.length; i++)
    {
        for (j = 0; j < L.length; j++)
        {
            // ���ǰһ��Ԫ�ش��ں�һ��Ԫ�أ���������
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
    List a1; // ����һ��List���͵Ľṹ�����a1
    int n;

    // ��ȡ�û���������Ա���
    cout << "���������Ա�ĳ���: ";
    cin >> n;

    a1.length = n; // �������Ա�ĳ���

    // ��ȡ���Ա��Ԫ��ֵ
    for (int i = 0; i < n; i++)
    {
        cout << "������� " << i + 1 << " ��Ԫ�ص�ֵ: ";
        cin >> a1.data[i];
    }

    cout << "ԭʼ���Ա�: ";
    for (int i = 0; i < n; i++)
    {
        cout << a1.data[i] << " ";
    }
    cout << endl;

    // ���������������Ա��������
    sort(a1);

    cout << "���������Ա�: ";
    for (int i = 0; i < n; i++)
    {
        cout << a1.data[i] << " ";
    }
    cout << endl;

    return 0;
}

#include<iostream>
using namespace std;

int main()
{
    int num;
    cin >> num; // �ӱ�׼�����ȡ����N

    int the_numberof1[128] = { 0 }; // ��ʼ��һ����СΪ100����������b����������Ԫ�س�ʼ��Ϊ0
    int the_numberof2[128] = { 0 }; // ��ʼ��һ����СΪ100����������c����������Ԫ�س�ʼ��Ϊ0

    // ѭ��N�Σ�����N����������
    for (int i = 0; i < num; i++)
    {
        int number;
        cin >> number; // �ӱ�׼�����ȡ����n
        // ѭ��n�Σ�����n����������
        for (int j = 0; j < number; j++)
        {
            int applefalls;
            cin >> applefalls; // �ӱ�׼�����ȡ����aw

            // ���b[i]Ϊ0����������Ϊaw��ֵ
            if (the_numberof1[i] == 0)
            {
                the_numberof1[i] = applefalls;
            }
            // ���awС�ڵ���0����aw��ӵ�b[i]
            else if (applefalls <= 0)
                the_numberof1[i] += applefalls;
            else
            {
                // ���b[i]������aw������c[i]Ϊ1��������b[i]Ϊaw
                if (the_numberof1[i] != applefalls)
                {
                    the_numberof2[i] = 1;
                    the_numberof1[i] = applefalls;
                }
            }
        }
    }
    int sum = 0;
    // ��������b������Ԫ�ص��ܺ�
    for (int i = 0; i < num; i++)
    {
        sum += the_numberof1[i];
    }
    int a1 = 0;
    // ��������c��ֵΪ1��Ԫ�ص�����
    for (int i = 0; i < num; i++)
    {
        if (the_numberof2[i] == 1)
            a1++;
    }
    int a2 = 0;
    // ����ض������µ�����cԪ��
    if (the_numberof2[0] == 1 && the_numberof2[1] == 1 && the_numberof2[num - 1] == 1)
        a2++;
    if (the_numberof2[0] == 1 && the_numberof2[num - 2] == 1 && the_numberof2[num - 1] == 1)
        a2++;
    for (int i = 2; i < num; i++)
    {
        if (the_numberof2[i] == 1 && the_numberof2[i - 1] == 1 && the_numberof2[i - 2] == 1)
            a2++;
    }
    // ���������
    cout << sum << ' ' << a1 << ' ' << a2;
}

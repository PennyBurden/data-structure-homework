#include <iostream>
using namespace std;

int main()
{
    int n;
    int t;
    cin >> n; // �ӱ�׼�����ȡ n ��ֵ
    int a[100]; // ����һ���������� a�����ڴ洢���
    int i;

    if (n > 99)
    {
        exit(0); // ��� n ���� 99���˳�����
    }

    for (i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            a[i] = 1; // ���� i ���� 0��a[i] ��ʼ��Ϊ 1
        }
        else
        {
            t = 2 * i * a[i - 1]; // �����µ� a[i] ֵ
            if (t > 65535)
            {
                exit(0); // ��� t ���� 65535���˳�����
            }
            else
            {
                a[i] = 2 * i * a[i - 1]; // ���� a[i] ��ֵ
            }
        }
    }

    for (i = 0; i <= n; i++)
    {
        if (a[i] > 65535)
        {
            exit(0); // ��� a[i] ���� 65535���˳�����
        }
        else
        {
            cout << a[i] << ' '; // ��� a[i] ��ֵ����ӿո�
        }
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
using namespace std;

// ����ݹ麯�����������ʽ��ֵ
double polynomial(int a[], int i, double x, int n)
{
    if (i > 0)
        return a[n - i] + polynomial(a, i - 1, x, n) * x; // �ݹ�������ʽֵ
    else
        return a[n]; // �ݹ�������������س�����
}

int main()
{
    double x;
    cout << "���������ֵx:";
    cin >> x;
    int n;
    int i;
    cout << "�������ʽ�Ľ״�n:";
    cin >> n;
    int a[10];

    if (n > 9)
    {
        exit(0); // �������ʽ�Ľ״δ��� 9���˳�����
    }

    cout << "�������ʽ��ϵ�� a[0]--a[n]:";
    for (i = 0; i <= n; i++)
    {
        cin >> a[i]; // �������ʽ��ϵ��
    }

    // ���ö���ʽ���㺯����������
    cout << "The polynomial value is " << polynomial(a, n, x, n) << endl;
    return 0;
}

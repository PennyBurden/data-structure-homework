#include <iostream>
using namespace std;

// �������ڼ��㽻ͨ�źŵƵĵȴ�ʱ��
int waitTime(long long cur, int k, int t, int r, int g, int T, int y, int n)
{
    switch (k) {
    case 1: // ���
    {
        cur += r - t; // ������ʱ��ʣ��ȴ�ʱ��
        break;
    }
    case 2: // �Ƶ�
    {
        cur += r + g + y - t; // ����Ƶ�ʱ��ʣ��ȴ�ʱ��
        break;
    }
    default: // �̵ƻ�δ֪��
    {
        cur += r + g - t; // �����̵ƻ�δ֪��ʱ��ʣ��ȴ�ʱ��
        break;
    }
    }
    int d = cur % T;
    if (d < r)
        return r - d; // �ں��ǰ������غ��ʣ��ȴ�ʱ��
    if (d < r + g)
        return 0; // ���̵�ǰ����ȴ�ʱ��Ϊ0
    return T - d + r; // �ڻƵ�ǰ������ػƵ�ʣ��ȴ�ʱ��
}

int main()
{
    int r, y, g, T;
    int n;
    int k, t;
    cin >> r >> y >> g;
    T = r + y + g; // ������ʱ��
    cin >> n;
    long long total = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k >> t;
        if (k == 0)
            total += t; // ���������ȴ��������ֱ���ۼ�ʱ��
        else
            total += waitTime(total, k, t, r, g, T, y, n); // �������ȴ�ʱ�䲢�ۼ�
    }

    cout << total; // ����ܵȴ�ʱ��
    return 0;
}

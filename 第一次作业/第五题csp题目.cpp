#include <iostream>
using namespace std;

int main()
{
    int score = 0;   // ��ʼ���÷�Ϊ0
    int time = 2;    // ��ʼ��ʱ��Ϊ2
    int judge = 0;   // ��ʼ���жϱ�־Ϊ0
    int num[30];     // ����洢���ֵ�����
    int i = 0, length; // ��ʼ�������±�����鳤��

    cin >> num[0];    // �ӱ�׼�����ȡ��һ������
    while (num[i] != 0)
    {
        i++;
        cin >> num[i]; // ��ȡֱ������0���洢��������
    }
    length = i + 1;  // ���������ʵ�ʳ���

    // ���������е�����
    for (i = 0; i < length; i++)
    {
        if (num[i] == 1)
        {
            score += 1;   // �������Ϊ1���÷ּ�1�������жϱ�־
            judge = 0;
        }
        if (num[i] == 2)
        {
            if (judge == 0)
            {
                time = 2;     // �������Ϊ2���жϱ�־Ϊ0��ʱ������Ϊ2���÷ּ�ʱ��
                score += time;
                judge = 1;
                continue;
            }
            if (judge == 1)
            {
                time += 2;    // �������Ϊ2���жϱ�־Ϊ1��ʱ���2���÷ּ�ʱ��
                score += time;
                continue;
            }
        }
    }

    cout << score; // ������յ÷�
}

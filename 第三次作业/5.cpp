#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, i, j, e;
	int min;  // �����洢��ǰ����С��ֵ
	cin >> n;
	if (n < 2)
	{
		cout << "����������������" << endl;
	}
	int a[1000];  // �洢���������

	// ��������
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	// ��ʼ����С��ֵΪ�����ǰ����Ԫ�صĲ�ֵ
	min = abs(a[1] - a[0]);

	// �������е����ԣ��ҳ���ֵ��С������
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			e = abs(a[j] - a[i]);  // ���㵱ǰ���ԵĲ�ֵ
			if (min > e)  // �����ǰ��ֵС����С��ֵ����ô������С��ֵ
			{
				min = e;
			}
		}
	}

	// �����С��ֵ
	cout << min;
}
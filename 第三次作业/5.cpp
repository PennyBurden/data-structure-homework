#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, i, j, e;
	int min;  // 用来存储当前的最小差值
	cin >> n;
	if (n < 2)
	{
		cout << "至少输入两个数字" << endl;
	}
	int a[1000];  // 存储输入的数组

	// 输入数组
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	// 初始化最小差值为数组的前两个元素的差值
	min = abs(a[1] - a[0]);

	// 遍历所有的数对，找出差值最小的数对
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			e = abs(a[j] - a[i]);  // 计算当前数对的差值
			if (min > e)  // 如果当前差值小于最小差值，那么更新最小差值
			{
				min = e;
			}
		}
	}

	// 输出最小差值
	cout << min;
}
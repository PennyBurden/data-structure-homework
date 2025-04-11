#include <iostream>
using namespace std;
int main()
{
	double a[2000], b[2000], c[2000], d[2000];
	double n;
	double time;
	double totaltime = 0;
	cin >> n;
	int i, j;
	//bool k1[2000];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	for (i = 0; i < n; i++)
	{
		cin >> c[i];
		cin >> d[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (c[j] < a[i])
			{
				if (d[j] <= a[i])
				{
					time = 0;
					continue;
				}
				if (d[j] > a[i] && d[j] <= b[i])
				{
					time = d[j] - a[i];
					totaltime += time;
					continue;
				}
				if (d[j] > b[i])
				{
					time = b[i] - a[i];
					totaltime += time;
					continue;
				}
			}
			if (c[j] >= a[i]&&c[j] <= b[i])
			{
				if (d[j] <= b[i])
				{
					time =d[j] - c[j];
					totaltime += time;
					continue;
				}
				if (d[j] >= b[i])
				{
					time = b[i] - c[j];
					totaltime += time;
					continue;
				}

			}
			if (c[j] > b[i])
			{
				time = 0;
				totaltime += time;
				break;
			}

		}
	}
	cout << totaltime;
	return 0;
}
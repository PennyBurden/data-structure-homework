#include <iostream>
using namespace std;

// 函数用于计算交通信号灯的等待时间
int waitTime(long long cur, int k, int t, int r, int g, int T, int y, int n)
{
    switch (k) {
    case 1: // 红灯
    {
        cur += r - t; // 计算红灯时的剩余等待时间
        break;
    }
    case 2: // 黄灯
    {
        cur += r + g + y - t; // 计算黄灯时的剩余等待时间
        break;
    }
    default: // 绿灯或未知灯
    {
        cur += r + g - t; // 计算绿灯或未知灯时的剩余等待时间
        break;
    }
    }
    int d = cur % T;
    if (d < r)
        return r - d; // 在红灯前到达，返回红灯剩余等待时间
    if (d < r + g)
        return 0; // 在绿灯前到达，等待时间为0
    return T - d + r; // 在黄灯前到达，返回黄灯剩余等待时间
}

int main()
{
    int r, y, g, T;
    int n;
    int k, t;
    cin >> r >> y >> g;
    T = r + y + g; // 总周期时间
    cin >> n;
    long long total = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k >> t;
        if (k == 0)
            total += t; // 如果是无需等待的情况，直接累加时间
        else
            total += waitTime(total, k, t, r, g, T, y, n); // 否则计算等待时间并累加
    }

    cout << total; // 输出总等待时间
    return 0;
}

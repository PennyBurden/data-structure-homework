#include <iostream>

using namespace std;

// 删除A中同时存在于B和C的元素
void deleteCommonElements(int A[], int& m, int B[], int n, int C[], int k) 
{
    int i = 0; // 用于遍历A
    int j = 0; // 用于遍历B
    int l = 0; // 用于遍历C

    while (i < m && j < n && l < k)
    {
        if (B[j] == C[l]) 
        {
            // 如果B[j]和C[l]相等，说明A[i]在B和C中都存在，从A中删除该元素
            for (int p = i; p < m - 1; p++)
            {
                A[p] = A[p + 1];
            }
            m--; // 更新A的长度
        }
        else if (A[i] < B[j] && A[i] < C[l]) 
        {
            // 如果A[i]小于B[j]和C[l]，说明A[i]不可能在B和C中存在，继续检查下一个A元素
            i++;
        }
        else if (B[j] < C[l]) 
        {
            // 如果B[j]小于C[l]，说明B[j]不可能存在于A中，继续检查下一个B元素
            j++;
        }
        else 
        {
            // 否则，C[l]不可能存在于A中，继续检查下一个C元素
            l++;
        }
    }
}

int main()
{
    int i;
    int A[] = { 1, 2, 3, 4, 5 };
    cout << "A：";
    for (i = 0; i < 5; i++)
    {
        cout << A[i] <<' ';
    }
    cout << endl;
    int B[] = { 3, 4, 7 };
    cout << "B：";
    for (i = 0; i < 3; i++)
    {
        cout << B[i] <<' ';
    }
    int C[] = { 2, 4, 6 };
    cout << endl;
    cout << "C：";
    for (i = 0; i < 3; i++)
    {
        
        cout << C[i] << ' ';

    }
    cout << endl;
    int m = 5; // A的长度
    int n = 3; // B的长度
    int k = 3; // C的长度

    deleteCommonElements(A, m, B, n, C, k);

    cout << "删除后的A: ";
    for (int i = 0; i < m; i++) 
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

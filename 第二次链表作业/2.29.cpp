#include <iostream>

using namespace std;

// ɾ��A��ͬʱ������B��C��Ԫ��
void deleteCommonElements(int A[], int& m, int B[], int n, int C[], int k) 
{
    int i = 0; // ���ڱ���A
    int j = 0; // ���ڱ���B
    int l = 0; // ���ڱ���C

    while (i < m && j < n && l < k)
    {
        if (B[j] == C[l]) 
        {
            // ���B[j]��C[l]��ȣ�˵��A[i]��B��C�ж����ڣ���A��ɾ����Ԫ��
            for (int p = i; p < m - 1; p++)
            {
                A[p] = A[p + 1];
            }
            m--; // ����A�ĳ���
        }
        else if (A[i] < B[j] && A[i] < C[l]) 
        {
            // ���A[i]С��B[j]��C[l]��˵��A[i]��������B��C�д��ڣ����������һ��AԪ��
            i++;
        }
        else if (B[j] < C[l]) 
        {
            // ���B[j]С��C[l]��˵��B[j]�����ܴ�����A�У����������һ��BԪ��
            j++;
        }
        else 
        {
            // ����C[l]�����ܴ�����A�У����������һ��CԪ��
            l++;
        }
    }
}

int main()
{
    int i;
    int A[] = { 1, 2, 3, 4, 5 };
    cout << "A��";
    for (i = 0; i < 5; i++)
    {
        cout << A[i] <<' ';
    }
    cout << endl;
    int B[] = { 3, 4, 7 };
    cout << "B��";
    for (i = 0; i < 3; i++)
    {
        cout << B[i] <<' ';
    }
    int C[] = { 2, 4, 6 };
    cout << endl;
    cout << "C��";
    for (i = 0; i < 3; i++)
    {
        
        cout << C[i] << ' ';

    }
    cout << endl;
    int m = 5; // A�ĳ���
    int n = 3; // B�ĳ���
    int k = 3; // C�ĳ���

    deleteCommonElements(A, m, B, n, C, k);

    cout << "ɾ�����A: ";
    for (int i = 0; i < m; i++) 
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

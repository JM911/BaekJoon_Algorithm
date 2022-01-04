// 11055. 가장 큰 증가 부분 수열
// S2

#include <bits/stdc++.h>
using namespace std;

int N;
int A[1010];
int sum[1010];
int maxSum;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum[i] = A[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if(A[j] > A[i])
                sum[j] = max(sum[j], sum[i] + A[j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        maxSum = max(maxSum, sum[i]);
    }

    cout << maxSum;
}
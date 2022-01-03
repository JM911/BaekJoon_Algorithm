// 1912. 연속합
// S2

#include <bits/stdc++.h>
using namespace std;

int n;
int maxSum = INT_MIN;
int tmpSum;
int sum[100010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        tmpSum += tmp;
        maxSum = max(maxSum, tmpSum);

        if(tmpSum < 0)
            tmpSum = 0;
    }

    cout << maxSum;
}
// 14225. 부분수열의 합
// S1

#include <bits/stdc++.h>
using namespace std;

int N;
int S[25];
int sum[2000000];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int totalCase = 1;

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        totalCase *= 2;
    }

    for (int i = 1; i < totalCase; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a = (i >> j) & 1;
            sum[i] += S[j] * a;
        }
    }

    sort(sum + 1, sum + totalCase);

    int idx = 1;
    int count = 1;

    while(true)
    {
        if(sum[idx] == count - 1)
        {
            idx++;
            continue;
        }

        if(sum[idx] == count)
        {
            idx++;
            count++;
            continue;
        }

        cout << count;
        return 0;
    }
}
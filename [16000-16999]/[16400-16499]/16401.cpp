// 16401. 과자 나눠주기
// S3

#include "bits/stdc++.h"
using namespace std;

int M, N;
int L[1000010];

bool Checking(int len)
{
    int sum = 0;

    for (int i = 0; i<N; i++)
        sum += L[i] / len;

    return sum >= M;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;
    for (int i = 0; i < N; i++)
        cin >> L[i];

    sort(L, L + N);

    int st = 0;
    int en = L[N - 1];

    while(st < en)
    {
        int mid = (st + en + 1) / 2;

        if(Checking(mid))
            st = mid;
        else
            en = mid - 1;
    }

    cout << st;
}
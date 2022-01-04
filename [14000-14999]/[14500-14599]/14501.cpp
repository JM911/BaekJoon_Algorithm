// 14501. 퇴사
// S3

#include <bits/stdc++.h>
using namespace std;

int N;
int T[20];
int P[20];
//int prevIdx = 0;
int maxPay, tmpPay;

void Counsel(int prevIdx)
{
    if(prevIdx + T[prevIdx] > N)
    {
        maxPay = max(maxPay, tmpPay);
        return;
    }

    for (int i = prevIdx + T[prevIdx]; i <= N; i++)
    {
        if(i + T[i] <= N+1)
            tmpPay += P[i];

        Counsel(i);

        if(i + T[i] <= N+1)
            tmpPay -= P[i];
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    T[0] = 1;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    Counsel(0);

    cout << maxPay;
}
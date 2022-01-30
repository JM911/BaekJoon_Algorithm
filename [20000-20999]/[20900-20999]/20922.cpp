// 20922. 겹치는 건 싫어
// S1

#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[200010];
int b[100010];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int leftIdx = 0;
    int rightIdx = 0;
    b[a[0]] = 1;
    ans = 1;

    while(true)
    {
        rightIdx++;

        if(rightIdx >= N)
            break;

        ++b[a[rightIdx]];

        while(b[a[rightIdx]] > K && leftIdx < rightIdx)
        {
            --b[a[leftIdx++]];
        }

        ans = max(ans, rightIdx - leftIdx + 1);
    }

    cout << ans;
}
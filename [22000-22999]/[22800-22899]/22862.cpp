// 22862. 가장 긴 짝수 연속한 부분 수열 (large)
// S1

#include <bits/stdc++.h>
using namespace std;

int N, K;
int S[1000010];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    int leftIdx = 0;
    int rightIdx = 0;
    int count = 0;

    if(S[0]%2 == 1)
        count++;

    while(rightIdx < N && leftIdx < N)
    {
        if(count <= K)
        {
            ans = max(ans, rightIdx - leftIdx + 1 - count);
            rightIdx++;

            if(S[rightIdx]%2 == 1)
                count++;
        }
        else
        {
            if(S[leftIdx]%2 == 1)
                count--;

            leftIdx++;
        }
    }

    cout << ans;
}
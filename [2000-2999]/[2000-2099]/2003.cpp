// 2003. 수들의 합 2
// S3

#include "bits/stdc++.h"
using namespace std;

int N, M;
int A[10010];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int sum = A[0];
    int leftIdx = 0;
    int rightIdx = 0;

    while(true)
    {
        if(sum == M)
        {
            ans++;
            sum -= A[leftIdx++];

            if(leftIdx >= N)
                break;
        }
        else if(sum > M)
        {
            sum -= A[leftIdx++];

            if(leftIdx >= N)
                break;
        }
        else
        {
            rightIdx++;

            if(rightIdx >= N)
                break;

            sum += A[rightIdx];
        }

        if(leftIdx > rightIdx)
        {
            rightIdx = leftIdx;
            sum = A[rightIdx];
        }
    }

    cout << ans;
}
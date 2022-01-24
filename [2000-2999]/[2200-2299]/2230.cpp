// 2230. 수 고르기
// G5

#include "bits/stdc++.h"
using namespace std;

int N, M;
int A[100010];
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

    sort(A, A + N);

    int leftIdx = 0;
    int rightIdx = 0;

    while(rightIdx < N)
    {
        if(A[rightIdx] - A[leftIdx] >= M)
        {
            ans = A[rightIdx] - A[leftIdx];
            break;
        }
        else
            rightIdx++;
    }

    int ans = A[rightIdx] - A[leftIdx];

    while(true)
    {
        if(A[rightIdx] - A[leftIdx] >= M)
        {
            ans = min(ans, A[rightIdx] - A[leftIdx]);
            leftIdx++;
        }
        
        else
        {
            rightIdx++;
            if(rightIdx >= N)
                break;
        }
    }

    cout << ans;
}
// 1806. 부분합
// G4

#include "bits/stdc++.h"
using namespace std;

int N, S;
int arr[100010];
int ans = 100020;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int sum = arr[0];
    int leftIdx = 0;
    int rightIdx = 0;

    while(rightIdx < N)
    {
        if(sum >= S)
        {
            ans = min(ans, rightIdx - leftIdx + 1);
            sum -= arr[leftIdx];
            leftIdx++;

            if(leftIdx > rightIdx)
            {
                break;
                // rightIdx = leftIdx;
                // sum = arr[rightIdx];
            }
        }

        else
        {
            rightIdx++;
            sum += arr[rightIdx];
        }
    }

    if(ans == 100020)
        cout << 0;
    else
        cout << ans;
}
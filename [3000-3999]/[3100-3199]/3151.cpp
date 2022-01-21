// 3151. 합이 0
// G4

#include "bits/stdc++.h"
using namespace std;

#define N_MAX      10010      //10010         100

int N;
int A[N_MAX];
int minusA[N_MAX];
long long ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A, A + N, greater<int>());

    for (int i = 0; i < N; i++)
    {
        minusA[i] = -A[i];
    }

    for (int i = 0; i < N-1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int tmp = A[i] + A[j];
            ans += upper_bound(minusA + j + 1, minusA + N, tmp) - lower_bound(minusA + j + 1, minusA + N, tmp);
        }
    }

    cout << ans;
}
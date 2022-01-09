// 1026. 보물
// S4

#include <bits/stdc++.h>
using namespace std;

int N, ans;
int A[55];
int B[55];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N, greater<int>());

    for (int i = 0; i < N; i++)
    {
        ans += A[i] * B[i];
    }

    cout << ans;
}  
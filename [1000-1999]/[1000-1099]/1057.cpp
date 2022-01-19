// 1057. 토너먼트
// S3

#include <bits/stdc++.h>
using namespace std;

int N, A, B;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> A >> B;

    if(A>B)
        swap(A, B);

    int ans = 1;

    while(true)
    {
        if(B-A == 1 && A%2 == 1)
            break;

        A = (A + 1) / 2;
        B = (B + 1) / 2;
        ans++;
    }

    cout << ans;
}
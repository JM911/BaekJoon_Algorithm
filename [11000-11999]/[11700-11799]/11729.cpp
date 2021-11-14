// 11729. 하노이 탑 이동 순서
// S2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int GetHanoiNum(int n)
{
    if(n==1)
        return 1;

    return GetHanoiNum(n - 1) * 2 + 1;
}

void MoveHanoi(int n, int fromNum, int toNum)
{
    if(n==1)
    {
        cout << fromNum << ' ' << toNum << '\n';
        return;
    }

    int mid = 6 - (fromNum + toNum);

    MoveHanoi(n - 1, fromNum, mid);
    cout << fromNum << ' ' << toNum << '\n';
    MoveHanoi(n - 1, mid, toNum);
}

int main()
{
    fastio;
    int N;
    cin >> N;

    cout << GetHanoiNum(N) << '\n';
    MoveHanoi(N, 1, 3);
}

// 1931. 회의실 배정
// S2

#include <bits/stdc++.h>
using namespace std;

#define IDX_MAX 100010

int N;
pair<int, int> meeting[IDX_MAX];
int ans;
int curTime;

bool compare_tmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting + 1, meeting + N + 1, compare_tmp);

    for (int i = 1; i<=N; i++)
    {
        if(meeting[i].first < curTime)
            continue;

        ans++;
        curTime = meeting[i].second;
    }

    cout << ans;
}  
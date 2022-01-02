// 2579. 계단 오르기
// S3

#include <bits/stdc++.h>
using namespace std;

int N;
int stairScore[310];
int totalScoreMax[310];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> stairScore[i];
    }

    totalScoreMax[0] = stairScore[0];
    totalScoreMax[1] = stairScore[0] + stairScore[1];
    totalScoreMax[2] = max(stairScore[0], stairScore[1]) + stairScore[2];

    for (int i = 3; i < N; i++)
    {
        totalScoreMax[i] = max(totalScoreMax[i - 2], totalScoreMax[i - 3] + stairScore[i - 1]) + stairScore[i];
    }

    cout << totalScoreMax[N - 1];
}
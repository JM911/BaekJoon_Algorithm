// 1182. 부분수열의 합
// S2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[25];
int N, S, ans;
int subArr[25];
bool isVisited[25];

void FindS(int len, int lastIdx)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += subArr[i];

    if (len > 0 && sum == S)
    {
        ans++;
    }

    if(len == N)
    {
        return;
    }

    for (int i = lastIdx; i < N; i++)
    {
        if(isVisited[i] == false)
        {
            subArr[len] = arr[i];
            isVisited[i] = true;
            FindS(len + 1, i);
            isVisited[i] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];  // 0 ~ 19
    }

    FindS(0, 0);

    cout << ans;
}

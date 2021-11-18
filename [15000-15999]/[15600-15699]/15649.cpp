// 15649. N과 M (1)
// S3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
int arr[9];
bool isVisited[9];

void Ans(int len)
{
    if(len == M)
    {
        for (int i = 1; i <= M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if(isVisited[i] == false)
        {
            arr[len + 1] = i;
            isVisited[i] = true;
            Ans(len + 1);
            isVisited[i] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> N >> M;

    Ans(0);
}

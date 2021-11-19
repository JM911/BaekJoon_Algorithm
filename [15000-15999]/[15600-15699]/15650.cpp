// 15650. N과 M (2)
// S3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M, prevNum;
int arr[10];
bool isVisited[10];

void PickNums(int len)
{
    if(len == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = prevNum + 1; i <= N; i++)
    {
        if(isVisited[i] == false)
        {
            arr[len] = i;
            isVisited[i] = true;
            prevNum = i;
            PickNums(len + 1);
            isVisited[i] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> N >> M;

    PickNums(0);
}

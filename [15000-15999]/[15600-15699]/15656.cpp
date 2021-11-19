// 15656. N과 M (7)
// S3
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
//int prevIdx;
int nums[10];
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

    for (int i = 0; i < N; i++)
    {
        //if(isVisited[i] == false)
        {
            arr[len] = nums[i];
            //isVisited[i] = true;
            //prevIdx = i;
            PickNums(len + 1);
            //isVisited[i] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    PickNums(0);

    return 0;
}

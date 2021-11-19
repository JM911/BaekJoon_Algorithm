// 15663. N과 M (9)
// S2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
int prevNum;
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
        if(isVisited[i] == false)
        {
            if(prevNum == nums[i])
                continue;
            arr[len] = nums[i];

            isVisited[i] = true;
            prevNum = 0;
            PickNums(len + 1);
            
            isVisited[i] = false;
            prevNum = nums[i];
        }
    }
}

int main()
{
    fastio;
    cin >> N >> M;
    //fill(nums, nums + 10, 10001);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    PickNums(0);

    return 0;
}

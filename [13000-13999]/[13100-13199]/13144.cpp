// 13144. List of Unique Numbers
// G3

#include "bits/stdc++.h"
using namespace std;

int N;
int arr[100010];
bool isVisited[100010];
long long ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int leftIdx = 0;
    int rightIdx = 0;

    while(rightIdx < N)
    {
        if(isVisited[arr[rightIdx]] == false)
        {
            isVisited[arr[rightIdx]] = true;
            ans += rightIdx - leftIdx + 1;
            rightIdx++;
        }
        else
        {
            isVisited[arr[leftIdx]] = false;
            leftIdx++;
        }
    }

    cout << ans;
}
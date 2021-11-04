// 2606. 바이러스
// S3

#include <bits/stdc++.h>
#define fastio cin.tie(nullptr); ios::sync_with_stdio(false)
using namespace std;

bool isVisited[101];
list<int> larr[101];
int ans;

bool Visit(int visitV)
{
    if(isVisited[visitV] == false)
    {
        isVisited[visitV] = true;
        return true;
    }

    return false;
}

void DFSForIdx(int idx)
{
    while(!larr[idx].empty())
    {
        if(Visit(larr[idx].front()))
        {
            DFSForIdx(larr[idx].front());
            ans++;
        }
        larr[idx].pop_front();
    }
}

int main()
{
    fastio;
    int N, M;
    cin >> N >> M;

    while(M--)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        larr[temp1].push_back(temp2);
        larr[temp2].push_back(temp1);
    }

    isVisited[1] = true;
    DFSForIdx(1);

    cout << ans;
}
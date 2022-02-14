// 1043. 거짓말
// G4

#include <bits/stdc++.h>
using namespace std;

int N, M, truthNum;
int manStatus[55];
bool partyMem[55][55];
bool vis[55];
queue<int> truthIdx;

int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    cin >> truthNum;

    for (int i = 0; i < truthNum; i++)
    {
        int tmp;
        cin >> tmp;
        manStatus[tmp] = true;
        truthIdx.push(tmp);
    }

    for (int i = 0; i < M; i++)
    {
        int tmpNum;
        cin >> tmpNum;

        while(tmpNum--)
        {
            int tmp;
            cin >> tmp;
            partyMem[i][tmp] = true;
        }
    }

    while(!truthIdx.empty())
    {
        int curIdx = truthIdx.front();
        truthIdx.pop();

        if(vis[curIdx] == true)
            continue;
        vis[curIdx] = true;

        for (int i = 0; i < M; i++)
        {
            if(partyMem[i][curIdx] == false)
                continue;

            for (int j = 1; j <= N; j++)
            {
                if(partyMem[i][j] == false)
                    continue;
                
                if(vis[j] == true)
                    continue;

                manStatus[j] = true;
                truthIdx.push(j);
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        bool check = false;

        for (int j = 1; j <= N; j++)
        {
            if(partyMem[i][j] == true && manStatus[j] == true)
            {
                check = true;
                break;
            }
        }

        if(check == false)
            ans++;
    }

    cout << ans;
}
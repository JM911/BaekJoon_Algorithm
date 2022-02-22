// 14267. 회사 문화 1
// G4

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ch[100010];
int p[100010];
int point[100010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int tmpP;
        cin >> tmpP;
        p[i] = tmpP;

        if(tmpP < 0)
            continue;

        ch[tmpP].push_back(i);
    }

    while(m--)
    {
        int targetNum, targetPoint;
        cin >> targetNum >> targetPoint;

        point[targetNum] += targetPoint;
    }

    for (int i = 1; i <= n; i++)
    {
        for(auto t : ch[i])
        {
            point[t] += point[i];
        }

        cout << point[i] << ' ';
    }
}
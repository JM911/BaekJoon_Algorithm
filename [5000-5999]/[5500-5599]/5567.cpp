// 5567. 결혼식
// S2

#include <bits/stdc++.h>
using namespace std;

int n, m;
bool fr[510][510];
bool vis[510];
int ans;

void MyDFS(int v, int len)
{
    if(len > 2)
        return;

    if(vis[v] == false)
        ans++;
        
    vis[v] = true;

    for (int i = 1; i <= n; i++)
    {
        if(fr[v][i] == true)
            MyDFS(i, len + 1);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        fr[a][b] = true;
        fr[b][a] = true;
    }

    MyDFS(1, 0);

    cout << ans - 1;
}
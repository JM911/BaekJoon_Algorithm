#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool paint[501][501];
bool isVisited[501][501];

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> paint[i][j];
        }
    }

    queue<pair<int, int>> q;
    int ans = 0;
    int max = 0;
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(paint[i][j] == true && isVisited[i][j] == false)
            {
                ans++;
                if(i-1>0 && paint[i-1][j] == true && isVisited[i-1][j] == false)
                    q.push(make_pair(i - 1, j));

                
                while(!q.empty())
                {
                    
                }
            }
        }
    }
}
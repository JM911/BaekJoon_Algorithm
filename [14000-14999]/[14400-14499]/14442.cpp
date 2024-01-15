// 14442. 벽 부수고 이동하기 2
// G3

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int N, M, K;
bool wallMap[1010][1010];
int distMap[1010][1010][12];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	setIO("");
	fill(&distMap[0][0][0], &distMap[1001][1001][12], -1);

	cin >> N >> M >> K;
	for(int i=0; i<N; i++)
	{
		string s;
		cin >> s;
		for(int j=0; j<M; j++)
			wallMap[i][j] = s[j] == '1' ? true : false;
	}

	queue<tuple<int, int, int>> q;
	distMap[0][0][0] = 0;
	q.push({0, 0, 0});

	while(!q.empty())
	{
		tuple<int, int, int> curPos = q.front();
		int curX = get<0>(curPos);
		int curY = get<1>(curPos);
		int curZ = get<2>(curPos);
		q.pop();

		for(int l=0; l<4; l++)
		{
			int x = curX + dx[l];
			int y = curY + dy[l];

			if(x<0 || x>=N || y<0 || y>=M) continue;
			
			if(wallMap[x][y])
			{
				if(curZ >= K) continue;
				if(distMap[x][y][curZ+1] < 0 || distMap[x][y][curZ+1] > distMap[curX][curY][curZ] + 1)
				{
					distMap[x][y][curZ+1] = distMap[curX][curY][curZ] + 1;
					q.push({x, y, curZ+1});
				}
			}
			else
			{
				if(distMap[x][y][curZ] < 0 || distMap[x][y][curZ] > distMap[curX][curY][curZ] + 1)
				{
					distMap[x][y][curZ] = distMap[curX][curY][curZ] + 1;
					q.push({x, y, curZ});
				}
			}
		}
	}
	
	int ans = INT_MAX;
	for(int i=0; i<=K; i++)
	{
		if(distMap[N-1][M-1][i] < 0) continue;

		ans = min(ans, distMap[N-1][M-1][i]);
	}

	if(ans == INT_MAX)
		cout << -1;
	else
		cout << ans+1;
}
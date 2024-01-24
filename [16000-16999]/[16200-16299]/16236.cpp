// 16236. 아기 상어
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

int N, M;
int board[25][25];

int sharkSize = 2;
int sharkExp;
pair<int, int> sharkPos;
int dist[25][25];
int ans;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void MyBFS()
{
	//fill(&dist[0][0], &dist[24][25], -1);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(board[i][j] > sharkSize)
				dist[i][j] = -2;
			else
				dist[i][j] = -1;
		}
	}

	dist[sharkPos.first][sharkPos.second] = 0;
	queue<pair<int, int>> q;
	q.push(sharkPos);

	while(!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for(int dir=0; dir<4; dir++)
		{
			int x = curX + dx[dir];
			int y = curY + dy[dir];
			if(x<0 || y<0 || x>=N || y>=N) continue;
			if(dist[x][y] >= 0 || dist[x][y] <= -2) continue;

			dist[x][y] = dist[curX][curY] + 1;
			q.push({x, y});
		}
	}
}

pair<int, int> GetNextFishPos()
{
	pair<int, int> fishPos{-1, -1};
	int minDist = 0x7f7f7f7f;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			int curFishSize = board[i][j];
			if(curFishSize<=0 || curFishSize>=7) continue;
			if(curFishSize >= sharkSize || dist[i][j] < 0) continue;
			if(dist[i][j] < minDist)
			{
				minDist = dist[i][j];
				fishPos = {i, j};
			}
		}
	}

	return fishPos;
}

void PrintBoard()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main()
{
	//setIO("");

	cin >> N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 9)
			{
				sharkPos = {i, j};
				board[i][j] = 0;
			}
		}
	}

	while(true)
	{
		MyBFS();
		pair<int, int> fishPos = GetNextFishPos();

		if(fishPos.first < 0) break;

		ans += dist[fishPos.first][fishPos.second];
		board[fishPos.first][fishPos.second] = 0;
		sharkPos = fishPos;
		
		sharkExp++;
		if(sharkExp >= sharkSize)
		{
			sharkSize++;
			sharkExp = 0;
		}

		// PrintBoard();
		int a = 0;
	}

	cout << ans;
}
// 16920. 확장 게임
// G2

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

int N, M, P;
int S[11];
int board[1010][1010];
int ans[11];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	setIO("");

	cin >> N >> M >> P;
	for(int i=1; i<=P; i++)
	{
		cin >> S[i];
	}

	queue<pair<int, int>> q[11];
	for(int i=0; i<N; i++)
	{
		string tmp;
		cin >> tmp;
		for(int j=0; j<M; j++)
		{
			if(tmp[j] == '#') board[i][j] = -1;
			else if(tmp[j] != '.')
			{
				int curP = tmp[j] - '0';
				board[i][j] = curP;
				q[curP].push({i, j});
			}
		}
	}

	while(true)
	{
		bool bStop = true;
		for(int i=1; i<=P; i++)
			if(!q[i].empty()) bStop = false;
		if(bStop) break;

		for(int i=1; i<=P; i++)
		{
			if(q[i].empty()) continue;
			int T1 = S[i];

			while(T1--)
			{
				if(q[i].empty()) break;
				int T2 = q[i].size();

				while(T2--)
				{
					if(q[i].empty()) break;

					int curX = q[i].front().first;
					int curY = q[i].front().second;
					q[i].pop();

					for(int d=0; d<4; d++)
					{
						int x = curX + dx[d];
						int y = curY + dy[d];

						if(x<0 || x>=N || y<0 || y>=M) continue;
						if(board[x][y] != 0) continue;

						board[x][y] = i;
						q[i].push({x, y});
					}
				}
			}
		}
	}


	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(board[i][j] > 0 && board[i][j] <= P)
				ans[board[i][j]]++;
		}
	}

	for(int i=1; i<=P; i++)
	{
		cout << ans[i] << ' ';
	}
}
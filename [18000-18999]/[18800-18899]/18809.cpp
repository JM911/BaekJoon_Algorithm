// 18809. Gaaaaaaaaaarden
// G1

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

int N, M, G, R;
int ground[55][55];

vector<pair<int, int>> canGround;
int ans;

vector<pair<int, int>> selectedGround;
queue<pair<int, int>> qG;
queue<pair<int, int>> qR;
int day[55][55];
int myBoard[55][55];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Solve()
{
	int curDay = 1;
	int curAns = 0;

	while(!qG.empty() && !qR.empty())	// 둘 중 하나라도 비면 종료
	{
		int TG = qG.size();
		while(TG--)
		{
			int curX = qG.front().first;
			int curY = qG.front().second;
			qG.pop();

			if(myBoard[curX][curY] != 3) continue;

			for(int d=0; d<4; d++)
			{
				int x = curX + dx[d];
				int y = curY + dy[d];
				if(x<0 || y<0 || x>=N || y>=M) continue;
				if(myBoard[x][y] == 1 || myBoard[x][y] == 2)
				{
					myBoard[x][y] = 3;
					day[x][y] = curDay;
					qG.push({x, y});
				}
			}
		}

		int TR = qR.size();
		while(TR--)
		{
			int curX = qR.front().first;
			int curY = qR.front().second;
			qR.pop();

			for(int d=0; d<4; d++)
			{
				int x = curX + dx[d];
				int y = curY + dy[d];
				if(x<0 || y<0 || x>=N || y>=M) continue;

				if(myBoard[x][y] == 3 && day[x][y] == curDay)
				{
					myBoard[x][y] = 5;
					curAns++;
				}

				if(myBoard[x][y] == 1 || myBoard[x][y] == 2)
				{
					myBoard[x][y] = 4;
					day[x][y] = curDay;
					qR.push({x, y});
				}
			}
		}


		curDay++;
	}

	//ans = max(ans, curAns);
	if(curAns > ans)
	{
		ans = curAns;
	}
}

int main()
{
	setIO("");

	cin >> N >> M >> G >> R;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> ground[i][j];
			if(ground[i][j] == 2)
				canGround.push_back({i, j});
		}
	}

	int a[11];
	fill(a, a+11, 1);
	for(int i=0; i<G+R; i++)
	{
		a[i] = 0;
	}

	do
	{
		selectedGround.clear();
		for(int i=0; i<canGround.size(); i++)
		{
			if(a[i] == 0)
				selectedGround.push_back(canGround[i]);
		}

		int b[11];
		fill(b, b+11, 1);
		for(int i=0; i<G; i++)
		{
			b[i] = 0;
		}

		do
		{
			for(int i=0; i<N; i++)
			{
				for(int j=0; j<M; j++)
				{
					myBoard[i][j] = ground[i][j];
					day[i][j] = 0;
				}
			}

			while(!qG.empty()) qG.pop();
			while(!qR.empty()) qR.pop();

			for(int i=0; i<G+R; i++)
			{
				if(b[i] == 0)
				{
					myBoard[selectedGround[i].first][selectedGround[i].second] = 3;
					qG.push(selectedGround[i]);
				}
				else
				{
					myBoard[selectedGround[i].first][selectedGround[i].second] = 4;
					qR.push(selectedGround[i]);
				}
			}

			Solve();
		} while (next_permutation(b, b+G+R));
		
	} while (next_permutation(a, a+canGround.size()));
	
	cout << ans;
}
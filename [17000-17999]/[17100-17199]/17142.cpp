// 17142. 연구소 3
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
int lab[55][55];
int curLab[55][55];

int ans = 0x7f7f7f7f;
vector<pair<int, int>> v;
vector<pair<int, int>> curV;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DebugPrint()
{
	cout << '\n';
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout << curLab[i][j] << ' ';
		}
		cout << '\n';
	}
}

int GetTotalTime()
{
	queue<pair<int, int>> q;
	int t = 0;
	int blankNum = 0;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			switch(lab[i][j])
			{
			case 1:
				curLab[i][j] = 1;
				break;
			case 2:
				curLab[i][j] = 2;
				break;
			default:
				curLab[i][j] = 0;
				blankNum++;
				break;
			}
		}
	}

	for(auto a : curV)
	{
		curLab[a.first][a.second] = 3;
		q.push(a);
	}

	while(!q.empty())
	{
		int qSize = q.size();
		bool bTime = false;
		bool bAwake = false;

		for(int i=0; i<qSize; i++)
		{
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();

			for(int dir=0; dir<4; dir++)
			{
				int x = curX + dx[dir];
				int y = curY + dy[dir];

				if(x<0 || y<0 || x>=N || y>=N) continue;
				if(curLab[x][y] == 0)
				{
					curLab[x][y] = 3;
					q.push({x, y});
					bTime = true;
					blankNum--;
				}
				else if(curLab[x][y] == 2)
				{
					curLab[x][y] = 3;
					q.push({x, y});
					bAwake = true;
				}
			}
		}

		if(bTime)
		{
			t++;
			//DebugPrint();
		}
		else if(bAwake && blankNum > 0)
		{
			t++;
		}
	}

	if(blankNum <= 0)
		return t;
	else
		return -1;

	// for(int i=0; i<N; i++)
	// {
	// 	for(int j=0; j<N; j++)
	// 	{
	// 		if(curLab[i][j] == 0)
	// 			return -1;
	// 	}
	// }

	// return t;
}

int main()
{
	setIO("");

	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> lab[i][j];
			if(lab[i][j] == 2)
				v.push_back({i, j});
		}
	}

	int a[12];
	int vSize = v.size();
	fill(a+M, a+vSize, 1);
	fill(a, a+M, 0);

	do
	{
		curV.clear();

		for(int i=0; i<vSize; i++)
		{
			if(a[i]==0) curV.push_back(v[i]);
		}

		int curTotalTime = GetTotalTime();
		if(curTotalTime < 0) continue;
		ans = min(ans, curTotalTime);
	} while (next_permutation(a, a+vSize));
	
	if(ans == 0x7f7f7f7f)
		cout << -1;
	else
		cout << ans;
}
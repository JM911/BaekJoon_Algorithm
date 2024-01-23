// 16235. 나무 재테크
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

using pq = priority_queue<int, vector<int>, greater<int>>;

int N, M, K;
int nut[15][15];
int A[15][15];

vector<int> tree[15][15];
int dt[15][15];
int at[15][15];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Spring()
{
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			sort(tree[i][j].begin(), tree[i][j].end());
			vector<int> tmpTree;
			tmpTree.reserve(100);

			int lastIdx = tree[i][j].size();
			for(int k=0; k<tree[i][j].size(); k++)
			{
				int t = tree[i][j][k];
				if(nut[i][j] >= t)
				{
					nut[i][j] -= t;
					tmpTree.push_back(t+1);
				}
				else
				{
					lastIdx = k;
					break;
				}
			}
			for(int k=lastIdx; k<tree[i][j].size(); k++)
			{
				dt[i][j] += (tree[i][j][k]/2);
			}

			tree[i][j].clear();
			for(auto t : tmpTree)
			{
				tree[i][j].push_back(t);
			}
		}
	}
}

void Summer()
{
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			nut[i][j] += dt[i][j];
			dt[i][j] = 0;
		}
	}
}

void Fall()
{
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			// tmpPq = tree[i][j];
			for(auto t : tree[i][j])
			{
				if(t%5 != 0) continue;				
				
				for(int dir=0; dir<8; dir++)
				{
					int x = i+dx[dir];
					int y = j+dy[dir];

					if(x<=0 || y<=0 || x>N || y>N) continue;

					at[x][y]++;
				}
			}
		}
	}

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			while(at[i][j]>0)
			{
				tree[i][j].push_back(1);
				at[i][j]--;
			}
		}
	}
}

void Winter()
{
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			nut[i][j] += A[i][j];
		}
	}
}

// void DebugPrint()
// {
// 	for(int i=1; i<=N; i++)
// 	{
// 		for(int j=1; j<=N; j++)
// 	}
// }

int main()
{
	setIO("");

	// init
	fill(&nut[0][0], &nut[12][13], 5);

	cin >> N >> M >> K;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cin >> A[i][j];
		}
	}
	for(int i=0; i<M; i++)
	{
		int tmpX, tmpY, tmpAge;
		cin >> tmpX >> tmpY >> tmpAge;
		
		tree[tmpX][tmpY].push_back(tmpAge);
	}

	

	while(K--)
	{
		Spring();
		Summer();
		Fall();
		Winter();

		// if(K<=1)
		// {
		// 	DebugPrint();
		// }
	}

	int totalTree = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			totalTree += tree[i][j].size();
		}
	}
	cout << totalTree;
}
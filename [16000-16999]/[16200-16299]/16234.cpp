// 16234. 인구 이동
// G4

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

int N, L, R;
int A[55][55];

int ans;
bool bVisit[55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	setIO("");

	cin >> N >> L >> R;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> A[i][j];
		}
	}

	while(true)
	{
		bool bStop = true;

		fill(&bVisit[0][0], &bVisit[54][55], false);
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(bVisit[i][j]) continue;

				queue<pair<int, int>> q;
				q.push({i, j});
				bVisit[i][j] = true;
				
				vector<pair<int, int>> unite;
				unite.push_back({i, j});

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
						if(bVisit[x][y] == true) continue;
						
						if(abs(A[x][y] - A[curX][curY]) >= L && abs(A[x][y] - A[curX][curY]) <= R)
						{
							bStop = false;
							unite.push_back({x, y});

							q.push({x, y});
							bVisit[x][y] = true;
						}
					}
				}

				if(unite.size() > 1)
				{
					int sum = 0;
					for(auto u : unite)
					{
						sum += A[u.first][u.second];
					}

					int avg = sum/unite.size();
					for(auto u : unite)
					{
						A[u.first][u.second] = avg;
					}
				}
			}
		}

		if(bStop) break;
		else ans++;
	}

	cout << ans;
}
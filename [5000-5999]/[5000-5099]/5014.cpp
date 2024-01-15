// 5014. 스타트링크
// S1

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

int F, S, G, U, D;
int dist[1000010];
int ud[2];

int main()
{
	setIO("");

	cin >> F >> S >> G >> U >> D;

	ud[0] = U;
	ud[1] = -D;
	fill(dist, dist+F+1, -1);

	queue<int> q;
	dist[S] = 0;
	q.push(S);

	while(!q.empty())
	{
		int curX = q.front();
		q.pop();

		for(int k=0; k<2; k++)
		{
			int x = curX + ud[k];

			if(x<=0 || x>F) continue;
			if(dist[x] >= 0) continue;

			dist[x] = dist[curX] + 1;
			q.push(x);
		}
	}

	if(dist[G] >= 0)
		cout << dist[G];
	else
		cout << "use the stairs";
}
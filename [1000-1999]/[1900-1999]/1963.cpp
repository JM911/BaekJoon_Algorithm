// 1963. 소수 경로
// G4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int T, a, b;
vector<bool> p;
//bool pa[10][10][10][10];
vector<int> adj[10010];
int dist[10010];

void Init()
{
	p.resize(10010, true);
	p[0] = false;
	p[1] = false;
	for(int i=2; i*i<=10000; i++)
	{
		if(!p[i]) continue;
		for(int j=2; i*j<=10000; j++)
			p[i*j] = false;
	}

	// for(int i1=0; i1<=9; i1++)
	// {
	// 	for(int i2=0; i2<=9; i2++)
	// 	{
	// 		for(int i3=0; i3<=9; i3++)
	// 		{
	// 			for(int i4=0; i4<=9; i4++)
	// 			{
	// 				pa[i1][i2][i3][i4] = p[i1*1000 + i2*100 + i3*10 + i4];
	// 			}
	// 		}
	// 	}
	// }

	for(int i=1000; i<=9999; i++)
	{
		if(!p[i]) continue;

		for(int j=1; j<=1000; j*=10)
		{
			int curNum = i;
			curNum -= (curNum/j) % 10 * j;
			
			for(int k=0; k<=9; k++)
			{
				int targetNum = curNum + k * j;
				if(targetNum<1000 || k==i) continue;
				if(p[targetNum]) 
				{
					adj[i].push_back(targetNum);
				}
			}
		}
	}
}

int main()
{
	FASTIO;

	Init();	

	cin >> T;
	while(T--)
	{
		cin >> a >> b;

		fill(dist, dist+10005, -1);
		dist[a] = 0;

		queue<int> q;
		q.push(a);
		bool bAns = false;

		while(!q.empty())
		{
			int cur = q.front();
			q.pop();

			for(auto it : adj[cur])
			{
				if(dist[it] == -1)
				{
					dist[it] = dist[cur] + 1;
					q.push(it);
					if(it == b)
					{
						bAns = true;
						break;
					}
				}
			}

			if(bAns) break;
		}
		
		int ans = dist[b];
		if(ans < 0)
			cout << "Impossible" << '\n';
		else
			cout << ans << '\n';
	}
}
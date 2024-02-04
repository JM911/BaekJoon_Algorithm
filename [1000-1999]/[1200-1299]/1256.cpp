// 1256. 사전
// G2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

#define MAX_NUM 1000000010
int d[210][210];
int N, M, K;

int main()
{
	FASTIO;

	d[1][0] = 1;
	d[1][1] = 1;
	
	for(int n=2; n<=200; n++)
	{
		for(int k=0; k<=n; k++)
		{
			if(k==n || k==0)
			{
				d[n][k] = 1;
			}
			else
			{
				d[n][k] = d[n-1][k] + d[n-1][k-1];
				if(d[n][k] > MAX_NUM)
					d[n][k] = MAX_NUM;
			}
		}
	}

	cin >> N >> M >> K;
	vector<char> ans;

	if(K > d[N+M][N])
	{
		cout << -1;
		return 0;
	}

	int remainA = N;
	int remainZ = M;
	while(remainA>0 && remainZ>0)
	{
		if(K > d[remainA+remainZ-1][remainZ])
		{
			K -= d[remainA+remainZ-1][remainZ];
			ans.push_back('z');
			remainZ--;
		}
		else
		{
			ans.push_back('a');
			remainA--;
		}
	}
	while(remainA-- > 0)
	{
		ans.push_back('a');
	}
	while(remainZ-- > 0)
	{
		ans.push_back('z');
	}

	for(auto a : ans)
		cout << a;
}
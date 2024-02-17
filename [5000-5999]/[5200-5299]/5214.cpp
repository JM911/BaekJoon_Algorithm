// 5214. 환승
// G2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, K, M;
vector<int> itoh[100010];
vector<int> htoi[1010];
int distI[100010];
int distH[1010];

int main()
{
	FASTIO;

	cin >> N >> K >> M;
	for(int h=0; h<M; h++)
	{
		int cnt = K;
		while(cnt--)
		{
			int i;
			cin >> i;

			itoh[i].push_back(h);
			htoi[h].push_back(i);
		}
	}

	queue<int> qi;
	queue<int> qh;
	qi.push(1);
	distI[1] = 1;

	while(!qi.empty())
	{
		int sizeI = qi.size();

		while(sizeI--)
		{
			int curI = qi.front();
			qi.pop();

			for(auto h : itoh[curI])
			{
				if(distH[h] > 0) continue;
				distH[h] = distI[curI] + 1;
				qh.push(h);
			}
		}

		int sizeH = qh.size();

		while(sizeH--)
		{
			int curH = qh.front();
			qh.pop();

			for(auto i : htoi[curH])
			{
				if(distI[i] > 0) continue;
				distI[i] = distH[curH];
				qi.push(i);
			}
		}
	}

	if(distI[N] > 0)
		cout << distI[N];
	else
		cout << -1;
}
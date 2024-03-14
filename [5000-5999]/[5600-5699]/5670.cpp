// 5670. 휴대폰 자판
// P4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int ROOT = 0;
const int MX = 1'000'000 + 10;
const int VAR = 26;

int unused = 1;
// int nxt[MX][VAR];
vector<pair<char, int>> nxt[MX];
bool chk[MX];

int totalTypeCount = 0;

int c2i(char c)
{
	return c - 'a';
}

void Init()
{
	// fill(&nxt[0][0], &nxt[MX-1][VAR], -1);
	for(int i=0; i<MX; i++)
		nxt[i].clear();
	totalTypeCount = 0;
}

void Insert(const string& s)
{
	int cur = ROOT;
	for(auto c : s)
	{
		// int i = c2i(c);
		// if(nxt[cur][i] < 0)
		// 	nxt[cur][i] = unused++;
		int idx = -1;
		for(int i=0; i<nxt[cur].size(); i++)
		{
			auto elem = nxt[cur][i];
			if(elem.first == c)
			{
				idx = i;
				break;
			}
		}
		if(idx < 0)
		{
			nxt[cur].push_back({c, unused++});
			idx = nxt[cur].size() - 1;
		}

		cur = nxt[cur][idx].second;
	}

	chk[cur] = true;
}

void DFS(int cur, int curTypeCount)
{
	if(chk[cur])
		totalTypeCount += curTypeCount;

	bool bTyped = (cur==0);
	int cnt = (chk[cur] ? 1 : 0);
	// for(int i=0; i<VAR; i++)
	// 	if(nxt[cur][i] >= 0) cnt++;
	for(auto elem : nxt[cur])
		cnt++;
	if(cnt >= 2) bTyped = true;

	int nxtTypeCount = curTypeCount;
	if(bTyped) nxtTypeCount++;

	// for(int i=0; i<VAR; i++)
	// {
	// 	if(nxt[cur][i] >= 0)
	// 		DFS(nxt[cur][i], nxtTypeCount);
	// }
	for(auto elem : nxt[cur])
		DFS(elem.second, nxtTypeCount);
}

void Solve()
{
	while(true) 
	{
		Init();

		int N;
		cin >> N;
		if (cin.eof() == 1) break;
		
		int cnt = N;
		while(cnt--)
		{
			string s;
			cin >> s;
			Insert(s);
		}

		DFS(0, 0);
		float ans = (float)totalTypeCount / (float)N;
		
		cout.precision(2);
		cout << fixed << ans << '\n';
	}
}

int main()
{
	FASTIO;

	Solve();
}
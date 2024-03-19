// 5446. 용량 부족
// P3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int ROOT = 0;
const int MX = 2'000 * 20 + 10;
const int VAR = 26 + 26 + 10 + 1;

int unused = 1;
int nxt[MX][VAR];
bool chk[MX];
bool noRemove[MX];
bool noRemoveChk[MX];

int c2i(char c)
{
	if(c>='a' && c<='z') 
		return c-'a';
	if(c>='A' && c<='Z')
		return c-'A'+26;
	if(c>='0' && c<= '9')
		return c-'0'+52;
	return 62;
}

void Insert(const string& s)
{
	int cur = ROOT;
	for(auto c : s)
	{
		int i = c2i(c);
		if(nxt[cur][i] < 0)
			nxt[cur][i] = unused++;
		cur = nxt[cur][i];
	}
	chk[cur] = true;
}

void AddNoRemove(const string& s)
{
	int cur = ROOT;
	for(auto c : s)
	{
		int i = c2i(c);
		if(nxt[cur][i] < 0)
			return;
		cur = nxt[cur][i];
		noRemove[cur] = true;
	}
	noRemoveChk[cur] = true;
}

int ans;

void DFS(int curIdx)
{
	if(!noRemove[curIdx])
	{
		ans++;
		return;
	}

	if(chk[curIdx] && !noRemoveChk[curIdx])
		ans++;

	for(int i=0; i<VAR; i++)
	{
		int nxtIdx = nxt[curIdx][i];
		if(nxtIdx < 0) continue;

		DFS(nxtIdx);
	}
}

int main()
{
	FASTIO;


	int T;
	cin >> T;

	while(T--)
	{
		fill(&nxt[0][0], &nxt[MX-1][VAR], -1);
		for(int i=0; i<MX; i++)
		{
			chk[i] = false;
			noRemove[i] = false;
			noRemoveChk[i] = false;
		}
		unused = 1;
		ans = 0;

		int N1, N2;
		cin >> N1;
		while(N1--)
		{
			string s;
			cin >> s;
			Insert(s);
		}

		cin >> N2;
		while(N2--)
		{
			string s;
			cin >> s;
			AddNoRemove(s);
			noRemove[0] = true;
		}

		DFS(0);
		cout << ans << '\n';
	}
}
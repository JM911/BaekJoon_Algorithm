// 14725. 개미굴
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int ROOT = 0;
const int MX = 15 * 15 * 1000 + 5;
const int VAR = 27;
const int SLASH = 0;

int unused = 1;
int nxt[MX][VAR];
//bool chk[MX];

int c2i(char c)
{
	if(c == '/') return SLASH;
	return c - 'A' + 1;
}

char i2c(int i)
{
	if(i == SLASH) return '/';
	return i + 'A' - 1;
}

void Insert(string s)
{
	int cur = ROOT;
	for(auto c : s)
	{
		int i = c2i(c);
		if(nxt[cur][i] < 0)
			nxt[cur][i] = unused++;
		cur = nxt[cur][i];
	}
	//chk[cur] = true;
}

void DFS(int curIdx, string curS, int curDepth)
{
	for(int k=0; k<VAR; k++)
	{
		int nxtDepth = curDepth;
		int nxtIdx = nxt[curIdx][k];

		if(nxtIdx < 0) continue;

		if(k == SLASH)
		{
			nxtDepth++;
			for(int i=0; i<curDepth; i++)
				cout << "--";
			cout << curS << '\n';
			DFS(nxtIdx, "", nxtDepth);
		}
		else
			DFS(nxtIdx, curS + i2c(k), nxtDepth);
	}
}

int main()
{
	FASTIO;

	fill(&nxt[0][0], &nxt[MX-1][VAR], -1);

	int N;
	cin >> N;

	while(N--)
	{
		int K;
		cin >> K;

		string total = "";

		while(K--)
		{
			string s;
			cin >> s;
			total += s;
			total += '/';
		}

		Insert(total);
	}

	DFS(ROOT, "", 0);
}
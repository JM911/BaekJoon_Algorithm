// 14425. 문자열 집합
// S4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int MX = 500 * 10'000 + 10;
const int VAR = 26;
const int ROOT = 0;
int unused = 1;

bool chk[MX];
int nxt[MX][VAR];

int c2i(char c)
{
	return c - 'a';
}

void insert(const string& s)
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

bool find(const string& s)
{
	int cur = ROOT;
	for(auto c : s)
	{
		cur = nxt[cur][c2i(c)];
		if(cur < 0)
			return false;
	}

	return chk[cur];
}

int N, M;

int main()
{
	FASTIO;

	fill(&nxt[0][0], &nxt[MX-1][VAR], -1);

	cin >> N >> M;
	while(N--)
	{
		string str;
		cin >> str;
		insert(str);
	}

	int ans = 0;
	while(M--)
	{
		string str;
		cin >> str;
		if(find(str)) ans++;
	}

	cout << ans;
}
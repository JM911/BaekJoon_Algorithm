// 14426. 접두사 찾기
// S1

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int MX = 10'000 * 500 + 10;
const int VAR = 26;
const int ROOT = 0;

int unused = 1;
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
		if(nxt[cur][i] <= 0)
			nxt[cur][i] = unused++;
		cur = nxt[cur][i];
	}
}

bool IsPrefixOfAny(const string& s)
{
	int cur = ROOT;
	for(auto c : s)
	{
		cur = nxt[cur][c2i(c)];
		if(cur <= 0)
			return false;
	}
	return true;
}

int N, M;

int main()
{
	FASTIO;

	cin >> N >> M;
	while(N--)
	{
		string s;
		cin >> s;
		insert(s);
	}

	int ans = 0;
	while(M--)
	{
		string s;
		cin >> s;
		if(IsPrefixOfAny(s)) ans++;
	}

	cout << ans;
}
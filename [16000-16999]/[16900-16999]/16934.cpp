// 16934. 게임 닉네임
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int MX = 100'000 * 10 + 10;
const int VAR = 26;
const int ROOT = 0;

int unused = 1;
int nxt[MX][VAR];
int chk[MX];

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
	chk[cur]++;
}

pair<int, int> find(const string& s)
{
	int cur = ROOT;
	int len = s.size();
	for(int i=0; i<len; i++)
	{
		cur = nxt[cur][c2i(s[i])];
		if(cur <= 0)
			return {0, i+1};
	}

	return {chk[cur], len};
}


int N;

int main()
{
	FASTIO;

	cin >> N;
	while(N--)
	{
		string s;
		cin >> s;
		
		auto [num, len] = find(s);
		
		string ans = "";
		for(int i=0; i<len; i++)
			ans += s[i];
		if(num > 0)
			ans += to_string(num+1);

		cout << ans << '\n';
		insert(s);
	}
}
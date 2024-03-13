// 5052. 전화번호 목록
// G4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int ROOT = 0;
const int MX = 10 * 10'000 + 10;
const int VAR = 10;

int unused = 1;
int nxt[MX][VAR];
bool chk[MX];

int c2i(char c)
{
	return c - '0';
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

bool IsPrefixOfAny(const string& s)
{
	int cur = ROOT;
	for(auto c : s)
	{
		int i = c2i(c);
		if(nxt[cur][i] < 0)
			return false;
		cur = nxt[cur][i];
	}

	return true;
}

bool MyComp(const string& a, const string& b)
{
	return a.size() > b.size();
}

void Solve()
{
	fill(&nxt[0][0], &nxt[MX-1][VAR], -1);
	unused = 1;

	int n;
	cin >> n;

	vector<string> v(n);
	for(auto& elem : v)
		cin >> elem;
	sort(v.begin(), v.end(), MyComp);
	
	bool bAns = true;
	for(auto s : v)
	{
		if(IsPrefixOfAny(s))
		{
			bAns = false;
			break;
		}

		Insert(s);
	}

	cout << (bAns ? "YES\n" : "NO\n");
}

int t;

int main()
{
	FASTIO;

	cin >> t;
	while(t--)
		Solve();

	return 0;
}
// 16906. 욱제어
// P4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int ROOT = 0;
const int MX = 1000 * 1000 + 10;
const int VAR = 2;

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

bool Find(const string& s)
{
	int cur = ROOT;
	for(auto c : s)
	{
		int i = c2i(c);
		if(nxt[cur][i] < 0)
			return false;
		cur = nxt[cur][i];
	}
	return chk[cur];
}

pair<string, bool> CreateNew(int len, string curS)
{
	if(curS.size() == len)
	{
		if(Find(curS))
			return {curS, false};
		
		return {curS, true};
	}

	curS += '0';
	if(!Find(curS))
	{
		auto result = CreateNew(len, curS);
		if(result.second) return {result.first, true};
	}

	curS = curS.substr(0, curS.size()-1);

	curS += '1';
	if(!Find(curS))
	{
		auto result = CreateNew(len, curS);
		if(result.second) return {result.first, true};
	}

	curS = curS.substr(0, curS.size()-1);
	return {curS, false};
}

void Solve()
{
	fill(&nxt[0][0], &nxt[MX-1][VAR], -1);

	int N;
	cin >> N;

	vector<int> L(N);
	for(auto& elem : L)
		cin >> elem;

	vector<int> L2 = L;

	sort(L2.begin(), L2.end());
	queue<string> ans[1010];

	for(auto elem : L2)
	{
		string curS = "";
		auto result = CreateNew(elem, curS);
		if(!result.second)
		{
			cout << -1;
			return;
		}

		Insert(result.first);
		ans[elem].push(result.first);
	}

	cout << 1 << '\n';
	for(auto elem : L)
	{
		cout << ans[elem].front() << '\n';
		ans[elem].pop();
	}
}

int main()
{
	FASTIO;

	Solve();
}
// 9202. Boggle
// P5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

const int ROOT = 0;
const int MX = 8 * 300'000 + 10;
const int VAR = 26;

int unused = 1;
int nxt[MX][VAR];
bool chk[MX];

int c2i(char c)
{
	return c - 'A';
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

int Find(const string& s)	// 0: 없음, 1: 접두사, 2: 단어
{
	int cur = ROOT;
	for(auto c : s)
	{
		int i = c2i(c);
		if(nxt[cur][i] < 0)
			return 0;
		cur = nxt[cur][i];
	}

	if(chk[cur]) return 2;
	return 1;
}

struct MyComp
{
	bool operator()(const string& a, const string& b) const
	{
		if(a.size() == b.size())
			return a < b;
		return a.size() > b.size();
	}
};

char board[4][4];
bool vis[4][4];
// set<string, MyComp> ans;
unordered_map<string, bool> ans;
string curS;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int curX, int curY)
{
	if(vis[curX][curY]) return;

	char c = board[curX][curY];
	vis[curX][curY] = true;
	curS += c;

	int result = Find(curS);
	if(result == 0)
	{
		curS = curS.substr(0, curS.size()-1);
		vis[curX][curY] = false;
		return;
	}

	if(result == 2)
		ans[curS] = true;

	for(int i=0; i<8; i++)
	{
		int x = curX + dx[i];
		int y = curY + dy[i];

		if(x<0 || y<0 || x>=4 || y>=4) continue;
		DFS(x, y);
	}

	vis[curX][curY] = false;
	curS = curS.substr(0, curS.size()-1);
}

int GetScore(const string& s)
{
	switch(s.size())
	{
	case 3:
	case 4:
		return 1;
	case 5:
		return 2;
	case 6:
		return 3;
	case 7:
		return 5;
	case 8:
		return 11;
	}

	return 0;
}

void Solve()
{
	ans.clear();

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			cin >> board[i][j];

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			DFS(i, j);
	
	int ansScore = 0;
	int ansCount = 0;
	int maxScore = 0;
	string maxS = "";

	for(auto elem : ans)
	{
		if(!elem.second) continue;
		
		string elemS = elem.first;
		int curScore = GetScore(elemS);
		ansScore += curScore;
		ansCount++;

		if(elemS.size() > maxS.size()) maxS = elemS;
		else if(elemS.size() == maxS.size())
			maxS = min(maxS, elemS);
	}

	cout << ansScore << ' ' << maxS << ' ' << ansCount << '\n';
}

int main()
{
	FASTIO;

	fill(&nxt[0][0], &nxt[MX-1][VAR], -1);

	int w;
	cin >> w;
	while(w--)
	{
		string s;
		cin >> s;
		Insert(s);
		ans.insert({s, false});
	}

	int b;
	cin >> b;
	while(b--)
		Solve();
}
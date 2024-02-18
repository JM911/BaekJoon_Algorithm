// 22856. 트리 순회
// G4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;
int p[100010];
int lc[100010];
int rc[100010];
unordered_set<int> s;

int main()
{
	FASTIO;

	cin >> N;
	int cnt = N;
	while(cnt--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		lc[a] = b;
		rc[a] = c;
		if(b>0)
			p[b] = a;
		if(c>0)
			p[c] = a;
		s.insert(a);
	}

	int cur = 1;
	int ans = -1;

	int inorderCur = 1;
	int inorderNext = rc[inorderCur];
	while(inorderNext > 0)
	{
		inorderCur = inorderNext;
		inorderNext = rc[inorderCur];
	}

	int inorderEnd = inorderCur;

	while(true)
	{
		int curL = lc[cur];
		int curR = rc[cur];
		s.erase(cur);
		ans++;

		if(curL>0 && s.find(curL)!=s.end())
			cur = curL;
		else if(curR>0 && s.find(curR)!=s.end())
			cur = curR;
		else if(cur == inorderEnd)
			break;
		else if(p[cur]>0)
			cur = p[cur];
		else
			break;
	}

	cout << ans;
}
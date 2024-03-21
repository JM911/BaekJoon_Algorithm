// 1543. 문서 검색
// S5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int main()
{
	FASTIO;

	string p, t;
	getline(cin, p);
	getline(cin, t);

	int ans = 0;
	int pos = 0;
	while(pos < p.size())
	{
		int nxtPos = p.find(t, pos);
		if(nxtPos == string::npos)
			break;
		ans++;
		pos = nxtPos + t.size();
	}

	cout << ans;
}
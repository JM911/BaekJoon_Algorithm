// 19583. 싸이버개강총회
// S2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

string S, E, Q;
unordered_set<string> us;

int MyComp(string a, string b)
{
	int ah = stoi(a.substr(0, 2));
	int am = stoi(a.substr(3, 2));
	int bh = stoi(b.substr(0, 2));
	int bm = stoi(b.substr(3, 2));

	if(ah < bh) return -1;
	if(ah == bh)
	{
		if(am < bm) return -1;
		if(am == bm) return 0;
		if(am > bm) return 1;
	}
	return 1;
}

int main()
{
	FASTIO;

	cin >> S >> E >> Q;
	
	int prevState = 0;	// 0: 시작 전, 1: 시작 후, 2: 끝난 후 ~ 스트리밍 종료 전
	int ans = 0;
	while(true) //!cin.eof()) //idx < len)
	{
		string timeStr, nameStr;

		cin >> timeStr >> nameStr;
		if(cin.eof() == 1) break;

		int compResult = 0;
		if(prevState == 0)
		{
			compResult = MyComp(timeStr, S);
			if(compResult > 0)
				prevState = 1;
			else
			{
				us.insert(nameStr);
			}
		}
		if(prevState == 1)
		{
			compResult = MyComp(timeStr, E);
			if(compResult >= 0)
				prevState = 2;
		}
		if(prevState == 2)
		{
			compResult = MyComp(timeStr, Q);
			if(compResult > 0)
				prevState = 3;
			else
			{
				if(us.find(nameStr) != us.end())
				{
					ans++;
					us.erase(nameStr);
				}
			}
		}
		//cout << ans << '\n';
	}

	cout << ans;
}
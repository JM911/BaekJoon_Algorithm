// 1759. 암호 만들기
// G5

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int L, C;
char cand[20];
char ans[20];

bool IsVowel(char a)
{
	switch(a)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
	}

	return false;
}

bool Check()
{
	int vowelNum = 0;
	int consonantNum = 0;

	for(int i=0; i<L; i++)
	{
		if(IsVowel(ans[i]))
			vowelNum++;
		else
			consonantNum++;
	}

	if(vowelNum >= 1 && consonantNum >= 2)
		return true;
	return false;
}

void Solve(int len, int lastIdx)
{
	if(len >= L)
	{
		if(Check())
		{
			for(int i=0; i<L; i++)
			{
				cout << ans[i];
			}
			cout << '\n';
		}
		return;
	}

	for(int i=lastIdx+1; i<C; i++)
	{
		ans[len] = cand[i];
		Solve(len+1, i);
	}
}

int main()
{
	setIO("");

	cin >> L >> C;
	for(int i=0; i<C; i++)
	{
		cin >> cand[i];
	}

	sort(cand, cand+C);
	Solve(0, -1);
}
// 11656. 접미사 배열
// S4

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

string S;
vector<int> v;

bool MyComp(int a, int b)
{
	int i = 0;
	int len = S.length();
	while(a+i<len && b+i<len)
	{
		if(S[a+i] == S[b+i])
		{
			i++;
			continue;
		}

		return S[a+i] < S[b+i];
	}

	return a > b;
}

int main()
{
	setIO("");

	cin >> S;

	int len = S.length();
	v.resize(len);
	for(int i=0; i<len; i++)
	{
		v[i] = i;
	}

	sort(v.begin(), v.end(), MyComp);

	for(auto a : v)
	{
		for(int i=a; i<len; i++)
		{
			cout << S[i];
		}
		cout << '\n';
	}
}
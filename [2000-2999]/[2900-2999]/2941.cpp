// 2941. 크로아티아 알파벳
// S5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

string cr[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

pair<int, int> FindCr(const string& s, int pos)
{
	int len = s.size();
	for(int i=pos; i<len-1; i++)
	{
		if(s[i] == 'c')
			if(s[i+1] == '=' || s[i+1] == '-')
				return {i, 2};
		
		if(s[i] == 'd')
		{
			if(s[i+1] == '-')
				return {i, 2};
			if(i+2 < len && s[i+1] == 'z' && s[i+2] == '=')
				return {i, 3};
		}
		
		if(s[i] == 'l' || s[i] == 'n')
			if(s[i+1] == 'j')
				return {i, 2};
		
		if(s[i] == 's' || s[i] == 'z')
			if(s[i+1] == '=')
				return {i, 2};
	}
	return {-1, 0};
}

int main()
{
	FASTIO;

	string s;
	cin >> s;

	int ans = s.size();
	auto f = FindCr(s, 0);
	while(f.first >= 0 && f.first < s.size())
	{
		ans -= (f.second - 1);
		f = FindCr(s, f.first + f.second);
	}

	cout << ans;
}
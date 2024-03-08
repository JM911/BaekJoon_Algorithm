// 1786. 찾기
// P5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

vector<int> GetFailureFunc(const string& S)
{
	vector<int> F;

	int len = S.size();
	F.resize(len);
	F[0] = 0;
	int j = 0;

	for(int i=1; i<len; i++)
	{
		while(S[i]!=S[j] && j>0) j=F[j-1];
		if(S[i] == S[j]) F[i] = ++j;
		else F[i] = 0;
	}

	return F;
}

vector<int> kmpSearch(const string& pattern, const string& target)
{
	vector<int> ret;
	vector<int> F = GetFailureFunc(target);

	int lenP = pattern.size();
	int lenT = target.size();
	ret.reserve(lenP);
	int j = 0;

	for(int i=0; i<lenP; i++)
	{
		while(pattern[i] != target[j] && j>0) j=F[j-1];
		if(pattern[i] == target[j])
			if(++j>=lenT)
			{
				ret.push_back(i-j+1);
				j = F[j-1];
			}
	}

	return ret;
}


string T, P;

int main()
{
	FASTIO;

	getline(cin, T);
	getline(cin, P);

	vector<int> ans = kmpSearch(T, P);

	cout << ans.size() << '\n';
	for(auto e : ans)
		cout << e+1 << ' ';
}
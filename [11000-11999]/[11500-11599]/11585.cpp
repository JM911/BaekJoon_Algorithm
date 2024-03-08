// 11585. 속타는 저녁 메뉴
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

int gcd(int b, int s)
{
	if(b % s == 0) return s;
	return gcd(s, b%s);
}

int N;
string pattern, target;

int main()
{
	FASTIO;

	cin >> N;

	for(int i=0; i<N; i++)
	{
		char a;
		cin >> a;
		target += a;
	}

	for(int i=0; i<N; i++)
	{
		char a;
		cin >> a;
		pattern += a;
	}

	string added = pattern.substr(0, N-1);
	pattern += added;

	int a = kmpSearch(pattern, target).size();
	int g = gcd(N, a);
	cout << a/g << '/' << N/g;
}
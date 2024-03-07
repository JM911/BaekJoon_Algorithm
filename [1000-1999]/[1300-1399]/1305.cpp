// 1305. 광고
// P4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

void GetFailureFunc(const string& S, vector<int>& outF)
{
	int len = S.length();
	outF.clear();
	outF.resize(len);

	outF[0] = 0;
	int j = 0;
	
	for(int i=1; i<len; i++)
	{
		while(S[i]!=S[j] && j>0) j = outF[j-1];
		if(S[i] == S[j]) outF[i] = ++j;
		else outF[i] = 0;
	}
}

int L;
string S;

int main()
{
	FASTIO;

	cin >> L >> S;

	vector<int> F;
	GetFailureFunc(S, F);

	cout << L - F[L-1];
}
// 4354. 문자열 제곱
// P5

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

string S;

int main()
{
	FASTIO;

	while(true)
	{
		cin >> S;
		if(S == ".") break;

		int L = S.size();
		vector<int> F;

		GetFailureFunc(S, F);

		int lenA = F[L-1];
		if(lenA < L/2)
			lenA = L;
		else
			lenA = L - lenA;

		if(L%lenA == 0)
			cout << L/lenA << '\n';
		else
			cout << 1 << '\n';
	}
}
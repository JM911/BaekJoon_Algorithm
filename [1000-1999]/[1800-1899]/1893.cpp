// 1893. 시저 암호
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

bool KMP(const string& S, const string& P, const vector<int>& PF)
{
	int lenS = S.length();
	int lenP = P.length();
	
	if(PF.size() < lenP) return false;

	int i=0, j=0;
	while(i < lenS)
	{
		while(S[i]!=P[j] && j>0) j=PF[j-1];
		if(S[i]==P[j] && ++j >= lenP) return true;
		else i++;
	}

	return false;
}

int KMP_All(const string& S, const string& P, const vector<int>& PF)
{
	int lenS = S.length();
	int lenP = P.length();
	int ret = 0;
	
	if(PF.size() < lenP) return ret;

	int i=0, j=0;
	while(i < lenS)
	{
		while(S[i]!=P[j] && j>0) j=PF[j-1];
		if(S[i]==P[j] && ++j >= lenP)
		{
			ret++;
			j=PF[j-1];
			i++;
		}
		else i++;
	}

	return ret;
}

int KMP_All_vec(const vector<char>& S, const vector<char>& P, const vector<int>& PF)
{
	int lenS = S.size();
	int lenP = P.size();
	int ret = 0;
	
	if(PF.size() < lenP) return ret;

	int i=0, j=0;
	while(i < lenS)
	{
		while(S[i]!=P[j] && j>0) j=PF[j-1];
		if(S[i]==P[j] && ++j >= lenP)
		{
			ret++;
			j=PF[j-1];
			i++;
		}
		else i++;
	}

	return ret;
}

int N;

int main()
{
	FASTIO;

	cin >> N;

	while(N--)
	{
		string A, W, S;
		cin >> A >> W >> S;

		unordered_map<char, int> ci;
		unordered_map<int, char> ic;

		int lenA = A.length();
		for(int i=0; i<lenA; i++)
		{
			ci.insert({A[i], i});
			ic.insert({i, A[i]});
		}

		vector<int> ans;
		vector<int> F;
		GetFailureFunc(W, F);

		int lenW = W.length();
		for(int i=0; i<lenA; i++)
		{
			string shiftW = "";
			for(auto e : W)
			{
				int idx = ci[e];
				idx = (idx+i)%lenA;
				shiftW += ic[idx];
			}

			if(KMP_All(S, shiftW, F) == 1)
				ans.push_back(i);
		}

		if(ans.size() == 0)
			cout << "no solution";
		else if(ans.size() == 1)
			cout << "unique: " << ans[0];
		else
		{
			cout << "ambiguous: ";
			for(auto e : ans)
				cout << e << ' ';
		}
		cout << '\n';
	}
}
// 16172. 나는 친구가 적다 (Large)
// B2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

string S, P;
vector<int> F;

int main()
{
	FASTIO;

	cin >> S >> P;

	// P의 실패 함수
	F.resize(P.length());
	F[0] = 0;
	int i = 1, j = 0;
	int lenS = S.length(), lenP = P.length();
	while(i<lenP)
	{
		if(P[i] == P[j])
		{
			F[i] = j+1;
			i++;
			j++;
		}
		else if(j > 0)
			j = F[j-1];
		else
		{
			F[i] = 0;
			i++;
			j = 0;
		}
	}

	// KMP
	i = 0;
	j = 0;
	bool bSub = false;
	while(i < lenS)
	{
		int t = (int)S[i] - (int)'0';
		if(t>=0 && t<=9)
			i++;
		else if(S[i] == P[j])
		{
			i++;
			j++;
			if(j >= lenP)
			{
				bSub = true;
				break;
			}
		}
		else if(j>0)
			j = F[j-1];
		else
			i++;
	}

	cout << bSub ? 1 : 0;
}
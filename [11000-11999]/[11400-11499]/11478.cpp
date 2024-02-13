// 11478. 서로 다른 부분 문자열의 개수
// S3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

string S;
unordered_set<string> mySet;

int main()
{
	FASTIO;

	cin >> S;
	int len = S.length();

	for(int i=0; i<len; i++)
	{
		for(int j=i; j<len; j++)
		{
			string subS = "";
			subS.resize(j-i+1);
			for(int k=i; k<=j; k++)
			{
				subS[k-i] = S[k];
			}
			mySet.insert(subS);
		}
	}

	cout << mySet.size();
}
// 2143. 두 배열의 합
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int T, n, m;
vector<int> A, B;
vector<int> pA, pB, psB;

int main()
{
	FASTIO;

	cin >> T;
	
	cin >> n;
	A.resize(n);
	int curSum = 0;
	pA.push_back(0);
	for(auto& e : A)
	{
		cin >> e;
		curSum += e;
		pA.push_back(curSum);
	}

	cin >> m;
	B.resize(m);
	curSum = 0;
	pB.push_back(0);
	for(auto& e : B)
	{
		cin >> e;
		curSum += e;
		pB.push_back(curSum);
	}

	for(int i=0; i<m+1; i++)
	{
		for(int j=0; j<i; j++)
		{
			psB.push_back(pB[i] - pB[j]);
		}
	}
	sort(psB.begin(), psB.end());

	long long ans = 0;
	for(int i=0; i<n+1; i++)
	{
		for(int j=0; j<i; j++)
		{
			int sumA = pA[i] - pA[j];
			int target = T - sumA;
			ans += (upper_bound(psB.begin(), psB.end(), target) - lower_bound(psB.begin(), psB.end(), target));
		}
	}

	cout << ans;
}
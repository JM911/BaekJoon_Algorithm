// 2512. 예산
// S2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M;
vector<int> b;

bool CanBe(int maxB)
{
	int cur = 0;
	for(auto a : b)
	{
		if(a < maxB)
			cur += a;
		else
			cur += maxB;
	}

	return cur <= M;
}

int main()
{
	FASTIO;

	int left = 0;
	int right = 0;

	cin >> N;
	b.resize(N);
	for(auto& a : b)
	{
		cin >> a;
		right = max(right, a);
	}

	cin >> M;

	while(left < right)
	{
		int mid = (left+right+1)/2;
		bool bCan = CanBe(mid);
		if(bCan)
			left = mid;
		else
			right = mid-1;
	}

	cout << left;
}
// 12015. 가장 긴 증가하는 부분 수열 2
// G2

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;
vector<int> A;
vector<int> B;

int GetIdx(int target)
{
	int left = 0;
	int right = B.size();

	while(left < right)
	{
		int mid = (left+right)/2;
		if(B[mid] == target)
			return mid;
		if(B[mid] > target)
			right = mid;
		else
			left = mid+1;
	}

	return left;
}

int main()
{
	FASTIO;

	cin >> N;
	A.resize(N);
	for(auto& e : A)
	{
		cin >> e;
	}

	B.push_back(A[0]);

	for(int i=1; i<N; i++)
	{
		int idx = GetIdx(A[i]);
		if(idx >= B.size())
		{
			B.push_back(A[i]);
		}
		else
		{
			B[idx] = A[i];
		}
	}

	cout << B.size();
}
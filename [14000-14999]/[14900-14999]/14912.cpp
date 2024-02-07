// 14912. 용액 합성하기
// G5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;
vector<int> A;

int main()
{
	FASTIO;

	cin >> N;
	A.resize(N);
	for(auto& e : A)
	{
		cin >> e;
	}

	sort(A.begin(), A.end());

	int left = 0;
	int right = N-1;
	int ans = A[0] + A[N-1];

	while(left < right)
	{
		int cur = A[left] + A[right];
		if(abs(cur) < abs(ans))
			ans = cur;
		
		if(cur < 0)
			left++;
		else
			right--;
	}

	cout << ans;
}
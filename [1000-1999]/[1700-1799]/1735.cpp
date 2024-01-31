// 1735. 분수 합
// S3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int gcd(int big, int small)
{
	if(small == 0) return big;
	return gcd(small, big%small);
}

int lcm(int big, int small)
{
	return big / gcd(big, small) * small;
}

int main()
{
	FASTIO;

	int A1, A2, B1, B2;
	cin >> A1 >> A2 >> B1 >> B2;

	int big2 = max(A2, B2);
	int small2 = min(A2, B2);
	int l = lcm(big2, small2);

	int multA = l/A2;
	int multB = l/B2;

	int ans1 = A1 * multA + B1 * multB;
	int ans2 = l;

	int g = gcd(max(ans1, ans2), min(ans1, ans2));
	cout << ans1/g << ' ' << ans2/g;
}
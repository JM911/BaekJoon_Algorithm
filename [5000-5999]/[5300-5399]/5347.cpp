// 5347. LCM
// S5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
ll n, a, b;

ll gcd(ll big, ll small)
{
	if(small == 0) return big;
	return gcd(small, big%small);
}

ll lcm(ll big, ll small)
{
	return big / gcd(big, small) * small;
}

int main()
{
	FASTIO;

	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		cout << lcm(max(a, b), min(a, b)) << '\n';
	}
}
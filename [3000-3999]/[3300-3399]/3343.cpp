// 3343. 장미
// G4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
ll N, A, B, C, D;

ll gcd(ll big, ll small)
{
	if(small == 0ll) return big;
	return gcd(small, big%small);
}

ll lcm(ll big, ll small)
{
	return big / gcd(big, small) * small;
}

int main()
{
	FASTIO;

	cin >> N >> A >> B >> C >> D;

	ll expN, expP, cheapN, cheapP;
	if(B * C == A * D)
	{
		if(A < C)	// 개당 가격이 같으면 덩어리가 더 큰 것을 cheap 으로 선택
		{
			expN = A;
			expP = B;
			cheapN = C;
			cheapP = D;
		}
		else
		{
			expN = C;
			expP = D;
			cheapN = A;
			cheapP = B;
		}
	}
	else if(B * C < A * D)
	{
		expN = C;
		expP = D;
		cheapN = A;
		cheapP = B;
	}
	else
	{
		expN = A;
		expP = B;
		cheapN = C;
		cheapP = D;
	}

	ll l = lcm(expN, cheapN);
	ll ans = LONG_LONG_MAX;
	for(ll i=0ll; i<=l/expN; i++)
	{
		ll expBundle = i;
		//if(expBundle * expN > N) break;

		ll expTotalNum = expBundle * expN;
		ll cheapTargetNum = N - expTotalNum;
		ll cheapBundle = cheapTargetNum / cheapN + (((cheapTargetNum % cheapN) > 0ll) ? 1ll : 0ll);

		ll curPrice = max(0ll, expBundle) * expP + max(0ll, cheapBundle) * cheapP;
		ans = min(ans, curPrice);
	}

	cout << ans;
}
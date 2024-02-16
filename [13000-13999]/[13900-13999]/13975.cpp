// 13975. 파일 합치기 3
// G4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int T, K;

int main()
{
	FASTIO;

	cin >> T;
	while(T--)
	{
		cin >> K;
		priority_queue<ll, vector<ll>, greater<ll>> pq;

		while(K--)
		{
			int tmp;
			cin >> tmp;
			pq.push(tmp);
		}

		long long ans = 0;
		while(pq.size() > 1)
		{
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();

			ans += (a+b);
			pq.push(a+b);
		}

		cout << ans << '\n';
	}
}
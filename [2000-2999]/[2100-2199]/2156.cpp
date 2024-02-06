// 2156. 포도주 시식
// S1

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int n;
int w[10010];
int d[10010];

int main()
{
	FASTIO;

	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> w[i];
	}

	d[0] = w[0];
	d[1] = w[0] + w[1];
	d[2] = max(0 + w[1] + w[2], d[0] + w[2]);
	d[3] = max(max(d[0] + w[2] + w[3], d[1] + w[3]), max(d[0] + w[3], 0 + w[2] + w[3]));

	for(int i=4; i<n; i++)
	{
		int tmp1 = max(d[i-3] + w[i-1] + w[i], d[i-2] + w[i]);	// 1칸 여유
		int tmp2 = max(d[i-3] + w[i], d[i-4] + w[i-1] + w[i]);	// 2칸 여유
		// 3칸 여유부터는 체크X (3칸 이상 쉬면 중간 와인도 먹는게 무조건 이득)
		d[i] = max(tmp1, tmp2);
	}

	int ans = d[n-1];
	if(n>1)
		ans = max(ans, d[n-2]);

	cout << ans;
}
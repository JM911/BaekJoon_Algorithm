// 2461. 대표 선수
// G1

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M;
vector<vector<int>> vc;

int main()
{
	FASTIO;

	cin >> N >> M;
	vc.resize(N);
	for(auto& a : vc)
	{
		a.resize(M);
		for(auto& b : a)
		{
			cin >> b;
		}
		sort(a.begin(), a.end());
	}

	// pq 에 tuple로 저장 (tuple는 선수 능력치 & 반 인덱스 & 선수 인덱스)
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	int curMax = 0;
	for(int i=0; i<N; i++)
	{
		pq.push({vc[i][0], i, 0});
		curMax = max(curMax, vc[i][0]);
	}
	
	// 최소가 되는 선수를 같은 반 다음 선수로 교체 => 최소인 선수가 마지막 번호라서 못넘어가면 종료, 교체 시 최대 값 갱신
	int ans = 0x7f7f7f7f;
	while(true)
	{		
		auto cur = pq.top();
		pq.pop();
		ans = min(ans, curMax - get<0>(cur));

		int curClass = get<1>(cur);
		int nxtIdx = get<2>(cur) + 1;
		if(nxtIdx >= M)
			break;

		int nxtVal = vc[curClass][nxtIdx];
		curMax = max(curMax, nxtVal);

		tuple<int, int, int> nxt = {nxtVal, curClass, nxtIdx};
		pq.push(nxt);
	}

	cout << ans;
}
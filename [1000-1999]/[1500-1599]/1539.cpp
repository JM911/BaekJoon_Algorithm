// 1539. 이진 검색 트리
// P5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int N;
set<pair<int, int>> s;
ll ans;

int main()
{
	FASTIO;

	cin >> N;

	int tmp;
	cin >> tmp;
	N--;

	s.insert({tmp, 1});
	ans += 1;

	while(N--)
	{
		cin >> tmp;
		auto iter = s.lower_bound({tmp, 0});

		int height = 0;
		if(iter != s.end())
			height = max(height, iter->second + 1);
		if(iter != s.begin())
			height = max(height, prev(iter)->second + 1);
		
		s.insert({tmp, height});
		ans += height;
	}

	cout << ans;
}
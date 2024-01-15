// 13913. 숨바꼭질 4
// G4

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int N, K;
pair<int, int> distPrev[200010];

int MyMove(int x, int idx)
{
	switch(idx)
	{
		case 0:
			return x+1;
		case 1:
			return x-1;
		default:
			return 2*x;
	}
}

int main()
{
	setIO("");

	cin >> N >> K;

	fill(distPrev, distPrev+200001, make_pair(-1, -1));
	
	queue<int> q;
	distPrev[N] = {0, -1};
	q.push(N);

	while(!q.empty())
	{
		int curX = q.front();
		q.pop();

		for(int l=0; l<3; l++)
		{
			int x = MyMove(curX, l);

			if(x<0 || x>200000) continue;
			if(distPrev[x].first >= 0) continue;

			distPrev[x] = {distPrev[curX].first + 1, curX};
			q.push(x);
		}
	}

	stack<int> s;
	int curIdx = K;
	
	while(curIdx >= 0)
	{
		s.push(curIdx);
		curIdx = distPrev[curIdx].second;
	}

	cout << s.size() - 1 << '\n';
	while(!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
}
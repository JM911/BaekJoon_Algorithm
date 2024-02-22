// 2887. 행성 터널
// P5

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

struct Coord
{
	int idx = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	
	void SetCoord(int i, int a, int b, int c)
	{
		idx = i;
		x = a;
		y = b;
		z = c;
	}
};

int N;
int u[100010];
vector<Coord> P;
vector<tuple<int, int, int>> dab;

int MyFind(int x)
{
	if(u[x] < 0) 
		return x;
	return u[x] = MyFind(u[x]);
}

void MyMerge(int x, int y)
{
	x = MyFind(x);
	y = MyFind(y);

	if(x == y)
		return;
	if(u[x] == u[y])
	{
		u[x] = y;
		u[y]--;
	}
	else if(u[x] < u[y])
		u[y] = x;
	else
		u[x] = y;
}

bool MyCompX(Coord a, Coord b)
{
	return a.x < b.x;
}

bool MyCompY(Coord a, Coord b)
{
	return a.y < b.y;
}

bool MyCompZ(Coord a, Coord b)
{
	return a.z < b.z;
}

int main()
{
	FASTIO;

	cin >> N;
	P.resize(N);
	for(int i=0; i<N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		P[i].SetCoord(i, a, b, c);
	}

	sort(P.begin(), P.end(), MyCompX);
	for(int i=0; i<N-1; i++)
	{
		dab.push_back({abs(P[i+1].x - P[i].x), P[i].idx, P[i+1].idx});
	}

	sort(P.begin(), P.end(), MyCompY);
	for(int i=0; i<N-1; i++)
	{
		dab.push_back({abs(P[i+1].y - P[i].y), P[i].idx, P[i+1].idx});
	}

	sort(P.begin(), P.end(), MyCompZ);
	for(int i=0; i<N-1; i++)
	{
		dab.push_back({abs(P[i+1].z - P[i].z), P[i].idx, P[i+1].idx});
	}

	sort(dab.begin(), dab.end());

	
	for(int i=0; i<N; i++)
		u[i] = -1;

	int cnt = 0;
	long long ans = 0;
	int idx = 0;

	while(cnt < N-1 && idx < dab.size())
	{
		int curDist, curA, curB;
		tie(curDist, curA, curB) = dab[idx++];

		if(MyFind(curA) == MyFind(curB)) continue;

		MyMerge(curA, curB);
		ans += curDist;
		cnt++;
	}

	cout << ans;
}
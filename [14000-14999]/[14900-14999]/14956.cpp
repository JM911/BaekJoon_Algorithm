// 14956. Philosopher’s Walk
// G2

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

int n, m;

pair<int, int> MyFunc(int len, int dist)
{
	if(len <= 2)
	{
		switch(dist)
		{
			case 1:
				return {1, 1};
			case 2:
				return {1, 2};
			case 3:
				return {2, 2};
			case 4:
				return {2, 1};
		}
		return {0, 0};
	}
	
	int div = len / 4 * len;
	int smallDist = (dist - 1) % div + 1;
	pair<int, int> smallCoord = MyFunc(len/2, smallDist);

	int bigDist = (dist - 1) / div + 1;
	switch(bigDist)
	{
		case 1:
			return {smallCoord.second, smallCoord.first};
		case 2:
			return {smallCoord.first, smallCoord.second + len/2};
		case 3:
			return {smallCoord.first + len/2, smallCoord.second + len/2};
		case 4:
			return { 1+len - smallCoord.second, 1+len - (smallCoord.first + len/2)};
	}

	return {0, 0};
}

int main()
{
	setIO("");

	cin >> n >> m;

	pair<int, int> ans = MyFunc(n, m);
	cout << ans.first << ' ' << ans.second;
}
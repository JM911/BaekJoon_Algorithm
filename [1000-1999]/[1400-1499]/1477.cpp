// 1477. 휴게소 세우기
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

int N, M, L;
vector<int> v;
vector<pair<int, int>> v2;

bool MyComp(pair<int, int> a, pair<int, int> b)
{
    int lenA = (a.first - 1) / (a.second + 1);
    int lenB = (b.first - 1) / (b.second + 1);
    return lenA > lenB;
}

int main()
{
	setIO("");

    cin >> N >> M >> L;
    v.resize(N);
    for(auto& a : v)
    {
        cin >> a;
    }

    sort(v.begin(), v.end());
    for(int i=0; i<N-1; i++)
    {
        v2.push_back({v[i+1] - v[i], 0});
    }

    if(N>0)
    {
        v2.push_back({v[0], 0});
        v2.push_back({L - v[N-1], 0});
    }
    else
    {
        v2.push_back({L, 0});
    }

    sort(v2.begin(), v2.end(), MyComp);

    while(M--)
    {
        v2[0].second++;
        sort(v2.begin(), v2.end(), MyComp);
    }

    cout << (v2[0].first-1)/(v2[0].second+1) + 1;
}
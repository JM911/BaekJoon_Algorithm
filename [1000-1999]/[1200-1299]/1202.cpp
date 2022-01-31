// 1202. 보석 도둑
// G2

#include <bits/stdc++.h>
using namespace std;

int N, K;
//int C[300010];
multiset<int> C;
vector<pair<int, int>> v;
long long ans;

bool myComp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int mass, val;
        cin >> mass >> val;

        v.push_back({val, mass});
    }

    sort(v.begin(), v.end(), myComp);

    for (int i = 0; i < K; i++)
    {
        int tmp;
        cin >> tmp;
        C.insert(tmp);
    }

    for (int i = N-1; i >= 0; i--)
    {
        int curVal = v[i].first;
        int curMass = v[i].second;

        auto iter = C.lower_bound(curMass);

        if(iter == C.end())
            continue;

        ans += curVal;
        C.erase(iter);
    }

    cout << ans;
}
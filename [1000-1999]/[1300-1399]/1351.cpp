// 1351. 무한 수열
// G4

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, P, Q;
unordered_map<ll, ll> m;

ll myFunc(ll n)
{
    if(m.find(n) != m.end())
        return m[n];

    ll ans = myFunc(n / P) + myFunc(n / Q);
    m.insert({n, ans});

    return ans;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> P >> Q;

    m.insert({0, 1});

    cout << myFunc(N);
}
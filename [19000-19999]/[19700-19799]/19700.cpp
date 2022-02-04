// 19700. 수업
// G1

#include <bits/stdc++.h>
using namespace std;

int N;
map<int, int> hk;
map<int, int> groups;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int h, k;
        cin >> h >> k;
        hk.insert({h, k});
    }

    for (auto iter = hk.rbegin(); iter != hk.rend(); ++iter)
    {
        int curRank = iter->second;

        if(groups.empty())
        {
            groups.insert({1, 1});
            continue;
        }

        auto iter_2 = groups.lower_bound(curRank);
        
        if(iter_2 == groups.begin())
        {
            groups[1]++;
            continue;
        }

        iter_2--;
        int curKey = iter_2->first;

        groups[curKey]--;
        groups[curKey + 1]++;

        if(groups[curKey] == 0)
        {
            groups.erase(curKey);
        }
    }

    int ans = 0;

    for(auto i : groups)
    {
        ans += i.second;
    }

    cout << ans;
}
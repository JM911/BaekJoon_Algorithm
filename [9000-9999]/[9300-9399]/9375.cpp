// 9375. 패션왕 신해빈
// S3

#include <bits/stdc++.h>
using namespace std;

int T, n;
unordered_map<string, int> m;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--)
    {
        m.clear();

        cin >> n;

        while(n--)
        {
            string tmp;
            cin >> tmp >> tmp;

            if(m.find(tmp) != m.end())
                m[tmp]++;
            else
                m.insert({tmp, 1});
        }

        int ans = 1;

        for(auto a : m)
        {
            ans *= (a.second + 1);
        }

        cout << ans - 1 << '\n';
    }
}
// 1270. 전쟁- 땅따먹기
// S3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    typedef long long ll;

    int n;
    cin >> n;

    while(n--)
    {
        int T;
        scanf("%d", &T);

        map<ll, int> m;
        map<ll, int>::iterator it;
        ll temp;

        for(int i=0; i<T; i++)
        {
            scanf("%lld", &temp);
            m[temp]++;
        }

        ll ans = 0;

        for(it = m.begin(); it != m.end(); ++it)
        {
            if((*it).second > T/2)
            {
                ans = (*it).first;
                break;
            }
        }

        if(ans)
            cout << ans << '\n';
        else
            cout << "SYJKGW" << '\n';
    }

    return 0;
}

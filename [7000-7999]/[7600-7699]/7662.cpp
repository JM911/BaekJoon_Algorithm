// 7662. 이중 우선순위 큐
// G5

#include <bits/stdc++.h>
using namespace std;

int T, k;
char com;
multiset<int> s;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--)
    {
        s.clear();

        cin >> k;

        while(k--)
        {
            int tmp;

            cin >> com >> tmp;
            
            if(com == 'I')
                s.insert(tmp);
            else
            {
                if(s.empty())
                    continue;

                if(tmp == 1)
                    s.erase(--s.end());
                else
                    s.erase(s.begin());
            }
        }

        if(!s.empty())
            cout << *(s.rbegin()) << ' ' << *(s.begin()) << '\n';
        else
            cout << "EMPTY" << '\n';
    }
}
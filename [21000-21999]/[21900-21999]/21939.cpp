// 21939. 문제 추천 시스템 Version 1
// G4

#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, set<int>*> mm;      // l, p 
unordered_map<int, int> um; // p, l
set<int> s[110];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    while(N--)
    {
        int p, l;
        cin >> p >> l;

        if(mm.find(l) == mm.end())
        {
            s[l].insert(p);
            mm.insert({l, &s[l]});
        }
        else
        {
            mm[l]->insert(p);
        }

        um.insert({p, l});
    }

    cin >> M;
    while(M--)
    {
        string cmd;
        int p, l, x;
        cin >> cmd;

        switch (cmd[0])
        {
        case 'a':
            cin >> p >> l;

            if(mm.find(l) == mm.end())
            {
                s[l].insert(p);
                mm.insert({l, &s[l]});
            }
            else
            {
                mm[l]->insert(p);
            }

            um.insert({p, l});
            break;

        case 'r':
            cin >> x;

            if(x==1)
                p = *(mm.rbegin()->second->rbegin());
            else
                p = *(mm.begin()->second->begin());

            cout << p << '\n';

            break;

        case 's':
            cin >> p;
            l = um[p];

            um.erase(p);
            mm[l]->erase(p);

            if(mm[l]->empty())
                mm.erase(l);

            break;
        }
    }
}
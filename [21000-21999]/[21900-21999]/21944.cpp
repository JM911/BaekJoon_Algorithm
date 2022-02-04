// 21944. 문제 추천 시스템 Version 2
// G3

#include <bits/stdc++.h>
using namespace std;

int N, M;
set<int> problemLevel[105];     // L
set<int> problem[105][105];     // L, G
unordered_map<int, pair<int, int>> plg;  // P, L, G

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    while(N--)
    {
        int p, l, g;
        cin >> p >> l >> g;

        problemLevel[l].insert(p);
        problem[l][g].insert(p);
        plg.insert({p, {l, g}});
    }

    cin >> M;
    while(M--)
    {
        string cmd;
        cin >> cmd;

        if(cmd == "add")
        {
            int p, l, g;
            cin >> p >> l >> g;

            problemLevel[l].insert(p);  
            problem[l][g].insert(p);
            plg.insert({p, {l, g}});
        }

        else if(cmd == "recommend")
        {
            int g, x;
            cin >> g >> x;

            if(x == 1)
            {
                for (int i = 100; i >= 1; i--)
                {
                    if(problem[i][g].empty())
                        continue;

                    cout << *(problem[i][g].rbegin()) << '\n';
                    break;
                }
            }

            else
            {
                for (int i = 1; i <= 100; i++)
                {
                    if(problem[i][g].empty())
                        continue;

                    cout << *(problem[i][g].begin()) << '\n';
                    break;
                }
            }
        }

        else if(cmd == "recommend2")
        {
            int x;
            cin >> x;

            if(x == 1)
            {
                for (int i = 100; i >= 1; i--)
                {
                    if(problemLevel[i].empty())
                        continue;

                    cout << *(problemLevel[i].rbegin()) << '\n';
                    break;
                }
            }

            else
            {
                for (int i = 1; i <= 100; i++)
                {
                    if(problemLevel[i].empty())
                        continue;

                    cout << *(problemLevel[i].begin()) << '\n';
                    break;
                }
            }
        }

        else if(cmd == "recommend3")
        {
            int x, l;
            cin >> x >> l;
            bool forCheck = false;

            if(x == 1)
            {
                for (int i = l; i <= 100; i++)
                {
                    if(problemLevel[i].empty())
                        continue;

                    cout << *(problemLevel[i].begin()) << '\n';
                    forCheck = true;
                    break;
                }
            }

            else
            {
                for (int i = l-1; i >= 1; i--)
                {
                    if(problemLevel[i].empty())
                        continue;

                    cout << *(problemLevel[i].rbegin()) << '\n';
                    forCheck = true;
                    break;
                }
            }

            if(forCheck == false)
                cout << -1 << '\n';
        }

        else    // solved
        {
            int p;
            cin >> p;

            pair<int, int> lg = plg.find(p)->second;
            int l = lg.first;
            int g = lg.second;

            plg.erase(p);

            problemLevel[l].erase(p);
            problem[l][g].erase(p);
        }
    }
}
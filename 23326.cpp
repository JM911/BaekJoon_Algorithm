// 23326. 홍익 투어리스트
// G3

#include <bits/stdc++.h>
using namespace std;

int N, Q, cmd;
int curPos = 1;
set<int> s;
int tmp;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        if(tmp == 1)
            s.insert(i);
    }

    while(Q--)
    {
        cin >> cmd;

        switch(cmd)
        {
        case 1:
            cin >> tmp;

            if(s.find(tmp) == s.end())
                s.insert(tmp);
            else
                s.erase(tmp);

            break;

        case 2:
            cin >> tmp;
            curPos = (curPos + tmp - 1) % N + 1;
            break;

        case 3:
            if(s.empty())
            {
                cout << -1 << '\n';
                break;
            }

            auto iter = s.lower_bound(curPos);

            if(iter == s.end())
            {
                cout << *(s.begin()) + (N - curPos) << '\n';
            }
            else
            {
                cout << *iter - curPos << '\n';
            }

            break;
        }
    }
}
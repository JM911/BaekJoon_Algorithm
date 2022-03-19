// 5430. AC
// G5

#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--)
    {
        string p;
        cin >> p;

        int n;
        string x;
        list<int> l;

        cin >> n;
        cin >> x;

        int i = 0;
        int tmpNum = 0;

        while(i < x.length())
        {
            if(x[i] >= '0' && x[i] <= '9')
            {
                tmpNum *= 10;
                tmpNum += x[i] - '0';
            }
            else if(tmpNum)
            {
                l.push_back(tmpNum);
                tmpNum = 0;
            }

            i++;
        }

        bool dir = true;
        bool error = false;

        for (int j = 0; j < p.length(); j++)
        {
            if(p[j] == 'R')
                dir = !dir;
            else
            {
                if(l.size() == 0)
                {
                    error = true;
                    break;
                }

                if(dir)
                    l.pop_front();
                else
                    l.pop_back();
            }
        }

        if(error)
        {
            cout << "error" << '\n';
            continue;
        }

        if(l.size() == 0)
        {
            cout << "[]" << '\n';
            continue;
        }

        cout << '[';

        int tmpLength = l.size();

        for (int j = 0; j < tmpLength - 1; j++)
        {
            if(dir)
            {
                cout << l.front() << ',';
                l.pop_front();
            }
            else
            {
                cout << l.back() << ',';
                l.pop_back();
            }

        }

        if(dir)
            cout << l.front() << ']' << '\n';
        else
            cout << l.back() << ']' << '\n';
    }
}
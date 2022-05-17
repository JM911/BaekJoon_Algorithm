// 11723. 집합
// S5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int myBit = 0;

    int M;
    cin >> M;

    while(M--)
    {
        string com;
        int x;
        int helper = 0;

        cin >> com;

        switch(com[0])
        {
        case 'a':
            if(com[1] == 'd')
            {
                cin >> x;
                helper = 1 << x;
                myBit |= helper;
            }
            else
            {
                myBit = 4194303;
            }
            break;
        case 'r':
            cin >> x;
            helper = (1 << x) ^ 4194303;
            myBit &= helper;
            break;
        case 'c':
            cin >> x;
            helper = myBit & (1 << x);
            if(helper == 0)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
            break;
        case 't':
            cin >> x;
            helper = myBit & (1 << x);
            if(helper == 0)
                myBit |= (1 << x);
            else
                myBit &= (4194303 ^ (1 << x));
            break;
        case 'e':
            myBit = 0;
            break;
        }
    }
}
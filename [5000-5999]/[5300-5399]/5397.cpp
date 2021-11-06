// 5397. 키로거
// S3

#include <bits/stdc++.h>
#define fastio cin.tie(nullptr); ios::sync_with_stdio(false)
using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N;

    while(N--)
    {
        string str;
        cin >> str;

        list<char> l;
        list<char>::iterator iter = l.begin();

        for (int i = 0; i < str.length(); i++)
        {
            switch(str[i])
            {
            case '<':
                if(iter != l.begin())
                    --iter;
                break;
            
            case '>':
                if(iter != l.end())
                    ++iter;
                break;
            
            case '-':
                if(iter != l.begin())
                {
                    --iter;
                    iter = l.erase(iter);
                }
                break;
            
            default:
                l.insert(iter, str[i]);
                break;
            }
        }

        for (iter = l.begin(); iter != l.end(); ++iter)
            cout << *iter;

        cout << '\n';
    }
}
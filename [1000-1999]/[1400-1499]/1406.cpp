// 1406. 에디터
// S3

#include <bits/stdc++.h>
#define fastio cin.tie(nullptr); ios::sync_with_stdio(false)
using namespace std;

int main()
{
    fastio;
    string str;
    cin >> str;

    list<char> l;

    for (int i = 0; i < str.length(); i++)
    {
        l.push_back(str[i]);
    }

    list<char>::iterator iter = l.end();

    int N;
    cin >> N;
    

    while(N--)
    {
        char command;
        cin >> command;
        char plus;
        list<char>::iterator tempIter;

        switch(command)
        {
        case 'L':
            if(iter != l.begin())
                --iter;
            break;

        case 'D':
            if(iter != l.end())
                ++iter;
            break;

        case 'B':
            if(iter == l.begin())
                break;

            tempIter = --iter;
            ++iter;
            l.erase(tempIter);
            break;

        case 'P':
            cin >> plus;
            l.insert(iter, plus);
            break;
        }
    }

    for (iter = l.begin(); iter!=l.end(); ++iter)
        cout << *iter;
}
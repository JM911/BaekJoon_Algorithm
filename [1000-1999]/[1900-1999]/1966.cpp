// 1966. 프린터 큐
// S3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T-- > 0)
    {
        list<int> print;
        typedef list<int>::iterator Iterator;
        typedef list<int>::reverse_iterator RIterator;

        int N, M;
        cin >> N >> M;

        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            print.push_back(temp);
        }

        Iterator tempit = print.begin();
        for (int i = 0; i < M; i++)
        {
            ++tempit;
        }
        int Mpr = (*tempit);
        (*tempit) += 10;

        int eraseCount = 0;
        for (int i = 9; i > Mpr; i--)
        {
            bool check = false;

            for (RIterator rit = print.rbegin(); rit != print.rend(); ++rit)
            {
                if ((*rit) == i)
                {
                    (*rit) += 10;
                    check = true;
                    break;
                }
            }
            
            if (check)
            {
                while ((*print.begin()) != i + 10)
                {
                    Iterator it = print.begin();
                    if ((*it) == i)
                    {
                        print.erase(it);
                        eraseCount++;
                    }
                    else
                    {
                        int temp = (*it);
                        print.pop_front();
                        print.push_back(temp);
                    }
                }
                print.erase(print.begin());
                eraseCount++;
            }
        }

        for (Iterator it = print.begin(); (*it) != Mpr + 10; ++it)
        {
            if ((*it) == Mpr)
                eraseCount++;
        }

        cout << eraseCount + 1 << '\n';
        
    }
    return 0;
}

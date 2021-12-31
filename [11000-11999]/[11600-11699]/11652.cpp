// 11652. 카드
// S4

#include <bits/stdc++.h>
using namespace std;

int N;
map<long long, int> Cards;
long long maxNum;
int maxNumNum;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long tmp;
        cin >> tmp;
        Cards[tmp]++;
    }

    map<long long, int>::iterator iter;

    for (iter = Cards.begin(); iter != Cards.end(); ++iter)
    {
        if(maxNumNum < iter->second)
        {
            maxNum = iter->first;
            maxNumNum = iter->second;
        }
    }

    cout << maxNum;
}
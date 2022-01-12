#include <bits/stdc++.h>
using namespace std;

int N, sum;
pair<int, int> Line[1000010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Line[i].first >> Line[i].second;
    }

    sort(Line, Line + N);

    sum += Line[0].second - Line[0].first;
    int curEnd = Line[0].second;

    for (int i = 1; i < N; i++)
    {
        if(curEnd >= Line[i].second)
            continue;
        
        else if(Line[i].second > curEnd && Line[i].first <= curEnd)
            sum += Line[i].second - curEnd;
        
        else
            sum += Line[i].second - Line[i].first;

        curEnd = Line[i].second;
    }

    cout << sum;
}
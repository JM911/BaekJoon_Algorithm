// 2110. 공유기 설치
// G5

#include "bits/stdc++.h"
using namespace std;

int N, C;
int house[200010];
//int gong[200010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> C;
    for(int i=0; i<N; i++)
    {
        cin >> house[i];
    }

    sort(house, house + N);

    //int ans = (house[N - 1] - house[0]) / (C - 1);
    //gong[0] = house[0];

    int st = 1;
    int en = (house[N - 1] - house[0]) / (C - 1);

    while(st<en)
    {
        int prevIdx = 0;
        int prevHouse = house[0];
        int mid = (st + en + 1) / 2;

        for (int i = 1; i < C; i++)
        {
            prevIdx = lower_bound(house + prevIdx, house + N, prevHouse + mid) - house;

            if(prevIdx >= N)
                break;

            prevHouse = house[prevIdx];
        }

        // if(prevIdx < N)
        //     break;

        if(prevIdx < N)
            st = mid;
        else
            en = mid - 1;
    }

    cout << en;
}
// 12852. 1로 만들기 2
// S1

#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> minOp[1000010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    //minOp[1] = {0, 0};
    minOp[2] = {1, 2};
    minOp[3] = {1, 1};

    for (int i = 4; i <= N; i++)
    {
        if(i%6 == 0)
        {
            if(minOp[i/3] < minOp[i/2] && minOp[i/3] < minOp[i-1])
                minOp[i] = {minOp[i / 3].first + 1, 1};
            else if(minOp[i/2] < minOp[i-1])
                minOp[i] = {minOp[i / 2].first + 1, 2};
            else
                minOp[i] = {minOp[i - 1].first + 1, 3};
        }

        else if(i%3 == 0)
        {
            if(minOp[i/3] < minOp[i-1])
                minOp[i] = {minOp[i / 3].first + 1, 1};
            else
                minOp[i] = {minOp[i - 1].first + 1, 3};
        }

        else if (i % 2 == 0)
        {
            if(minOp[i/2] < minOp[i-1])
                minOp[i] = {minOp[i / 2].first + 1, 2};
            else
                minOp[i] = {minOp[i - 1].first + 1, 3};
        }

        else
        {
            minOp[i] = {minOp[i - 1].first + 1, 3};
        }
    }

    cout << minOp[N].first << '\n';

    while(N != 1)
    {
        cout << N << ' ';
        
        switch(minOp[N].second)
        {
        case 1:
            N /= 3;
            break;
        case 2:
            N /= 2;
            break;
        case 3:
            N--;
            break;
        }
    }

    cout << 1;
}
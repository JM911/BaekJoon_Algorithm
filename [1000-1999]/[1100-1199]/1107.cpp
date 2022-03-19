// 1107. 리모컨
// G5

#include <bits/stdc++.h>
using namespace std;

int N, M;
bool num[10];

bool OnlyNum(int a)
{
    if(a == 0)
        return num[a];

    while(a != 0)
    {
        if(!num[a%10])
            return false;

        a /= 10;
    }

    return true;
}

int RadCount(int a)
{
    int cnt = 1;

    while(a / 10 !=0)
    {
        a /= 10;
        cnt++;
    }

    return cnt;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(num, num + 10, true);

    cin >> N >> M;

    while(M--)
    {
        int tmp;
        cin >> tmp;
        num[tmp] = false;
    }

    int upNum = N;
    int downNum = N;

    while(upNum - N < abs(N-100) && upNum < 1000000)
    {
        if(OnlyNum(upNum))
            break;

        upNum++;
    }

    while(N - downNum < abs(N-100))
    {
        if(downNum < 0)
            break;
        
        if(OnlyNum(downNum))
            break;

        downNum--;
    }

    int ans;

    if(downNum < 0)
        ans = min(RadCount(upNum) + (upNum - N), abs(N - 100));
    else
        ans = min(min(RadCount(upNum) + (upNum - N), RadCount(downNum) + (N - downNum)), abs(N - 100));

    cout << ans;
}
// 11501. 주식
// S2

#include <bits/stdc++.h>
using namespace std;

int T, N;
int price[1000010];
int prevMax;
long long sum;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--)
    {
        cin >> N;
        sum = 0;
        prevMax = 0;

        for (int i = 0; i<N; i++)
        {
            cin >> price[i];
        }

        for (int i = N - 1; i >= 0; i--)
        {
            if(price[i] > prevMax)
                prevMax = price[i];
            else
                sum += (prevMax - price[i]);
        }

        cout << sum << '\n';
    }
}
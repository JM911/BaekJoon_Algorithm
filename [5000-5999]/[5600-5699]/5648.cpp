// 5648. 역원소 정렬
// S4

#include <bits/stdc++.h>
using namespace std;

int n;
long long RevNum[1000010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;

        for (int j = 0; j < 13; j++)
        {
            if(tmp == 0)
                break;
            else
            {
                RevNum[i] *= 10;
                RevNum[i] += tmp % 10;
                tmp /= 10;
            }
        }
    }

    sort(RevNum, RevNum + n);

    for (int i = 0; i < n; i++)
    {
        cout << RevNum[i] << '\n';
    }
}
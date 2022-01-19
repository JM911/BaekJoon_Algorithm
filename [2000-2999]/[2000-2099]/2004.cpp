// 2004. 조합 0의 개수
// S2

#include <bits/stdc++.h>
using namespace std;

int N, M, R;
int fiveN, fiveM, fiveR, fiveTotal;
int twoN, twoM, twoR, twoTotal;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    R = N - M;

    int tmp = N;
    while(tmp)
    {
        tmp /= 5;
        fiveN += tmp;
    }
    tmp = N;
    while(tmp)
    {
        tmp /= 2;
        twoN += tmp;
    }

    tmp = M;
    while(tmp)
    {
        tmp /= 5;
        fiveM += tmp;
    }
    tmp = M;
    while(tmp)
    {
        tmp /= 2;
        twoM += tmp;
    }

    tmp = R;
    while(tmp)
    {
        tmp /= 5;
        fiveR += tmp;
    }
    tmp = R;
    while(tmp)
    {
        tmp /= 2;
        twoR += tmp;
    }

    fiveTotal = fiveN - (fiveM + fiveR);
    twoTotal = twoN - (twoM + twoR);

    cout << min(fiveTotal, twoTotal);
}
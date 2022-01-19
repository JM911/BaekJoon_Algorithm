// 3036. 링
// S3

#include <bits/stdc++.h>
using namespace std;

int N;
int Rad[1010];

int GCDjm(int a, int b)
{
    if(b%a == 0)
        return a;
    return GCDjm(b % a, a);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> Rad[i];
    }

    int firstRad = Rad[0];

    for (int i = 1; i < N; i++)
    {
        int gcdNum = 1;
        if(firstRad > Rad[i])
            gcdNum = GCDjm(Rad[i], firstRad);
        else
            gcdNum = GCDjm(firstRad, Rad[i]);

        cout << firstRad / gcdNum << "/" << Rad[i] / gcdNum << '\n';
    }
}
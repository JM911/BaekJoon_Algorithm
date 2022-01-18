// 1011. Fly me to the Alpha Centauri
// G5

#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--)
    {
        int a, b;
        cin >> a >> b;
        int dist = b - a;

        int count = sqrt(dist - 1) + 1;

        if(dist <= count * (count-1))
            cout << 2 * (count - 1);
        else
            cout << 2 * count - 1;

        cout << '\n';
    }
}
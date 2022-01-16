// 4796. 캠핑
// S5

#include <bits/stdc++.h>
using namespace std;

int L, P, V;

int main()
{
    //cin.tie(nullptr);
    //ios_base::sync_with_stdio(false);

    int count = 1;

    while(true)
    {
        cin >> L >> P >> V;

        if(!L)
            return 0;

        int a = V / P;
        int b = V % P;

        if(b > L)
            b = L;

        cout << "Case " << count++ << ": ";
        cout << (a * L) + b << '\n';
    }
}
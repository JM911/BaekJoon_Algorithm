// 9251. LCS
// G5

#include <bits/stdc++.h>
using namespace std;

string sA, sB;
int d[1010][1010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> sA >> sB;

    int LenA = sA.length();
    int LenB = sB.length();

    for (int i = 0; i < LenB; i++)
    {
        for (int j = 0; j < LenA; j++)
        {
            if(sA[j] == sB[i])
            {
                d[i + 1][j + 1] = d[i][j] + 1;
            }
            else
            {
                d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
            }
        }
    }

    cout << d[LenB][LenA];
}  
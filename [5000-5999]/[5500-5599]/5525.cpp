// 5525. IOIOI
// S2

#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;

string T = "I";
int pi;
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    cin >> S;

    for (int i = 0; i<N; i++)
    {
        T += "OI";
    }

    int j = 0;
    int lenS = M;
    int lenT = 2 * N + 1;

    vector<int> pi(lenT, 0);

    for (int i = 1; i < lenT; i++)
    {
        while(j>0 && T[i] != T[j])
        {
            j = pi[j - 1];
        }

        if(T[i] == T[j])
        {
            j++;
            pi[i] = j;
        }
    }


    j = 0;

    for (int i = 0; i < M; i++)
    {
        while(j>0 && S[i] != T[j])
            j = pi[j - 1];

        if(S[i] == T[j])
        {
            if(j == lenT - 1)
            {
                ans++;
                j = pi[j];
            }
            else
                j++;
        }
    }

    cout << ans;
}
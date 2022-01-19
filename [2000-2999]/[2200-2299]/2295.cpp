// 2295. 세 수의 합
// G4

#include <bits/stdc++.h>
using namespace std;

int N;
int U[1010];
int AddTwo[1000100];
int SubTwo[1000100];
int Origin[1000100];
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> U[i];
    }

    //sort(U, U + N);

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            AddTwo[count] = U[i] + U[j];
            SubTwo[count] = U[i] - U[j];
            Origin[count] = U[i];
            count++;
        }
    }

    sort(AddTwo, AddTwo + count);

    for (int i = 0; i < count; i++)
    {
        if(binary_search(AddTwo, AddTwo + count, SubTwo[i]))
            ans = max(ans, Origin[i]);
    }

    cout << ans;
}
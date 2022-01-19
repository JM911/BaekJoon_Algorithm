// 18870. 좌표 압축
// S2

#include <bits/stdc++.h>
using namespace std;

int N;
int X[1000010];
int Y[1000010];
vector<int> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        X[i] = tmp;
        Y[i] = tmp;
    }

    sort(X, X + N);

    v.push_back(X[0]);

    for(int i=1; i<N; i++)
    {
        if(X[i] == X[i-1])
            continue;

        v.push_back(X[i]);
    }

    for (int i = 0; i < N; i++)
    {
        cout << lower_bound(v.begin(), v.end(), Y[i]) - v.begin() << ' ';
    }
}
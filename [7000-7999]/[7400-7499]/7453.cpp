// 7453. 합이 0인 네 정수
// G2

#include "bits/stdc++.h"
using namespace std;

int n;
long long A[4010];
long long B[4010];
long long C[4010];
long long D[4010];

long long tmp;

long long ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        cin >> B[i];
        cin >> C[i];
        cin >> D[i];
    }

    vector<long long> AB;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AB.push_back(A[i] + B[j]);
        }
    }

    sort(AB.begin(), AB.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp = -C[i] - D[j];

            ans += upper_bound(AB.begin(), AB.end(), tmp) - lower_bound(AB.begin(), AB.end(), tmp);
        }
    }

    cout << ans;
}
#include "bits/stdc++.h"
using namespace std;

int AN, BN;
int A[500010];
int B[500010];
int count;
vector<int> vecAns;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> AN >> BN;

    for (int i = 0; i < AN; i++)
        cin >> A[i];
    for (int i = 0; i < BN; i++)
        cin >> B[i];

    sort(B, B + BN);

    for (int i = 0; i < AN; i++)
    {
        if(!binary_search(B, B+BN, A[i]))
            vecAns.push_back(A[i]);
    }

    sort(vecAns.begin(), vecAns.end());

    cout << vecAns.size() << '\n';

    for (size_t i = 0; i < vecAns.size(); i++)
        cout << vecAns[i] << ' ';
}
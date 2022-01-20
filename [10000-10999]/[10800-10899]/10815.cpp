// 10815. 숫자 카드
// S4

#include "bits/stdc++.h"
using namespace std;

int N, M;
int card[500010];
int target[500010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> card[i];

    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> target[i];

    sort(card, card + N);

    for (int i = 0; i < M; i++)
        cout << binary_search(card, card + N, target[i]) << ' ';
}
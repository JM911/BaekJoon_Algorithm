// 1149. RGB 거리
// S1

#include <bits/stdc++.h>
using namespace std;

int N;
tuple<int, int, int> ColorCost[1010];
int minCostAndLastColor[1010][5];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        ColorCost[i] = {r, g, b};
    }

    minCostAndLastColor[1][1] = get<0>(ColorCost[1]);
    minCostAndLastColor[1][2] = get<1>(ColorCost[1]);
    minCostAndLastColor[1][3] = get<2>(ColorCost[1]);

    for (int i = 2; i <= N; i++)
    {
        minCostAndLastColor[i][1] = min(minCostAndLastColor[i - 1][2], minCostAndLastColor[i - 1][3]) + get<0>(ColorCost[i]);
        minCostAndLastColor[i][2] = min(minCostAndLastColor[i - 1][1], minCostAndLastColor[i - 1][3]) + get<1>(ColorCost[i]);
        minCostAndLastColor[i][3] = min(minCostAndLastColor[i - 1][1], minCostAndLastColor[i - 1][2]) + get<2>(ColorCost[i]);
    }

    int ans = min(min(minCostAndLastColor[N][1], minCostAndLastColor[N][2]), minCostAndLastColor[N][3]);

    cout << ans;
}
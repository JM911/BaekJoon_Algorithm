// 15686. 치킨 배달
// G5

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

//int townMap[60][60];
int N, M;
pair<int, int> chicken[15];
pair<int, int> chickenM[15];
pair<int, int> house[120];
int houseNum, chickenNum;
int minChickenDist = INT_MAX;
int prevNum = -1;

void PickChicken(int len)
{
    if(len == M)
    {
        int sum = 0;
        for (int i = 0; i < houseNum; i++)
        {
            int tempMin = INT_MAX;

            for (int j = 0; j < M; j++)
            {
                int tempDist = abs(house[i].first - chickenM[j].first) + abs(house[i].second - chickenM[j].second);
                tempMin = min(tempMin, tempDist);
            }

            sum += tempMin;
        }

        minChickenDist = min(minChickenDist, sum);
        return;
    }

    for (int i = prevNum + 1; i < chickenNum; i++)
    {
        chickenM[len] = chicken[i];
        prevNum = i;
        PickChicken(len + 1);
    }
}

int main()
{
    fastio;
    cin >> N >> M;
    int temp;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> temp;
            if(temp == 1)
                house[houseNum++] = {i, j};
            if(temp == 2)
                chicken[chickenNum++] = {i, j};
        }
    }

    PickChicken(0);

    cout << minChickenDist;
}
// 14889. 스타트와 링크
// S3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
int abilityPoint[25][25];
int minSub = INT_MAX;
vector<bool> permutationTool;

int main()
{
    fastio;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> abilityPoint[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if(i < N / 2)
            permutationTool.push_back(false);
        else
            permutationTool.push_back(true);
    }

    do
    {
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(permutationTool[i] == true && permutationTool[j] == true)
                    sum1 += abilityPoint[i][j];
                else if(permutationTool[i] == false && permutationTool[j] == false)
                    sum2 += abilityPoint[i][j];
            }
        }

        int subAbility = abs(sum1 - sum2);

        minSub = min(minSub, subAbility);

    } while (next_permutation(permutationTool.begin(), permutationTool.end()));

    cout << minSub;
}
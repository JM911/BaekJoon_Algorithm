// 1644. 소수의 연속합
// G3

#include "bits/stdc++.h"
using namespace std;

int N;
bool isVisited[4000010];
vector<int> PNum;
int ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    if(N==1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 2; i <= N; i++)
    {
        if(isVisited[i])
            continue;

        PNum.push_back(i);

        for (int j = 1; j * i <= N; j++)
        {
            isVisited[j * i] = true;
        }
    }

    int sum = PNum[0];
    int leftIdx = 0;
    int rightIdx = 0;

    while(N >= PNum[leftIdx])
    {
        if(sum==N)
        {
            ans++;
            rightIdx++;

            if(rightIdx >= PNum.size())
                break;

            sum += PNum[rightIdx];
        }

        else if(sum > N)
        {
            sum -= PNum[leftIdx];
            leftIdx++;
        }

        else
        {
            if(rightIdx >= PNum.size() - 1)
                break;

            rightIdx++;
            sum += PNum[rightIdx];
        }
    }

    cout << ans;
}
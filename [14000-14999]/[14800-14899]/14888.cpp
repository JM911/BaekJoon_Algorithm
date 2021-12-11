// 14888. 연산자 끼워넣기
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
int nums[13];
//int plusOp, minusOp, mulOp, divOp;
int OperNum[4];
int minResult = INT_MAX;
int maxResult = INT_MIN;

void Operating(int operand, int len)
{
    if(len == N)
    {
        minResult = min(minResult, operand);
        maxResult = max(maxResult, operand);
        return;
    }

    for (int idx = 0; idx < 4; idx++)
    {
        if(OperNum[idx] == 0)
            continue;

        int newOperand;

        switch(idx)
        {
        case 0:
            newOperand = operand + nums[len];
            break;
        case 1:
            newOperand = operand - nums[len];
            break;
        case 2:
            newOperand = operand * nums[len];
            break;
        case 3:
            newOperand = operand / nums[len];
            break;
        }
        OperNum[idx]--;
        Operating(newOperand, len + 1);
        OperNum[idx]++;
    }
}

int main()
{
    fastio;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> OperNum[i];
    }

    Operating(nums[0], 1);

    cout << maxResult << '\n'
         << minResult;
}
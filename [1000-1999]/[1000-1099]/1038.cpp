// 1038. 감소하는 수
// G5

#include <bits/stdc++.h>
using namespace std;

vector<long long> decNum;
queue<long long> newDecNum;
int N;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    decNum.push_back(0);

    for (int i = 1; i <= 9; i++)
    {
        decNum.push_back(i);
        newDecNum.push(i);
    }

    bool isContinuing = true;

    while(!newDecNum.empty())
    {
        long long prevNum = newDecNum.front();
        long long lastNum = prevNum % 10;

        newDecNum.pop();

        if(lastNum == 0)
            continue;

        isContinuing = true;

        for (int j = 0; j < lastNum; j++)
        {
            long long newNum = prevNum * 10 + j;
            decNum.push_back(newNum);
            newDecNum.push(newNum);
        }
    }

    sort(decNum.begin(), decNum.end());

    cin >> N;

    if(N < decNum.size())
        cout << decNum[N];
    else
        cout << -1;
}
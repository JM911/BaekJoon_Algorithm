// 1744. 수 묶기
// G4

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> posNum;
vector<int> negNum;
bool isVisitedPos[55];
bool isVisitedNeg[55];
bool isZeroExist;
int sum;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        if(tmp > 0)
            posNum.push_back(tmp);
        else if(tmp < 0)
            negNum.push_back(tmp);
        else
            isZeroExist = true;
    }

    sort(posNum.begin(), posNum.end(), greater<int>());
    sort(negNum.begin(), negNum.end());

    int posLen = posNum.size();
    int negLen = negNum.size();

    for (int i = 0; i < posLen - 1; i++)
    {
        if(isVisitedPos[i])
            continue;

        if(posNum[i] == 1 || posNum[i+1] == 1)
        {
            sum += posNum[i];
            isVisitedPos[i] = true;
            continue;
        }

        sum += posNum[i] * posNum[i + 1];
        isVisitedPos[i] = true;
        isVisitedPos[i+1] = true;
    }

    if(posLen > 0 && !isVisitedPos[posNum.size()-1])
        sum += posNum[posNum.size() - 1];


    for (int i = 0; i < negLen - 1; i++)
    {
        if(isVisitedNeg[i])
            continue;

        sum += negNum[i] * negNum[i + 1];
        isVisitedNeg[i] = true;
        isVisitedNeg[i+1] = true;
    }

    if(negLen > 0 && !isVisitedNeg[negNum.size()-1] && !isZeroExist)
        sum += negNum[negNum.size() - 1];

    cout << sum;
}
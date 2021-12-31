// 2910. 빈도 정렬
// S3

#include "bits/stdc++.h"
using namespace std;

int N, C;
vector<pair<int, int>> vecNum;
pair<int, int> tmpArr[1050];

void MergeSort(int st, int en)
{
    int mid = (st + en) / 2;
    int i = st;
    int j = mid + 1;
    int k = st;

    while(i<=mid && j<=en)
    {
        if(vecNum[i].second >= vecNum[j].second)
            tmpArr[k++] = vecNum[i++];
        else
            tmpArr[k++] = vecNum[j++];
    }

    if(i > mid)
    {
        while(j<=en)
            tmpArr[k++] = vecNum[j++];
    }
    else
    {
        while(i<=mid)
            tmpArr[k++] = vecNum[i++];
    }

    for (int t = st; t <= en; t++)
    {
        vecNum[t] = tmpArr[t];
    }
}

void Merge(int st, int en)
{
    if(st >= en)
        return;

    int mid = (st + en) / 2;

    Merge(st, mid);
    Merge(mid + 1, en);
    MergeSort(st, en);
}

int main()
{
    //cin.tie(nullptr);
    //ios_base::sync_with_stdio(false);

    cin >> N >> C;

    vector<pair<int, int>>::iterator iter;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        for (iter = vecNum.begin(); iter != vecNum.end(); ++iter)
        {
            if(tmp == iter->first)
            {
                iter->second++;
                break;
            }
        }

        if (iter == vecNum.end())
        {
            vecNum.push_back({tmp, 1});
        }
    }

    Merge(0, vecNum.size());

    for (iter = vecNum.begin(); iter != vecNum.end(); ++iter)
    {
        for (int i = 0; i < iter->second; i++)
        {
            cout << iter->first << ' ';
        }
    }
}
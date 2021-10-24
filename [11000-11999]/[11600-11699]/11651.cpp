// 11651. 좌표 정렬하기 2
// S5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<pair<int, int>>* arr, int start, int mid, int end)
{
    vector<pair<int, int>> sortVec;

    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if ((*arr)[i].second < (*arr)[j].second)
            sortVec.push_back((*arr)[i++]);
        else if ((*arr)[i].second > (*arr)[j].second)
            sortVec.push_back((*arr)[j++]);
        else if ((*arr)[i].first < (*arr)[j].first)
            sortVec.push_back((*arr)[i++]);
        else
            sortVec.push_back((*arr)[j++]);
    }

    if (i > mid)
    {
        while(j<=end)
            sortVec.push_back((*arr)[j++]);
    }
    else
    {
        while(i<=mid)
            sortVec.push_back((*arr)[i++]);
    }

    for (int t = start; t <= end; t++)
    {
        (*arr)[t] = sortVec[t - start];
    }
}

void MergeSort(vector<pair<int, int>>* arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

int main()
{
    int N;
    cin >> N;
    pair<int, int> temp;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &temp.first, &temp.second);
        v.push_back(temp);
    }

    MergeSort(&v, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}

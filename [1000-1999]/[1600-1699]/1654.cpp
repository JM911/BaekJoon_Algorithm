// 1654. 랜선 자르기
// S3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long MyMax(long long* arr, int len)
{
    long long max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

long long MyBSearch(long long* arr, int len, long long goal, long long start, long long end)
{
    if (start < end)
    {
        long long mid = (start + end) / 2;
        long long sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += arr[i] / mid;
        }

        if (sum < goal)
            return MyBSearch(arr, len, goal, start, mid);
        else
            return MyBSearch(arr, len, goal, mid + 1, end);
    }
    
    else
    {
        long long sum = 0;

        for (int i = 0; i < len; i++)
        {
            sum += arr[i] / end;
        }

        if (sum == goal)
            return end;
        else
            return end - 1;
    }
}

int main()
{
    int K;
    long long N;
    cin >> K >> N;

    long long* LanLen = new long long[K];
    float sum = 0;

    for (int i = 0; i < K; i++)
    {
        scanf("%lld", &LanLen[i]);
    }

    cout << MyBSearch(LanLen, K, N, 1, MyMax(LanLen, K));


    delete[] LanLen;

    return 0;
}

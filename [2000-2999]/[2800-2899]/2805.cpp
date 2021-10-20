// 2805. 나무 자르기
// S3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long HMax(long long* arr, int len, int goal, long long start, long long end)
{
    if (start < end)
    {
        long long mid1 = (start + end) / 2;
        long long mid2 = mid1 + 1;
        long long sum1 = 0;
        long long sum2 = 0;

        for (int i = 0; i < len; i++)
        {
            long long temp1 = arr[i] - mid1;
            long long temp2 = arr[i] - mid2;
            if (temp1 > 0)
                sum1 += temp1;
            if (temp2 > 0)
                sum2 += temp2;
        }

        if (sum1 < goal && sum2 >= goal)
            return mid2;
        else if (sum1 >= goal)
            return HMax(arr, len, goal, mid2, end);
        else
            return HMax(arr, len, goal, start, mid1);

    }

    else
    {
        return end-1;
    }
}


int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    long long* trees = new long long[N];

    for (int i = 0; i < N; i++)
        scanf("%lld", &trees[i]);

    long long ans = HMax(trees, N, M, 0, 2000 * 1000 * 1000);

    cout << ans;

    delete[] trees;

    return 0;
}

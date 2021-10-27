// 18111. 마인크래프트
// S3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int ground[500][500];

int TimeForWork(int arr[][500], int N, int M, int goal)
{
    int time = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] < goal)
                time += (goal - arr[i][j]);
            else
                time += (arr[i][j] - goal) * 2;
        }
    }

    return time;
}

int main()
{
    int N, M, B;
    cin >> N >> M >> B;

    int min = 256;
    int max = 0;
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &ground[i][j]);
            if (min > ground[i][j])
                min = ground[i][j];
            if (max < ground[i][j])
                max = ground[i][j];
            sum += ground[i][j];
        }
    }

    int temp_Max = (sum + B) / (N * M);
    if (max > temp_Max)
        max = temp_Max;

    int time_min = TimeForWork(ground, N, M, max);
    int temp;
    int height = max;

    for (int i = max-1; i >= min; i--)
    {
        temp = TimeForWork(ground, N, M, i);
        if (time_min > temp)
        {
            time_min = temp;
            height = i;
        }
    }

    cout << time_min << ' ' << height;

    return 0;
}

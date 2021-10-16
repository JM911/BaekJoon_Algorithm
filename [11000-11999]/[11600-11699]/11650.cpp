// 11650. 좌표 정렬하기
// S5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void MergeXY(int* x, int* y, int start, int mid, int end)
{
    int* sort_x = new int[end - start + 1];
    int* sort_y = new int[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (x[i] < x[j])
        {
            sort_x[k] = x[i];
            sort_y[k] = y[i];
            i++;
        }
        else if (x[i] > x[j])
        {
            sort_x[k] = x[j];
            sort_y[k] = y[j];
            j++;
        }
        else if (y[i] < y[j])
        {
            sort_x[k] = x[i];
            sort_y[k] = y[i];
            i++;
        }
        else
        {
            sort_x[k] = x[j];
            sort_y[k] = y[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= end)
        {
            sort_x[k] = x[j];
            sort_y[k] = y[j];
            j++;
            k++;
        }
    }

    else
    {
        while (i <= mid)
        {
            sort_x[k] = x[i];
            sort_y[k] = y[i];
            i++;
            k++;
        }
    }

    for (int t = start; t <= end; t++)
    {
        x[t] = sort_x[t-start];
        y[t] = sort_y[t-start];
    }

    delete[] sort_x;
    delete[] sort_y;
}

void MergeSortXY(int* x, int* y, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSortXY(x, y, start, mid);
        MergeSortXY(x, y, mid + 1, end);
        MergeXY(x, y, start, mid, end);
    }
}

int main()
{
    int N;
    cin >> N;

    int* x = new int[N];
    int* y = new int[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        //cin >> x[i] >> y[i];
    }

    MergeSortXY(x, y, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        cout << x[i] << ' ' << y[i] << '\n';
    }

    delete[] x;
    delete[] y;

    return 0;
}

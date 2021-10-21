// 7568.덩치
// S5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int w[50] = { };
    int h[50] = { };

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &w[i], &h[i]);
    }

    int rank[50] = { };
    for (int i = 0; i < N; i++)
    {
        int temp = 0;
        for (int j = 0; j < N; j++)
        {
            if (j == i)
                continue;
            else
            {
                if (w[i] < w[j] && h[i] < h[j])
                    temp++;
            }
        }
        rank[i] = temp + 1;
    }

    for (int i = 0; i < N; i++)
        cout << rank[i] << ' ';

    return 0;
}

// 2775. 부녀회장이 될테야
// B2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main()
{
    int arr[15][15] = { };
    
    for (int i = 1; i <= 14; i++)
        arr[0][i] = i;

    for (int i = 1; i <= 14; i++)
    {
        for (int j = 1; j <= 14; j++)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }

    int T;
    cin >> T;

    while (T-- > 0)
    {
        int k, n;
        scanf("%d %d", &k, &n);
        
        cout << arr[k][n] << '\n';
    }

    return 0;
}

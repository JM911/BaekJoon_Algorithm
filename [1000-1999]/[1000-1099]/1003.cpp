// 1003. 피보나치 함수
// S3

#include <iostream>
using namespace std;

int farr[41];

int main()
{
    farr[0] = 0;
    farr[1] = 1;
    for(int i=2; i<=40; i++)
    {
        farr[i] = farr[i-1] + farr[i-2];
    }

    int T;
    scanf("%d", &T);

    while(T--)
    {
        int N;
        scanf("%d", &N);

        if(N==0)
            cout << 1 << ' ' << 0 << '\n';

        else
            cout << farr[N-1] << ' ' << farr[N] << '\n';
    }

    return 0;
}

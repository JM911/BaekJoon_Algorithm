// 2292. 벌집
// B2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long n = N - 1;

    long long count = 0;
    long long stair = 0;

    while (true)
    {
        if (n <= stair * 6)
            break;
        
        count++;
        stair += count;
    }

    cout << count + 1;

    return 0;
}

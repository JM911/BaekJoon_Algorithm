// 1463. 1로 만들기
// S3

#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

int main()
{
    int temp;

    arr[1] = 0;
    for(int i=2; i<=1000000; i++)
    {
        temp = i%6;

        switch(temp)
        {
        case 1:
        case 5:
            arr[i] = arr[i-1] + 1;
            break;
        case 2:
        case 4:
            arr[i] = min(arr[i-1], arr[i/2]) + 1;
            break;
        case 3:
            arr[i] = min(arr[i-1], arr[i/3]) + 1;
            break;
        case 0:
            arr[i] = min(arr[i/3], arr[i/2]) + 1;
            break;
        }
    }

    int N;

    cin >> N;
    cout << arr[N];

    return 0;
}

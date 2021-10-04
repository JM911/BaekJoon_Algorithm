// 1292. 쉽게 푸는 문제
// S5

#include <iostream>
using namespace std;

int TotalSum(int a)
{
    int sum = 0;
    for (int i = 1; i <= a; i++)
        sum += i;

    return sum;
}

int main()
{
    int arr[1000];
    int startIndex, endIndex;
    cin >> startIndex >> endIndex;

    for (int i = 0; i < 1000; i++)
    {
        int num = 1;

        while ((i + 1) > TotalSum(num))
        {
            num++;
        }
        
        arr[i] = num;
    }

    int sum = 0;

    for (int i = startIndex - 1; i <= endIndex - 1; i++)
        sum += arr[i];

    cout << sum;

    return 0;
}
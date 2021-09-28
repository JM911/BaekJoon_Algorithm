// 1434. 책 정리
// B2

#include <iostream>
using namespace std;

int boxSum(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int boxNum, bookNum;
    int count = 0;

    cin >> boxNum >> bookNum;
    int box[50] = { 0, };
    int book[50] = { 0, };

    for (int i = 0; i < boxNum; i++)
    {
        cin >> box[i];
    }

    for (int i = 0; i < bookNum; i++)
    {
        cin >> book[i];
    }

    for (int i = 0; i < boxNum; i++)
    {
        while (box[i] >= book[count] && count != bookNum)
        {
            box[i] -= book[count];
            count++;
        }
    }

    cout << boxSum(box, boxNum);

    return 0;
}
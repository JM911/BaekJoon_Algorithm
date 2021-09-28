// 2605. 줄 세우기
// B2

#include <iostream>
using namespace std;

int main()
{
    int student[100] = { };
    int number[100] = { };
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> number[i];
    }

    student[0] = 1;

    for (int i = 1; i < N; i++)
    {
        for (int j = i - 1; j >= i-number[i]; j--)
        {
            student[j+1] = student[j];
        }
        student[i - number[i]] = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        cout << student[i] << ' ';
    }

    return 0;
}
// 1977. 완전제곱수
// B1

#include <iostream>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    int arr[100] = { };
    int count = 0;
    int sum = 0;

    for (int i = M; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j * j == i)
            {
                arr[count] = i;
                sum += i;
                count++;
                break;
            }
        }
    }

    if (arr[0] == 0)
        cout << -1;

    else
    {
        cout << sum << endl;
        cout << arr[0];
    }

    return 0;
}
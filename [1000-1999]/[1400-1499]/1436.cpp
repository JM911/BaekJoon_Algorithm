// 1436. 영화감독 숌
// S5

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int x = 100;
    int count = 0;

    while (count < N)
    {
        x++;
        string x_str = to_string(x);
        for (int i = 0; i < x_str.length() - 2; i++)
        {
            if (x_str[i] == '6' && x_str[i + 1] == '6' && x_str[i + 2] == '6')
            {
                count++;
                break;
            }
        }
    }

    cout << x;

    return 0;
}
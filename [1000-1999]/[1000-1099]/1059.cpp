// 1059. 좋은 구간
// S5

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int L;
    cin >> L;
    int temp;

    vector<int> S(L + 1, 0);

    for (int i = 0; i < L; i++)
    {
        cin >> temp;
        S[i]=temp;
    }

    for (int i = 0; i < L - 1; i++)
    {
        for (int j = i + 1; j < L; j++)
        {
            if (S[i] > S[j])
            {
                int temp2 = S[i];
                S[i] = S[j];
                S[j] = temp2;
            }
        }
    }

    int n;
    cin >> n;
    int count = 0;

    if (n == 1)
    {
        if (S[0] <= 2)
        {
            cout << 0;
            return 0;
        }
        else
        {
            cout << S[0] - 2;
            return 0;
        }
    }

    else if (n<S[0])
    {
        cout << n * (S[0] - n) - 1;
        return 0;
    }

    while (true)
    {
        if (S[count] >= n)
            break;
        count++;
    }

    if (S[count] == n)
        cout << 0;
    else
    {
        cout << (n - S[count-1]) * (S[count] - n) - 1;
    }

    return 0;
}
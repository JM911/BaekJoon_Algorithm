// 1343. 폴리오미노
// S5

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char goal[501];
    char ans[501];

    cin >> goal;

    int len = strlen(goal);

    int count = 0;
    int temp = 0;
    int tempIndex = 0;

    while (goal[count] != '\0')
    {
        if (goal[count] == '.')
        {
            ans[count] = '.';
            count++;
            continue;
        }

        else if (goal[count] == 'X')
        {
            tempIndex = count;

            while (goal[count] == 'X')
            {
                count++;
            }

            temp = count - tempIndex;

            if (temp % 2 == 1)
            {
                cout << -1;
                return 0;
            }

            else if (temp % 4 == 0)
            {
                for (int i = tempIndex; i < count; i++)
                {
                    ans[i] = 'A';
                }
            }

            else if (temp % 4 == 2)
            {
                for (int i = tempIndex; i < count - 2; i++)
                {
                    ans[i] = 'A';
                }
                ans[count - 2] = 'B';
                ans[count - 1] = 'B';
            }
        }
    }

    ans[len] = '\0';

    cout << ans;

    return 0;
}
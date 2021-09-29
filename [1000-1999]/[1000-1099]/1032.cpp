// 1032. 명령 프롬프트
// B1

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 1;

    char file[60] = { };
    char ans[60] = { };

    cin >> ans;

    while (count < N)
    {
        cin >> file;

        int strMax = strlen(ans);
        if (strlen(ans) < strlen(file))
        {
            strMax=strlen(file);
        }

        for (int i = 0; i < strMax; i++)
        {
            if (ans[i] == file[i])
            {
                ans[i] = file[i];
            }
            else
            {
                ans[i] = '?';
            }
        }

        count++;
    }

    cout << ans;

    return 0;
}
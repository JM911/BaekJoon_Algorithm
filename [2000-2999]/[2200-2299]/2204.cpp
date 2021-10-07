// 2204. 도비의 난독증 테스트
// S5

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n != 0)
    {
        string* strArr = new string[n];
        string* copyArr = new string[n];

        for (int i = 0; i < n; i++)
        {
            cin >> strArr[i];
            copyArr[i] = strArr[i];
            
            for (int j = 0; j < copyArr[i].size(); j++)
            {
                if (copyArr[i][j] > 96)
                    copyArr[i][j] -= 32;
            }
        }

        int maxIndex = 0;

        for (int i = 1; i < n; i++)
        {
            int a = copyArr[maxIndex].compare(copyArr[i]);
            if (a > 0)
                maxIndex = i;
        }

        cout << strArr[maxIndex] << endl;


        delete[] copyArr;
        delete[] strArr;

        cin >> n;
    }
    return 0;
}
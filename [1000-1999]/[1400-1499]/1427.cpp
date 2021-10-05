// 1427. 소트인사이드
// S5

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char num[11];
    cin >> num;

    int len = strlen(num);

    for (int i = 0; i < len-1; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (num[i] < num[j])
            {
                char temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    cout << num;

    return 0;
}
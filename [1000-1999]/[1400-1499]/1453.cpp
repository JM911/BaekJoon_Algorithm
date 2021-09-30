// 1453. 피시방 알바
// B1

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int arr[100] = { };
    int temp[100];
    int count = 0;
    int refuseNum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> temp[i];
    }

    for (int i = 0; i < N; i++)
    {       
        if (count == 0)
        {
            arr[count] = temp[i];
            count++;
            continue;
        }

        for (int j = 0; j < count; j++)
        {
            if (arr[j] == temp[i])
            {
                refuseNum++;
                break;
            }
        }

        arr[count] = temp[i];
        count++;
    }

    cout << refuseNum;
    

    return 0;
}
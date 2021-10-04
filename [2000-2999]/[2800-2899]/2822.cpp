// 2822. 점수 계산
// S5

#include <iostream>
using namespace std;

int maxIndex;

int Max(int arr[], int len)
{
    int max = 0;

    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            maxIndex = i;
        }
    }

    return max;
}

void Sort(int arr[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int score[8];
    int highIndex[5];
    int sum = 0;

    for (int i = 0; i < 8; i++)
        cin >> score[i];

    for (int i = 0; i < 5; i++)
    {
        sum += Max(score, 8);
        highIndex[i] = maxIndex;
        score[maxIndex] = 0;
    }

    Sort(highIndex, 5);
    
    cout << sum << endl;
    for (int i = 0; i < 5; i++)
        cout << highIndex[i]+1 << ' ';


    return 0;
}
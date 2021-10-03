// 1316. 그룹 단어 체커
// S5

#include <iostream>
#include <cstring>
using namespace std;

bool isGWord(char arr[101], int len)
{
    for (int i = 0; i < 26; i++)
    {
        int count = 0;
        int minIndex = 99;
        int maxIndex = 0;
        
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == 'a' + i)
            {
                if (j < minIndex)
                    minIndex = j;
                if (j > maxIndex)
                    maxIndex = j;

                count++;
            }
        }
        if (maxIndex - minIndex + 1 != count && count !=0)
            return false;
    }

    return true;
}

int main()
{
    int N;
    cin >> N;
    
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        char word[101];
        cin >> word;

        if (isGWord(word, strlen(word)))
            count++;
    }
    
    cout << count;
    
    return 0;
}
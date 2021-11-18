// 1181. 단어 정렬
// S5

#include <iostream>
#include <string>
using namespace std;

void MergeSort(string sarr[], int len)
{
    if (len == 1)
    {
        return;
    }
    int len1 = len / 2;
    int len2 = len - len1;

    string* copy1 = new string[len1];
    string* copy2 = new string[len2];

    for (int i = 0; i < len1; i++)
    {
        copy1[i] = sarr[i];
        copy2[i] = sarr[len1 + i];
    }
    copy2[len2 - 1] = sarr[len - 1];

    MergeSort(copy1, len1);
    MergeSort(copy2, len2);

    int count1 = 0;
    int count2 = 0;

    while (count1 < len1 || count2 < len2)
    {
        if (count1 == len1)
        {
            sarr[count1 + count2] = copy2[count2];
            count2++;
        }

        else if (count2 == len2)
        {
            sarr[count1 + count2] = copy1[count1];
            count1++;
        }

        else if (copy1[count1].size() > copy2[count2].size())
        {
            sarr[count1 + count2] = copy2[count2];
            count2++;
        }

        else if (copy1[count1].size() < copy2[count2].size())
        {
            sarr[count1 + count2] = copy1[count1];
            count1++;
        }

        else if (copy1[count1].compare(copy2[count2]) < 0)
        {
            sarr[count1 + count2] = copy1[count1];
            count1++;
        }

        else /*if (copy1[count1].compare(copy2[count2]) > 0)*/
        {
            sarr[count1 + count2] = copy2[count2];
            count2++;
        }
        /*
        else
        {
            sarr[count1 + count2] = copy2[count2];
            sarr[count1 + count2 + 1] = "0";
            count1++;
            count2++;
        }*/
    }

    delete[] copy1;
    delete[] copy2;
}

int main()
{
    int N;
    cin >> N;
    string* arr = new string[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    if (N == 1)
    {
        cout << arr[0];
        delete[] arr;
        return 0;
    }

    else
    {
        MergeSort(arr, N);

        for (int i = 0; i < N; i++)
        {
            if (i == 0)
                cout << arr[0] << '\n';
            else if(i>0 && arr[i].compare(arr[i-1]))
                cout << arr[i] << '\n';
        }

        delete[] arr;
    }
    
    return 0;
}
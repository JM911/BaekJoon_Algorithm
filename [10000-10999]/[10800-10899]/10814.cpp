// 10814. 나이순 정렬
// S5

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct _MEMBER_INFO
{
    int age;
    int num;
    char name[101];
} MemInfo;

void MergeSort(vector<MemInfo>& v, int len)
{
    if (len == 1)
        return;

    int len1 = len / 2;
    int len2 = len - len1;

    vector<MemInfo> copy1(len1);
    vector<MemInfo> copy2(len2);

    for (int i = 0; i < len1; i++)
    {
        copy1[i].age = v[i].age;
        copy1[i].num = v[i].num;
        strcpy(copy1[i].name, v[i].name);
    }

    for (int i = 0; i < len2; i++)
    {
        copy2[i].age = v[len1 + i].age;
        copy2[i].num = v[len1 + i].num;
        strcpy(copy2[i].name, v[len1 + i].name);
    }

    MergeSort(copy1, len1);
    MergeSort(copy2, len2);

    int count1 = 0;
    int count2 = 0;

    while (count1 + count2 < len)
    {
        if (count1 == len1)
        {
            v[count1 + count2].age = copy2[count2].age;
            v[count1 + count2].num = copy2[count2].num;
            strcpy(v[count1 + count2].name, copy2[count2].name);
            count2++;
        }

        else if (count2 == len2)
        {
            v[count1 + count2].age = copy1[count1].age;
            v[count1 + count2].num = copy1[count1].num;
            strcpy(v[count1 + count2].name, copy1[count1].name);
            count1++;
        }

        else if (copy1[count1].age < copy2[count2].age)
        {
            v[count1 + count2].age = copy1[count1].age;
            v[count1 + count2].num = copy1[count1].num;
            strcpy(v[count1 + count2].name, copy1[count1].name);
            count1++;
        }

        else if (copy1[count1].age > copy2[count2].age)
        {
            v[count1 + count2].age = copy2[count2].age;
            v[count1 + count2].num = copy2[count2].num;
            strcpy(v[count1 + count2].name, copy2[count2].name);
            count2++;
        }

        else if (copy1[count1].num < copy2[count2].num)
        {
            v[count1 + count2].age = copy1[count1].age;
            v[count1 + count2].num = copy1[count1].num;
            strcpy(v[count1 + count2].name, copy1[count1].name);
            count1++;
        }

        else
        {
            v[count1 + count2].age = copy2[count2].age;
            v[count1 + count2].num = copy2[count2].num;
            strcpy(v[count1 + count2].name, copy2[count2].name);
            count2++;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vector<MemInfo> v(N);
    int count = 1;

    for (int i = 0; i < N; i++)
    {
        int age;
        char name[101];
        cin >> age >> name;

        v[i].age = age;
        v[i].num = count;
        strcpy(v[i].name, name);
        
        count++;
    }

    MergeSort(v, N);

    for (int i = 0; i < N; i++)
    {
        printf("%d %s\n", v[i].age, v[i].name);
    }

    return 0;
}
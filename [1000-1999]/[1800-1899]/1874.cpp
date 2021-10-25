// 1874. 스택 수열
// S3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    stack<int> s;
    vector<char> exp;
    int temp = 0;
    bool isPossible = true;

    for (int j = 0; j < N; j++)
    {
        if (j == 0)
        {
            scanf("%d", &temp);
            for (int i = 1; i <= temp; i++)
            {
                s.push(i);
                exp.push_back('+');
            }
            s.pop();
            exp.push_back('-');
        }

        else
        {
            int x;
            scanf("%d", &x);

            if (x <= temp)
            {
                if (s.top() == x)
                {
                    s.pop();
                    exp.push_back('-');
                }
                else
                {
                    isPossible = false;
                }
            }

            else
            {
                for (int i = temp + 1; i <= x; i++)
                {
                    s.push(i);
                    exp.push_back('+');
                }
                s.pop();
                exp.push_back('-');

                temp = x;
            }
        }
    }

    while (!s.empty())
        s.pop();

    if (isPossible == false)
        printf("NO");
    else
    {
        for (int i = 0; i<exp.size(); i++)
        {
            printf("%c\n", exp[i]);
        }
    }

    return 0;
}

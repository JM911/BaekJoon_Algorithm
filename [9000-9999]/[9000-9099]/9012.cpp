// 9012. 괄호
// S4

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        int count1 = 0;
        int count2 = 0;

        for (int j = 0; j < s.length(); j++)
        {
            switch (s[j])
            {
            case '(':
                count1++;
                break;
            case ')':
                count2++;
                break;
            }

            if (count1 < count2)
            {
                cout << "NO" << endl;
                break;
            }
        }

        if (count1 == count2)
            cout << "YES" << endl;
        else if (count1 > count2)
            cout << "NO" << endl;
    }

    return 0;
}
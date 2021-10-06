// 1769. 3의 배수
// S5

#include <iostream>
#include <string>
using namespace std;

int AddAll(string s, int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++)
        sum += s[i] - 48;

    return sum;
}


int main()
{
    string s1;
    cin >> s1;

    int temp = AddAll(s1, s1.length());
    int count = 0;

    if(s1.length()>1)
    {
        count++;

        while (temp / 10 != 0)
        {
            s1 = to_string(temp);
            temp = AddAll(s1, s1.length());
            count++;
        }
    }

    cout << count << endl;
    
    if (temp % 3 == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
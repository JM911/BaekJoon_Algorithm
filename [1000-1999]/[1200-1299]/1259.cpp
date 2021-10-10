// 1259. 팰린드롬수
// B1

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    bool A = true;

    while (N != 0)
    {
        string SN = to_string(N);

        for (int i = 0; i < SN.size(); i++)
        {
            if (SN[i] != SN[SN.size() - i - 1])
            {
                cout << "no" << endl;
                A = false;
                break;
            }
        }

        if (A == true)
            cout << "yes" << endl;

        A = true;

        cin >> N;
    }

    return 0;
}
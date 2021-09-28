// 2028. 자기복제수
// B2

#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int T;
    int N;
    cin >> T;

    while (count++ < T)
    {
        cin >> N;
        if (N < 10)
        {
            if (N * N % 10 == N)
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }

        else if (N < 100)
        {
            if (N * N % 100 == N)
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }

        else if (N < 1000)
        {
            if (N * N % 1000 == N)
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }

        else cout << "NO" << endl;
    }
    
    return 0;
}
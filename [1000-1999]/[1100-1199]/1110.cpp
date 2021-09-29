// 더하기 사이클
// B1

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int temp = N;
    int a, b;
    int count = 0;

    do 
    {
        a = temp % 10;
        b = temp / 10;

        temp = a * 10 + (a + b) % 10;

        count++;
    } while (temp != N);

    cout << count;

    return 0;
}
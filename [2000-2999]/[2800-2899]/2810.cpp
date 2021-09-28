// 2810. 컵 홀더
// B2

#include <iostream>
using namespace std;

int main()
{
    int seatNum;
    char seat[50] = { };

    cin >> seatNum;
    cin >> seat;
    
    int countL = 0;
    int i = 0;

    while(seat[i])
    {
        if (seat[i] == 'L')
        {
            countL++;
        }
        i++;
    }

    if (countL == 0)
    {
        cout << seatNum;
    }
    else
    {
        cout << seatNum - countL / 2 + 1;
    }

    return 0;
}
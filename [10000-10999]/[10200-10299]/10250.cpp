// 10250. ACM 호텔
// B3

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int H, W, N;
        cin >> H >> W >> N;

        int floor = N % H;
        if (floor == 0)
            floor = H;
        int ho = N / H + 1;
        if (floor == H)
            ho -= 1;

        int room = floor * 100 + ho;

        cout << room << endl;
    }

    return 0;
}
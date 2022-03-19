// 2630. 색종이 만들기
// S3

#include <bits/stdc++.h>
using namespace std;

int N;
int myBoard[130][130];
int ans[3];

int MyFunc(int stX, int stY, int len)
{
    if(len == 1)
    {
        int tmp = myBoard[stX][stY];
        ans[tmp]++;
        return tmp;
    }
    
    int half = len / 2;

    int leftUp      = MyFunc(stX, stY, half);
    int rightUp     = MyFunc(stX, stY + half, half);
    int leftDown    = MyFunc(stX + half, stY, half);
    int rightDown   = MyFunc(stX + half, stY + half, half);

    if(leftUp == 0 && rightUp == 0 && leftDown == 0  && rightDown == 0)
    {
        ans[0] -= 3;
        return 0;
    }
    if(leftUp == 1 && rightUp == 1 && leftDown == 1  && rightDown == 1)
    {
        ans[1] -= 3;
        return 1;
    }

    return 2;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> myBoard[i][j];
        }
    }

    MyFunc(0, 0, N);

    cout << ans[0] << '\n'
         << ans[1];
}
// 1991. 트리 순회
// S1

#include <bits/stdc++.h>
using namespace std;

int N;
int lc[30];
int rc[30];

void MyPreorder(int num)
{
    if(num == -1)
        return;

    char tmp = num + 'A';

    cout << tmp;
    MyPreorder(lc[num]);
    MyPreorder(rc[num]);
}

void MyInorder(int num)
{
    if(num == -1)
        return;

    char tmp = num + 'A';

    MyInorder(lc[num]);
    cout << tmp;
    MyInorder(rc[num]);
}

void MyPostorder(int num)
{
    if(num == -1)
        return;

    char tmp = num + 'A';

    MyPostorder(lc[num]);
    MyPostorder(rc[num]);
    cout << tmp;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char tmpP, tmpL, tmpR;
        cin >> tmpP >> tmpL >> tmpR;

        int iP = tmpP - 'A';
        int iL = tmpL - 'A';
        int iR = tmpR - 'A';

        if(tmpL == '.')
            iL = -1;

        if(tmpR == '.')
            iR = -1;

        lc[iP] = iL;
        rc[iP] = iR;
    }

    MyPreorder(0);
    cout << '\n';
    MyInorder(0);
    cout << '\n';
    MyPostorder(0);
}
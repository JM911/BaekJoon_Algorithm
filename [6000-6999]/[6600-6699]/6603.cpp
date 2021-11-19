// 6603. 로또
// S2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int k;
int S[20];
int arr[10];
bool isVisited[20];
int prevIdx = -1;

void PickSix(int len)
{
    if(len == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = prevIdx + 1; i < k; i++)
    {
        if(isVisited[i] == false)
        {
            arr[len] = S[i];
            isVisited[i] = true;
            prevIdx = i;
            PickSix(len + 1);
            isVisited[i] = false;
        }
    }
}

int main()
{
    //fastio;

    while(true)
    {
        cin >> k;

        if(k==0)
            break;

        for (int i = 0; i < k; i++)
            cin >> S[i];

        PickSix(0);
        prevIdx = -1;

        cout << '\n';
    }

    return 0;
}

// 14890. 경사로
// G3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, L;
int mymap[110][110];
bool checkRow[110][110];
bool checkCol[110][110];

int main()
{
    fastio;
    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mymap[i][j];
        }
    }

    int ans = 0;

    // row
    for (int i = 0; i < N; i++)
    {
        bool isOkay = true;

        for (int j = 0; j < N; j++)
        {
            int curHeight = mymap[i][j];
            int leftIdx = j - 1;
            int rightIdx = j + 1;

            if(leftIdx>=0 && mymap[i][leftIdx] < curHeight)
            {
                for (int k = 0; k < L; k++)
                {
                    if(leftIdx - k < 0)
                    {
                        isOkay = false;
                        break;
                    }

                    if(mymap[i][leftIdx-k] != curHeight - 1 || checkRow[i][leftIdx-k] == true)
                    {
                        isOkay = false;
                        break;
                    }

                    checkRow[i][leftIdx - k] = true;
                }
            }

            if(rightIdx<N && mymap[i][rightIdx] < curHeight)
            {
                for (int k = 0; k < L; k++)
                {
                    if(leftIdx + k >= N)
                    {
                        isOkay = false;
                        break;
                    }

                    if(mymap[i][rightIdx+k] != curHeight - 1 || checkRow[i][rightIdx+k] == true)
                    {
                        isOkay = false;
                        break;
                    }

                    checkRow[i][rightIdx + k] = true;
                }
            }
        }

        if(isOkay)
            ans++;
    }
    
    // coloumn
    for (int i = 0; i < N; i++)
    {
        bool isOkay = true;

        for (int j = 0; j < N; j++)
        {
            int curHeight = mymap[j][i];
            int upIdx = j - 1;
            int downIdx = j + 1;

            if(upIdx>=0 && mymap[upIdx][i] < curHeight)
            {
                for (int k = 0; k < L; k++)
                {
                    if(upIdx - k < 0)
                    {
                        isOkay = false;
                        break;
                    }

                    if(mymap[upIdx-k][i] != curHeight - 1 || checkCol[upIdx-k][i] == true)
                    {
                        isOkay = false;
                        break;
                    }

                    checkCol[upIdx-k][i] = true;
                }
            }

            if(downIdx<N && mymap[downIdx][i] < curHeight)
            {
                for (int k = 0; k < L; k++)
                {
                    if(downIdx + k >= N)
                    {
                        isOkay = false;
                        break;
                    }

                    if(mymap[downIdx+k][i] != curHeight - 1 || checkCol[downIdx+k][i] == true)
                    {
                        isOkay = false;
                        break;
                    }

                    checkCol[downIdx+k][i] = true;
                }
            }
        }

        if(isOkay)
            ans++;
    }

    cout << ans;
}
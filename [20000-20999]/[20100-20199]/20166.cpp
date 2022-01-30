// 20166. 문자열 지옥에 빠진 호석
// G5

#include <bits/stdc++.h>
using namespace std;

int N, M, K;
char board[12][12];
char target[8];
int targetLen;
char myString[8];
int ans;
int targetHash;

// const int hashM = 1000003;
// const int a = 1000;

int dRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

unordered_map<string, int> m;

// int my_hash(char s[])
// {
//     int h = 0;

//     for (int i = 0; i < targetLen; i++)
//     {
//         //h = (h * a + s[i]) % hashM;
//         h = h * 10 + s[i];
//     }

//     return h;
// }

void my_BT(int prevRow, int prevCol, int len)
{
    if(len == 0)
    {
        if(board[prevRow][prevCol] == target[0])
        {
            myString[0] = board[prevRow][prevCol];
            my_BT(prevRow, prevCol, 1);
        }
        return;
    }
    
    // if(target[len-1] != myString[len-1])
    //     return;

    if(len == targetLen)
    {
        // if(targetHash == my_hash(myString))
        // {
        //     // if(target == myString)
        //         ans++;
        // }
        ans++;

        return;
    }

    for (int dir = 0; dir < 8; dir++)
    {
        int curRow = (prevRow + dRow[dir]);
        int curCol = (prevCol + dCol[dir]);

        if(curRow == -1)
            curRow = N - 1;
        else if(curRow == N)
            curRow = 0;
        if(curCol == -1)
            curCol = M - 1;
        else if(curCol == M)
            curCol = 0;

        //myString.push_back(board[curRow][curCol]);
        //myString[len] = board[curRow][curCol];

        if(board[curRow][curCol] != target[len])
            continue;

        my_BT(curRow, curCol, len + 1);

        //myString.pop_back();
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < M; j++)
        {
            board[i][j] = tmp[j];
        }
    }

    // K = 1000;
    // string tmp;
    // cin >> tmp;
    // targetLen = tmp.length();

    while(K--)
    {
        //cin >> target;

        //targetLen = target.length();

        string tmp;
        cin >> tmp;
        targetLen = tmp.length();
        if(m.find(tmp) != m.end())
        {
            cout << m[tmp] << '\n';
            continue;
        }

        for (int i = 0; i < targetLen; i++)
            target[i] = tmp[i];

        ans = 0;
        //targetHash = my_hash(target);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                my_BT(i, j, 0);
            }
        }

        m.insert({tmp, ans});

        cout << ans << '\n';
    }
}
// 9019. DSLR
// G4

#include <bits/stdc++.h>
using namespace std;

int T;

int dp[10010];
char prevOp[10010];
char charOp[4] = {'D', 'S', 'L', 'R'};
int prevNum[10010];

int opD(int n)
{
    return 2 * n % 10000;
}

int opS(int n)
{
    int ret = n - 1;
    if(ret<0)
        ret = 9999;

    return ret;
}

int opL(int n)
{
    int d_1 = n / 1000;
    int ret = n % 1000 * 10 + d_1;
    return ret;
}

int opR(int n)
{
    int d_4 = n % 10;
    int ret = n / 10 + d_4 * 1000;
    return ret;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while(T--)
    {
        int A, B;
        cin >> A >> B;

        fill(dp, dp + 10001, INT_MAX);
       // fill(prevOp, prevOp + 10001, 0);
        //fill(prevNum, prevNum + 10001, -1);
        queue<int> q;

        dp[A] = 0;
        q.push(A);

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            int nxt[4] = {opD(cur), opS(cur), opL(cur), opR(cur)};

            for (int i = 0; i < 4; i++)
            {
                if(dp[nxt[i]] <= dp[cur]+1)
                    continue;

                dp[nxt[i]] = dp[cur] + 1;
                prevOp[nxt[i]] = charOp[i];
                prevNum[nxt[i]] = cur;
                q.push(nxt[i]);
            }
        }

        stack<char> s;

        while(dp[B] != 0)
        {
            s.push(prevOp[B]);
            B = prevNum[B];
        }

        while(!s.empty())
        {
            cout << s.top();
            s.pop();
        }

        cout << '\n';
    }
}
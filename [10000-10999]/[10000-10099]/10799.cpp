// 10799. 쇠막대기
// S3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;
    string prob;
    cin >> prob;
    int len = prob.length();

    int sStack = 0;
    int ans = 0;

    for (int i = 0; i < len; i++)
    {
        if(prob[i] == '(')
        {
            if(prob[i+1] == ')')
            {
                ans += sStack;
                i++;
            }
            else
                sStack++;
        }

        else
        {
            ans++;
            sStack--;
        }
    }

    cout << ans;
}
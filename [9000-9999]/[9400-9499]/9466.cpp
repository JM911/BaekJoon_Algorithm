// 9466. 텀 프로젝트
// G3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

pair<int, bool> isVisited[100001];
bool isTeamed[100001];

int main()
{
    fastio;
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        int* student = new int[n + 1];

        for (int i = 1; i <= n; i++)
        {
            cin >> student[i];
            isVisited[i] = {0, false};
            isTeamed[i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            if(isVisited[i].second == true)
                continue;

            isVisited[i] = {i, true};
            int target = student[i];

            while(isVisited[target].second == false)
            {
                isVisited[target] = {i, true};
                target = student[target];
            }

            if(isVisited[target].first != i)
                continue;
            
            while(isTeamed[target] == false)
            {
                isTeamed[target] = true;
                target = student[target];
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if(isTeamed[i] == false)
                ans++;
        }

        cout << ans << '\n';

        delete[] student;
    }
}

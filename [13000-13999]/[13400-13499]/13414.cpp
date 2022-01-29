// 13414. 수강신청
// S3

#include <bits/stdc++.h>
using namespace std;

int K, L;
string student[500010];
bool isEnable[500010];
unordered_map<string, int> m;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> K >> L;
    int count = 0;

    while(count < L)
    {
        string tmp;
        cin >> tmp;

        if(m.find(tmp) != m.end())
            isEnable[m[tmp]] = false;
        
        m[tmp] = count;

        student[count] = tmp;
        isEnable[count] = true;

        count++;
    }

    int idx = 0;
    count = 0;

    while(count < K && idx < L)
    {
        if(isEnable[idx] == true)
        {
            cout << student[idx] << '\n';
            count++;
        }

        idx++;
    }
}
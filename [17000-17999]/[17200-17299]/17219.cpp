// 17219. 비밀번호 찾기
// S4

#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, string> m;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    string site, pw;

    while(N--)
    {
        cin >> site >> pw;
        m.insert({site, pw});
    }

    while(M--)
    {
        cin >> site;
        cout << m[site] << '\n';
    }
}
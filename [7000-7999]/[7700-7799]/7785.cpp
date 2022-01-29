// 7785. 회사에 있는 사람
// S5

#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> s;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string name, el;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> el;

        if(el == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    vector<string> v;

    for(auto t : s)
        v.push_back(t);

    sort(v.begin(), v.end());

    vector<string>::reverse_iterator iter;

    for (iter = v.rbegin(); iter != v.rend(); ++iter)
    {
        cout << *iter << '\n';
    }
}
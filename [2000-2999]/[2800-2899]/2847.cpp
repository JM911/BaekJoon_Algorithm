// 2847. 게임을 만든 동준이 
// S4

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int N;
stack<int> s;
int ans;

int main()
{
	setIO("");

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        s.push(tmp);
    }

    int nextNum = s.top();
    s.pop();

    while(!s.empty())
    {
        int curNum = s.top();
        s.pop();

        if(curNum >= nextNum)
        {
            ans += curNum - (nextNum - 1);
            nextNum -= 1;
        }
        else
            nextNum = curNum;
    }

    cout << ans;
}
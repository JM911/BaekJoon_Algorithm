// 7570. 줄 세우기
// G3

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
int pos[1000010];
bool bVisit[1000010];
int maxStreak;

int main()
{
	setIO("");

    cin >> N;
    for(int i=1; i<=N; i++)
    {
        int tmp;
        cin >> tmp;
        pos[tmp] = i;
    }

    for(int i=1; i<=N; i++)
    {
        if(bVisit[i]) continue;

        bVisit[i] = true;
        int curNum = i;
        int streak = 1;
        while(true)
        {
            if(curNum == N || pos[curNum+1] < pos[curNum]) break;
            
            streak++;
            curNum++;
            bVisit[curNum] = true;
        }

        maxStreak = max(maxStreak, streak);
    }

    cout << N-maxStreak;
}
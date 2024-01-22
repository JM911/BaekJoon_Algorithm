// 17281. ⚾
// G4

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
vector<int> score[12];

int ans;
int numOrder[12];

void Simul()
{
	int curScore = 0;
	int curOrder = 1;

	for(int inn=1; inn<=N; inn++)
	{
		int curOut = 0;
		queue<int> recentResult;
		int curTotalResult = 0;

		while(curOut < 3)
		{
			int curNum = numOrder[curOrder];
			int curResult = score[curNum][inn];

			if(curResult == 0)
				curOut++;
			else
			{
				curTotalResult += curResult;
				recentResult.push(curResult);

				while(curTotalResult >= 4 && !recentResult.empty())
				{
					curTotalResult -= recentResult.front();
					recentResult.pop();
					curScore++;
				}
			}

			curOrder++;
			if(curOrder > 9) curOrder = 1;
		}
	}

	ans = max(ans, curScore);
}

int main()
{
	setIO("");

	for(int i=1; i<=9; i++)
	{
		score[i].resize(53,-1);
	}

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=9; j++)
		{
			cin >> score[j][i];
		}
	}

	for(int i=1; i<=9; i++)
	{
		numOrder[i] = i;
	}

	do
	{
		if(numOrder[4] == 1)
		{
			Simul();
		}
	} while (next_permutation(&numOrder[1], &numOrder[10]));
	
	cout << ans;
}
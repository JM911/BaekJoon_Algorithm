// 17140. 이차원 배열과 연산
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

int r, c, k;

int A[105][105];
int t;
int row = 3;
int col = 3;

bool MyCmp(pair<int, int> a, pair<int, int> b)
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

void OpR()
{
	int cnt[105];
	int newCol = 0;

	for(int i=1; i<=row; i++)
	{
		fill(cnt, cnt+102, 0);
		for(int j=1; j<=col; j++)
		{
			if(A[i][j] == 0) continue;

			cnt[A[i][j]]++;
		}

		vector<pair<int, int>> tmpVec;
		tmpVec.reserve(105);

		for(int k=1; k<=100; k++)
		{
			if(cnt[k] > 0)
				tmpVec.push_back({k, cnt[k]});
		}
		sort(tmpVec.begin(), tmpVec.end(), MyCmp);
		int tmpSize = tmpVec.size();

		for(int j=1; j<=100; j+=2)
		{
			int k = j/2;
			if(k<tmpSize)
			{
				A[i][j] = tmpVec[k].first;
				A[i][j+1] = tmpVec[k].second;
			}
			else
			{
				A[i][j] = 0;
				A[i][j+1] = 0;
			}

		}
		newCol = max(newCol, tmpSize*2);
	}

	col = newCol;
}

void OpC()
{
	int cnt[105];
	int newRow = 0;

	for(int j=1; j<=col; j++)
	{
		fill(cnt, cnt+102, 0);
		for(int i=1; i<=row; i++)
		{
			if(A[i][j] == 0) continue;

			cnt[A[i][j]]++;
		}

		vector<pair<int, int>> tmpVec;
		tmpVec.reserve(105);

		for(int k=1; k<=100; k++)
		{
			if(cnt[k] > 0)
				tmpVec.push_back({k, cnt[k]});
		}
		sort(tmpVec.begin(), tmpVec.end(), MyCmp);
		int tmpSize = tmpVec.size();

		for(int i=1; i<=100; i+=2)
		{
			int k = i/2;
			if(k<tmpSize)
			{
				A[i][j] = tmpVec[k].first;
				A[i+1][j] = tmpVec[k].second;
			}
			else
			{
				A[i][j] = 0;
				A[i+1][j] = 0;
			}

		}
		newRow = max(newRow, tmpSize*2);
	}

	row = newRow;
}

void DebugPrint()
{
	cout << '\n';
	for(int i=1; i<=row; i++)
	{
		for(int j=1; j<=col; j++)
		{
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	setIO("");

	cin >> r >> c >> k;
	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++)
		{
			cin >> A[i][j];
		}
	}

	if(A[r][c] == k)
	{
		cout << t;
		return 0;
	}

	while(t++ < 100)
	{
		if(row >= col)
			OpR();
		else
			OpC();

		//DebugPrint();

		if(A[r][c] == k)
		{
			cout << t;
			return 0;
		}
	}

	cout << -1;
}
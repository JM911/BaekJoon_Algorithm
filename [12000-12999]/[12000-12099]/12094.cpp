// 12094. 2048 (Hard)
// P4

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
int board[12][25][25];

int ans;
//int boardOrigin[25][25];

#define TRY_NUM 10

void ClearBoard(int idx)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			board[idx][i][j] = 0;
		}
	}
}

void MoveLeft(int len)
{
	for(int i=0; i<N; i++)
	{
		int prevCol = 0;
		int prevNum = 0;

		for(int j=0; j<N; j++)
		{
			int curNum = board[len][i][j];
			board[len+1][i][j] = 0;

			if(curNum == 0)	continue;

			if(prevNum == 0)
			{
				board[len+1][i][prevCol] = curNum;

				prevNum = curNum;
			}
			else if(prevNum == curNum)
			{
				board[len+1][i][prevCol] *= 2;
				ans = max(ans, board[len+1][i][prevCol]);

				prevCol++;
				prevNum = 0;
			}
			else
			{
				prevCol++;
				board[len+1][i][prevCol] = curNum;

				prevNum = curNum;
			}
		}
	}
}
void MoveRight(int len)
{
	for(int i=0; i<N; i++)
	{
		int prevCol = N-1;
		int prevNum = 0;

		for(int j=N-1; j>=0; j--)
		{
			int curNum = board[len][i][j];
			board[len+1][i][j] = 0;

			if(curNum == 0)	continue;

			if(prevNum == 0)
			{
				board[len+1][i][prevCol] = curNum;

				prevNum = curNum;
			}
			else if(prevNum == curNum)
			{
				board[len+1][i][prevCol] *= 2;
				ans = max(ans, board[len+1][i][prevCol]);

				prevCol--;
				prevNum = 0;
			}
			else
			{
				prevCol--;
				board[len+1][i][prevCol] = curNum;

				prevNum = curNum;
			}
		}
	}
}
void MoveUp(int len)
{
	for(int j=0; j<N; j++)
	{
		int prevRow = 0;
		int prevNum = 0;

		for(int i=0; i<N; i++)
		{
			int curNum = board[len][i][j];
			board[len+1][i][j] = 0;

			if(curNum == 0)	continue;

			if(prevNum == 0)
			{
				board[len+1][prevRow][j] = curNum;

				prevNum = curNum;
			}
			else if(prevNum == curNum)
			{
				board[len+1][prevRow][j] *= 2;
				ans = max(ans, board[len+1][prevRow][j]);

				prevRow++;
				prevNum = 0;
			}
			else
			{
				prevRow++;
				board[len+1][prevRow][j] = curNum;

				prevNum = curNum;
			}
		}
	}
}
void MoveDown(int len)
{
	for(int j=0; j<N; j++)
	{
		int prevRow = N-1;
		int prevNum = 0;

		for(int i=N-1; i>=0; i--)
		{
			int curNum = board[len][i][j];
			board[len+1][i][j] = 0;

			if(curNum == 0)	continue;

			if(prevNum == 0)
			{
				board[len+1][prevRow][j] = curNum;

				prevNum = curNum;
			}
			else if(prevNum == curNum)
			{
				board[len+1][prevRow][j] *= 2;
				ans = max(ans, board[len+1][prevRow][j]);

				prevRow--;
				prevNum = 0;
			}
			else
			{
				prevRow--;
				board[len+1][prevRow][j] = curNum;

				prevNum = curNum;
			}
		}
	}
}

void Solve(int len)
{
	if(len >= TRY_NUM)
	{
		return;
	}

	for(int d=0; d<4; d++)
	{
		switch(d)
		{
			case 0:
				MoveLeft(len);
				break;
			case 1:
				MoveRight(len);
				break;
			case 2:
				MoveUp(len);
				break;
			case 3:
				MoveDown(len);
				break;
		}
		Solve(len+1);
	}
}

int main()
{
	setIO("");

	cin >> N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> board[0][i][j];
			ans = max(ans, board[0][i][j]);
		}
	}

	Solve(0);
	cout << ans;
}
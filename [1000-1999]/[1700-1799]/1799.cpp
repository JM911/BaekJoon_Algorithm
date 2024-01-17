// 1799. 비숍
// G1

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
bool board[12][12];

int ansOdd, ansEven, curNumOdd, curNumEven;
bool bUsed1[25]; // 대각선1 (x+y)
bool bUsed2[25]; // 대각선2 (x-y+N-1)

void SolveOdd(int len)
{
	if(len >= 2*N-1)
	{
		ansOdd = max(ansOdd, curNumOdd);
		return;
	}

	int startI = max(0, len-N+1);
	int endI = min(len, N-1);

	for(int i=startI; i<=endI; i++)
	{
		int j = len-i;
		
		if(!board[i][j] || bUsed2[i-j+N-1]) 
			continue; 

		curNumOdd++;
		bUsed2[i-j+N-1] = true;
		
		SolveOdd(len+2);

		curNumOdd--;
		bUsed2[i-j+N-1] = false;
	}

	SolveOdd(len+2);
}

void SolveEven(int len)
{
	if(len >= 2*N-1)
	{
		ansEven = max(ansEven, curNumEven);
		return;
	}

	int startI = max(0, len-N+1);
	int endI = min(len, N-1);

	for(int i=startI; i<=endI; i++)
	{
		int j = len-i;
		
		if(!board[i][j] || bUsed2[i-j+N-1]) 
			continue; 

		curNumEven++;
		bUsed2[i-j+N-1] = true;
		
		SolveEven(len+2);

		curNumEven--;
		bUsed2[i-j+N-1] = false;
	}

	SolveEven(len+2);
}

int main()
{
	setIO("");

	cin >> N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			int tmp;
			cin >> tmp;
			board[i][j] = (tmp == 1) ? true : false;
		}
	}
	
	SolveEven(0);
	SolveOdd(1);

	cout << ansOdd + ansEven;
}
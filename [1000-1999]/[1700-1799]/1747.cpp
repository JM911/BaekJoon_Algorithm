// 1747. 소수&팰린드롬
// S1

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;
vector<bool> p;

bool IsPal(int num)
{
	queue<int> q;
	int d = 1;

	while(num >= d)
	{
		int digit = (num/d)%10;

		q.push(digit);
		d *= 10;
	}

	int newNum = 0;
	while(!q.empty())
	{
		int digit = q.front();
		q.pop();

		newNum *= 10;
		newNum += digit;
	}

	return num == newNum;
}

int main()
{
	FASTIO;

	const int MAX_NUM = 1003002;
	p.resize(MAX_NUM+10, true);
	p[0] = false;
	p[1] = false;

	for(int i=2; i*i <= MAX_NUM; i++)
	{
		if(!p[i]) continue;

		for(int j=2; i*j <= MAX_NUM; j++)
		{
			p[i*j] = false;
		}
	}

	cin >> N;
	while(true)
	{
		if(p[N] && IsPal(N))
		{
			cout << N;
			break;
		}
		N++;
	}
}
// 11728. 배열 합치기
// S5

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

int N, M;
int A[1000010];
int B[1000010];

int main()
{
	setIO("");

	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		cin >> A[i];
	}
	for(int i=0; i<M; i++)
	{
		cin >> B[i];
	}

	int ia = 0;
	int ib = 0;

	while(ia<N && ib<M)
	{
		if(A[ia] <= B[ib])
			cout << A[ia++] << ' ';
		else
			cout << B[ib++] << ' ';
	}

	if(ia==N)
	{
		while(ib<M)
		{
			cout << B[ib++] << ' ';
		}
	}
	else if(ib==M)
	{
		while(ia<N)
		{
			cout << A[ia++] << ' ';
		}
	}
}
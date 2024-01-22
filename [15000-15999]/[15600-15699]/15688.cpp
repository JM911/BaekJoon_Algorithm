// 15688. 수 정렬하기 5
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

int N;
int arr[2010000];
#define ADD_NUM 1000000

int main()
{
	setIO("");

	cin >> N;
	for(int i=0; i<N; i++)
	{
		int tmp;
		cin >> tmp;
		arr[tmp + ADD_NUM]++;
	}

	for(int i=0; i<= ADD_NUM * 2; i++)
	{
		while(arr[i]>0)
		{
			cout << i - ADD_NUM << '\n';
			arr[i]--;
		}
	}
}
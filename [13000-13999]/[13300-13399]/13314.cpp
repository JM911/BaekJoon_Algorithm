// 13314. 플로이드에 오타가?
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int main()
{
	FASTIO;

	cout << 100 << '\n';
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
			if(i==j) cout << 0 << ' ';
			else if(i==99 || j==99) cout << 1 << ' ';
			else cout << 9999 << ' ';
		}
		cout << '\n';
	}
}
// 1253. 좋다
// G4

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;
vector<int> A;
int ans;

int main()
{
	FASTIO;

	cin >> N;
	A.resize(N);
	for(auto& e : A)
	{
		cin >> e;
	}

	sort(A.begin(), A.end());
	bool bPrev = false;
	int prevNum = INT_MAX;

	for(int i=N-1; i>=0; i--)
	{
		if(A[i] == prevNum)
		{
			if(bPrev) ans++;
			continue;
		}

		bPrev = false;
		prevNum = A[i];

		for(int j=N-1; j>=0; j--)
		{
			if(j == i) continue;
			if(!binary_search(A.begin(), A.end(), A[i] - A[j])) continue;
			int l = lower_bound(A.begin(), A.end(), A[i] - A[j]) - A.begin();
			int u = upper_bound(A.begin(), A.end(), A[i] - A[j]) - A.begin();

			for(int k=l; k<u; k++)
			{
				if(k!=i && k!=j)
				{
					ans++;
					bPrev = true;
					break;
				}
			}
			if(bPrev) break;
		}
	}

	cout << ans;
}
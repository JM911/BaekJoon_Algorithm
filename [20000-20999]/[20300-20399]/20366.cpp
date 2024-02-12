// 20366. 같이 눈사람 만들래?
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N;
vector<int> H;

int main()
{
	FASTIO;

	cin >> N;
	H.resize(N);
	for(auto& e : H)
	{
		cin >> e;
	}

	sort(H.begin(), H.end());

	int ans = 0x7f7f7f7f;
	for(int s1=0; s1<N; s1++)
	{
		for(int e1=N-1; e1>s1+1; e1--)
		{
			int sum1 = H[s1] + H[e1];
			int s2 = s1+1;
			if(s2 == e1) s2++;
			int e2 = N-1;

			while(s2 < e2)
			{
				if(e2 == e1) 
				{
					e2--;
					continue;
				}

				int sum2 = H[s2] + H[e2];
				ans = min(ans, abs(sum1 - sum2));
				if(sum2 < sum1)
					s2++;
				else
					e2--;
			}
		}
	}

	cout << ans;
}
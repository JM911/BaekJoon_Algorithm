// 1019. 책 페이지
// G1

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
ll N;

ll ans[10];

int main()
{
	FASTIO;
	
	//while(true)
	{	
		//fill(ans, ans+10, 0);

		cin >> N;
		ll digit = 1;
		ll div = 10;
		
		while(true)
		{
			if(N/div <= 0) break;

			ll a = (N / div) % 10;
			ll b = N % div;

			ll add = a * (digit) * div / 10;
			for(int i=0; i<=9; i++)
			{
				ans[i] += add;

				if(i < a && i > 0)
					ans[i] += div;
			}
			
			if(a>0)
				ans[a] += (b+1);

			if(a == 0)
				ans[0] -= (div - b - 1);

			digit++;
			div *= 10;
		}

		for(int i=1; i<=N%10; i++)
		{
			ans[i]++;
		}

		for(int i=0; i<=9; i++)
		{
			cout << ans[i] << ' ';
		}
	}
}
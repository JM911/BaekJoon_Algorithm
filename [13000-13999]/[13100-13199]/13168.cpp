// 13168. 내일로 여행
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int N, R, M, K;
vector<string> v1, v2;
unordered_map<string, unordered_map<string, int>> um1, um2;

int main()
{
	FASTIO;

	cin >> N >> R;
	v1.resize(N);
	for(auto& e : v1)
		cin >> e;
	
	cin >> M;
	v2.resize(M);
	for(auto& e : v2)
		cin >> e;

	for(auto e1 : v1)
		for(auto e2 : v1)
		{	
			if(um1.find(e1) != um1.end())
					um1[e1].insert({e2, 400001});
			else
			{
				unordered_map<string, int> tmpUm;
				tmpUm.insert({e2, 400001});
				um1.insert({e1, tmpUm});
			}

			if(um2.find(e1) != um2.end())
					um2[e1].insert({e2, 400001});
			else
			{
				unordered_map<string, int> tmpUm;
				tmpUm.insert({e2, 400001});
				um2.insert({e1, tmpUm});
			}
		}
	
	cin >> K;
	while(K--)
	{
		string Type, S, E;
		int Cost;

		cin >> Type >> S >> E >> Cost;
		Cost *= 2;

		um1[S][E] = min(um1[S][E], Cost);
		um1[E][S] = min(um1[E][S], Cost);

		if(Type[0] == 'I' ||  Type[0] == 'M')
			Cost = 0;
		else if(Type[1] == '-')
			Cost /= 2;

		um2[S][E] = min(um2[S][E], Cost);
		um2[E][S] = min(um2[E][S], Cost);
	}

	for(auto i : v1)
		for(auto s : v1)
			for(auto e : v1)
			{
				um1[s][e] = min(um1[s][e], um1[s][i] + um1[i][e]);
				um2[s][e] = min(um2[s][e], um2[s][i] + um2[i][e]);
			}

	ll total1 = 0;
	ll total2 = R * 2;

	for(int i=0; i<M-1; i++)
	{
		string S = v2[i];
		string E = v2[i+1];
		
		total1 += um1[S][E];
		total2 += um2[S][E];
	}

	if(total1 > total2)
		cout << "Yes";
	else
		cout << "No";
}
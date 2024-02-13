// 16165. 걸그룹 마스터 준석이
// S3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

int N, M;
unordered_map<string, vector<string>> um1;
unordered_map<string, string> um2;

int main()
{
	FASTIO;

	cin >> N >> M;
	while(N--)
	{
		string teamName;
		cin >> teamName;
		
		int num;
		cin >> num;

		vector<string> v;
		
		while(num--)
		{
			string memName;
			cin >> memName;

			v.push_back(memName);
			um2.insert({memName, teamName});
		}

		sort(v.begin(), v.end());
		um1.insert({teamName, v});
	}

	while(M--)
	{
		string name;
		int q;
		cin >> name >> q;

		if(q == 0)
		{
			vector<string> v = um1[name];
			for(auto e : v)
			{
				cout << e << '\n';
			}
		}
		else
		{
			cout << um2[name] << '\n';
		}
	}
}
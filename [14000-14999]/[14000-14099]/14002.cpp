// 14002. 가장 긴 증가하는 부분 수열 4
// G4

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
vector<stack<int>> v;

int main()
{
	setIO("");

	cin >> N;
	
	while(N--)
	{
		int tmp;
		cin >> tmp;

		auto iter = v.begin();
		auto iterEnd = v.end();
		
		while(iter != iterEnd)
		{
			if(tmp <= iter->top())
			{
				iter->push(tmp);
				break;
			}
			++iter;
		}

		if(iter == iterEnd)
		{
			stack<int> s;
			s.push(tmp);
			v.push_back(s);
		}
	}

	int ans = v.size();
	cout << ans << '\n';

	stack<int> ansStack;
	for(int i=ans-1; i>=0; i--)
	{
		if(ansStack.empty())
		{
			ansStack.push(v[i].top());
			continue;
		}
		while(true)
		{
			int curNum = v[i].top();
			v[i].pop();
			if(v[i].empty() || v[i].top() >= ansStack.top())
			{
				ansStack.push(curNum);
				break;
			}
		}
	}
	while(!ansStack.empty())
	{
		cout << ansStack.top() << ' ';
		ansStack.pop();
	}
}
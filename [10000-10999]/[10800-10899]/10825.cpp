// 10825. 국영수
// S4

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

struct ScoreSet
{
	string Name;
	int kor, eng, math;

	ScoreSet(const string& s, int a, int b, int c)
		: Name(s), kor(a), eng(b), math(c)
	{

	}
};

int N;
vector<ScoreSet> v;

bool MyComp(const ScoreSet& A, const ScoreSet& B)
{
	if(A.kor == B.kor)
	{
		if(A.eng == B.eng)
		{
			if(A.math == B.math)
			{
				return A.Name.compare(B.Name) < 0;
			}

			return A.math > B.math;
		}

		return A.eng < B.eng;
	}

	return A.kor > B.kor;
}

int main()
{
	setIO("");

	cin >> N;
	v.reserve(N);
	for(int i=0; i<N; i++)
	{
		string s;
		int a, b, c;
		cin >> s >> a >> b >> c;

		v.push_back(ScoreSet(s, a, b, c));
	}

	sort(v.begin(), v.end(), MyComp);
	for(auto a : v)
	{
		cout << a.Name << '\n';
	}
}
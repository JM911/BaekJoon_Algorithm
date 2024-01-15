// 11003. 최솟값 찾기
// P5

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

int N, L;
vector<int> A;
deque<pair<int, int>> d;

int main()
{
  setIO("");

  cin >> N >> L;
  A.resize(N);

  for(int i=1; i<=N; i++)
    cin >> A[i];

  for(int i=1; i<=N; i++)
  {
    int target = A[i];
    while(!d.empty() && d.back().first > A[i])
    {
      d.pop_back();
    }
    if(!d.empty() && d.front().second <= i-L)
    {
      d.pop_front();
    }
    d.push_back({A[i], i});
    cout << d.front().first << ' ';
  }
}
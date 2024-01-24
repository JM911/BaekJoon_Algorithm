// 1431. 시리얼 번호
// S3

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
vector<string> v;

int GetSum(const string& s)
{
	int sum = 0;
	for(auto a : s)
	{
		if(a >= '0' && a <= '9')
			sum += (a - '0');
	}
	return sum;
}

bool DicComp(const string& A, const string& B)
{
	int len = A.length();
	for(int i=0; i<len; i++)
	{
		if(A[i] == B[i]) continue;
		return A[i] < B[i];
	}

	return false;
}

bool MyComp(const string& A, const string& B)
{
	int lenA = A.length();
	int lenB = B.length();

	if(lenA == lenB)
	{
		int sumA = GetSum(A);
		int sumB = GetSum(B);

		if(sumA == sumB)
		{
			return DicComp(A, B);
		}

		return sumA < sumB;
	}

	return lenA < lenB;
}

int main()
{
	setIO("");

	cin >> N;
	v.resize(N);
	for(auto& a : v)
	{
		cin >> a;
	}

	sort(v.begin(), v.end(), MyComp);
	
	for(auto a : v)
	{
		cout << a << '\n';
	}
}
#include <iostream>
using namespace std;

int main()
{
	unsigned long long dot;
	unsigned long long n;
	cin >> n;

	dot = 3 * n * (n + 1) / 2 + n + 1;

	cout << dot % 45678;
	
	return 0;
}	
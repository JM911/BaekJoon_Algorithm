#include <iostream>
#include <cmath>
using namespace std;

int Max(int a, int b, int c)
{
	int max = a;
	if (a < b)
	{
		if (b < c) max = c;
		else max = b;
	}
	else if (a < c) max = c;

	return max;
}

int main()
{
	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;

	if (d1 == d2 && d2 == d3)
		cout << 10000 + d1 * 1000;
	else if (d1 == d2 || d1 == d3)
		cout << 1000 + d1 * 100;
	else if (d2 == d3)
		cout << 1000 + d2 * 100;
	else cout << Max(d1, d2, d3) * 100;
	
	return 0;
}
#include <iostream>
using namespace std;

int min(int a, int b, int c, int d)
{
	int minimum = a;
	if (minimum > b)
		minimum = b;
	if (minimum > c)
		minimum = c;
	if (minimum > d)
		minimum = d;

	return minimum;
}

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int dist = min(x, y, w - x, h - y);
	cout << dist;

	return 0;
}
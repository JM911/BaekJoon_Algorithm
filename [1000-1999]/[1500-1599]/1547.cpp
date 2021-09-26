#include <iostream>
using namespace std;

int ballNum = 1;

void cupSwap(int a, int b)
{
	if (a == ballNum) ballNum = b;
	else if (b == ballNum) ballNum = a;
}

int main()
{
	int count;
	int swapA, swapB;
	cin >> count;
	

	for (int i = 0; i < count; ++i)
	{
		cin >> swapA >> swapB;
		cupSwap(swapA, swapB);
	}

	cout << ballNum;
	
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int numCall;
	int time;
	int priceY = 0;
	int priceM = 0;

	cin >> numCall;


	for (int i = 0; i < numCall; ++i)
	{
		cin >> time;

		priceY += (1 + (time / 30)) * 10;
		priceM += (1 + (time / 60)) * 15;
	}

	if (priceY < priceM)
	{
		cout << "Y " << priceY;
	}
	else if (priceM < priceY)
	{
		cout << "M " << priceM;
	}
	else
	{
		cout << "Y M " << priceY;
	}
	
	return 0;
}

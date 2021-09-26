#include <iostream>
using namespace std;

int main()
{
	int cardA[10];
	int cardB[10];
	int pointA = 0;
	int pointB = 0;

	for (int i = 0; i < 10; ++i)
	{
		cin >> cardA[i];
	}

	for (int i = 0; i < 10; ++i)
	{
		cin >> cardB[i];
	}
	
	for (int i = 0; i < 10; ++i)
	{
		if (cardA[i] > cardB[i])	pointA += 3;
		else if (cardA[i] < cardB[i])	pointB += 3;
		else
		{
			pointA += 1;
			pointB += 1;
		}
	}

	cout << pointA << ' ' << pointB << endl;

	if (pointA > pointB)
	{
		cout << 'A';
		return 0;
	}
	else if (pointA < pointB)
	{
		cout << 'B';
		return 0;
	}
	else
	{
		for (int i = 9; i >= 0; --i)
		{
			if (cardA[i] > cardB[i])
			{
				cout << 'A';
				return 0;
			}
			else if (cardA[i] < cardB[i])
			{
				cout << 'B';
				return 0;
			}
		}
	}
	cout << 'D';
	return 0;
}	
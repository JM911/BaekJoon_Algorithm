#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int count;
	char numPad[10];
	int character[3];
	int number[4];
	int left, right;
	cin >> count;

	
	while (count > 0)
	{
		cin >> numPad;

		character[0] = numPad[0] - 65;
		character[1] = numPad[1] - 65;
		character[2] = numPad[2] - 65;

		left = character[0] * 26 * 26 + character[1] * 26 + character[2];
		
		number[0] = numPad[4] - 48;
		number[1] = numPad[5] - 48;
		number[2] = numPad[6] - 48;
		number[3] = numPad[7] - 48;

		right = number[0] * 1000 + number[1] * 100 + number[2] * 10 + number[3];

		if (abs(left - right) <= 100)
			cout << "nice" << endl;
		else
			cout << "not nice" << endl;

		count--;
	}

	return 0;
}
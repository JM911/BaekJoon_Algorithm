#include <iostream>
using namespace std;

int main()
{
	int N, F;
	cin >> N >> F;
	
	int newN = N / 100 * 100;
	
	for (int i = 0; i < 100; ++i)
	{
		if (newN % F == 0)
			break;
		newN++;
	}
	
	int delta = newN - (newN / 100) * 100;
	
	int arr[2];
	arr[0] = delta / 10;
	arr[1] = delta - arr[0] * 10;
	cout << arr[0] << arr[1];

	return 0;
}	
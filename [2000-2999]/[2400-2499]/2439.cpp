#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		for (int k = 0; k < num - i-1; ++k)
			cout << " ";
		for (int j = 0; j < i + 1; ++j)
			cout << "*";
		
		cout << endl;
	}
	
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		for (int k = 0; k < num - i; ++k)
			cout << "*";
		
		cout << endl;
	}
	
	return 0;
}
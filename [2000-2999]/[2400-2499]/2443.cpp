#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < i ; ++j)
			cout << " ";
		for (int k = 0; k < num-i; ++k)
			cout << "*";
		for (int l = 0; l < num-i-1; ++l)
			cout << "*";
		
		cout << endl;
	}
	
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	char str[5];
	int width;

	cin >> str;

	while (str[0] != '0')
	{
		width = 1;
		for (int i = 0; i < 4; ++i)
		{
			if (str[i] == NULL)
				break;
			else if (str[i] == '0')	width += 4;
			else if (str[i] == '1') width += 2;
			else width += 3;

			width += 1;
		}

		cout << width << endl;
		cin >> str;
	}
	
	return 0;
}
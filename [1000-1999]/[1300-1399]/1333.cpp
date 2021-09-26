#include <iostream>
using namespace std;

int main()
{
	int songNum;
	int songLen;
	int bellTerm;

	cin >> songNum >> songLen >> bellTerm;

	int allbumLen = songLen * songNum + 5 * (songNum - 1);
	int finalNum = allbumLen / bellTerm + 1;
	if (allbumLen % bellTerm == 0) finalNum -= 1;

	for (int i = 0; i < finalNum; i++)
	{
		for (int j = 1; j < songNum; j++)
		{
			if (bellTerm * i >= songLen * j + 5 * (j - 1) && bellTerm * i < songLen * j + 5 * j)
			{
				cout << i*bellTerm;
				return 0;
			}
		}
	}

	cout << finalNum * bellTerm;
	
	return 0;
}	
#include <iostream>
using namespace std;

int MaxIndex(int arr[], int len)
{
	int maxi = 0;
	for (int i = 0; i < len; ++i)
	{
		if (arr[maxi] < arr[i])
			maxi = i;
	}

	return maxi;
}

int main()
{
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int arr[80] = { 0, };
	int temp;

	for (int i = 1; i <= s1; ++i)
	{
		for (int j = 1; j <= s2; ++j)
		{
			for (int k = 1; k <= s3; ++k)
			{
				temp = i + j + k;
				arr[temp]++;
			}
		}
	}

	int ans = MaxIndex(arr, 80);
	cout << ans;

	return 0;
}	
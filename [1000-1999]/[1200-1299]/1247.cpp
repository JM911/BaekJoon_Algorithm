#include <iostream>
#include <climits>
using namespace std;

int sumSign(long long* arr, int len)
{
	long long sum = 0;
	int ofnum = 0;

	for (int i = 0; i < len; i++)
	{
		if (sum > 0 && arr[i] > 0 && sum > LLONG_MAX - arr[i])
			++ofnum;
		else if (sum < 0 && arr[i] < 0 && sum < LLONG_MIN - arr[i])
			--ofnum;

		sum += arr[i];
	}

	if (ofnum > 0)
		return 1;
	else if (ofnum < 0)
		return -1;
	else if (sum > 0)
		return 1;
	else if (sum < 0)
		return -1;
	else return 0;
}

int main()
{
	int count = 0;

	while (count < 3)
	{
		int num;
		cin >> num;

		long long* arr = new long long[num];
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}

		int ans = sumSign(arr, num);

		if (ans < 0)
			cout << "-";
		else if (ans > 0)
			cout << "+";
		else
			cout << 0;

		cout << endl;
		delete[] arr;

		count++;
	}
	return 0;
}

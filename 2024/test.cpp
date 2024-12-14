#include<iostream>
#include<queue>
using namespace std;
long long gcd(long long a, long long b)
{
	while (a != b)
	{
		if (a > b) a = a - b;
		else b = b - a;
	}
	return a;
}
long long arr[100001];
int main()
{

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int m = INT_MAX;
	for (int i = 1; i < n; i++)
	{
		long long n1 = arr[i - 1], n2 = arr[i];
		while (n1 != 1 && n2 != 1)
		{
			gcd(n1, n2);
		}
	}
	return 0;

}
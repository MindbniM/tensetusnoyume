#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int ret = 0;
	if (n > 30) ret += n - 30;
	n = min(n, 30);
	vector<int> v(n);
	vector<int> arr(n);
	arr[0] = 1, arr[1] = 1;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 3; i < n; i++) arr[i] = arr[i - 1] + arr[i - 2];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

		}
	}
	int ret = 0;

}

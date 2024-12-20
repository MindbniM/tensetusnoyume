#include <iostream>
using namespace std;
long long v[10];
long long sum[10];
int h1[10] = { 0,1,1,2,2,3,3,4,4,5 };
int h2[10] = { 0,0,1,1,2,2,3,3,4,4 };
int main()
{
	ios::sync_with_stdio(0);
	string str;
	cin >> str;
	v[0] = 1;
	sum[0] = 0;
	int n = str.size();
	for (int i = 1; i < n; i++)
	{
		v[i] = v[i - 1] * 5;
		sum[i] = sum[i - 1];
		if (i % 2 == 0) sum[i] += v[i - 1] * 4;
		else sum[i] += v[i];
	}
	long long num = 0;
	if (n > 1) num = sum[n - 1];
	//cout << num << endl;
	for (int i = 0; i < n; i++)
	{
		if ((n - i) % 2 == 0)
		{
			int temp=h1[str[i] - '0'];
			if (i == 0) temp--;
			num += temp * v[n - i - 1];
			if ((str[i]-'0') % 2 != 0) break;
		}
		else
		{
			int temp=h2[str[i] - '0'];
			num += temp * v[n - i - 1];
			if (i==n-1&&(str[i] - '0') % 2 == 1) num++;
			if ((str[i]-'0') % 2 != 1) break;
		}
	}
	cout << num;
	return 0;
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> v;
bool isNum(long long num)
{
	long long n = sqrt(num);
	return n * n == num;
}
bool dfs(const string& str,int n,int num)
{
	if (n == str.size()&&num==2) return true;
	for (int i = n; i < str.size(); i++)
	{
		long long temp = stoll(str.substr(n, i - n + 1));
		if(temp!=0&&isNum(temp)&&dfs(str,i+1,num+1)) return true;
	}
	return false;
}
int main()
{
	long long a,b;
	cin >> a >> b;
	for (long long i = sqrt(a); i < sqrt(b); i++)
	{
		long long temp = i * i;
		if (isNum(temp))
		{
			string str = to_string(temp);
			if(dfs(str,0,0))
			cout << temp << endl;
		}
	}
	return 0;
}
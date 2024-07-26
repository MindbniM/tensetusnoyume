#include<iostream>
#include<vector>
#include<thread>
#include<memory>
#include<format>
#include<iostream>
#include<memory>
using namespace std;
int main()
{
	bool a=true;
	bool& b = a;
	b = false;
	cout << a << endl;
	return 0;
}
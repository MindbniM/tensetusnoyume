#include<iostream>
#include<functional>
using namespace std;
template<class T>
void fun(function<T> f)
{
	f();
}
int main()
{
	fun<void()>([] {cout << "000"; });
	void(*p)(int) = nullptr;
	return 0;
}
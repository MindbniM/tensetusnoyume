#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;
class Person {
public:
	virtual void f() 
	{
		cout << "person::f()" << endl;
	}
	void fun()
	{
		cout << "void person:: fun()" << endl;
	}
};
class Student : public Person {
public:
	virtual void f()
	{
		cout << "student:: f()" << endl;
	}
	void fun()
	{
		cout << "void student::fun()" << endl;
	}
};

int main()
{
	Person a;
	Student s;
	Person& p = s;
	p.f();
	p.fun();
	return 0;
}
#include"Data.h"
void Test1()
{
	Data d(2023, 12, 14);
	d.Print();
	Data d1(d);
	d1.Print();
	Data d2, d3;
	d3 = d2 = d;
	d2.Print();
	d3.Print();
}
void Test2()
{
	Data d(2023, 12, 14);
	d += 50;
	d.Print();
	d = d + 50;
	d.Print();
}
void Test3()
{
	Data d(2023, 12, 14);
	d -= 50;
	d.Print();
	d = d - 50;
	d.Print();
}
void Test4()
{
	Data d(2023, 12, 14);
	(d--).Print();
	d.Print();
	(--d).Print();
	d.Print();
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}

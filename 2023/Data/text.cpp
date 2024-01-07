#include"Data.h"
void Test1()
{
	Data d;
	d.Print();
}
//void Test2()
//{
//	Data d(2023, 12, 14);
//	d += 50;
//	d.Print();
//	d = d + 50;
//	d.Print();
//}
//void Test3()
//{
//	Data d(2023, 12, 14);
//	d -= 50;
//	d.Print();
//	d = d - 50;
//	d.Print();
//}
//void Test4()
//{
//	Data d(2023, 12, 14);
//	(d--).Print();
//	d.Print();
//	(--d).Print();
//	d.Print();
//}
//void Test5()
//{
//	Data d1(2023, 12, 14);
//	Data d2(2023, 12, 13);
//	
//}
//void Test6()
//{
//	std::list<Data> li;
//	li.push_back(Data(2022, 10, 1));
//	li.push_back(Data(2023, 10, 1));
//	li.push_back(Data(2024, 10, 1));
//	li.push_back(Data(2025, 10, 1));
//	li.pop_front();
//	std::list<Data>::iterator lis = li.begin();
//	while (lis != li.end())
//	{
//		std::cout << *lis << " ";
//		lis++;
//	}
//	std::cout << std::endl;
//}
int main()
{
	Test1();
	return 0;
}

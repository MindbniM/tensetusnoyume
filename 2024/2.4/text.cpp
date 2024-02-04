#include <iostream>
#include <string>
#include <vector>
//using namespace std;
#include"Data.h"

int main()
{
	MindbniM::Time t(2024, 2, 4, 12);
	Data& d = t;
	std::cout << d;
	return 0;
}
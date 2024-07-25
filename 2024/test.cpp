#include<iostream>
#include<vector>
#include<thread>
#include<memory>
#include<format>
#include<iostream>
#include<memory>
using namespace std;
template<class T,class index>
decltype(auto) at( T&& v, index n)
{
	return forward<T>(v)[n];
}
template<typename Container, typename Index>    //最终的C++11版本
auto authAndAccess(Container&& c, Index i) -> decltype(std::forward<Container>(c)[i])
{
	authenticateUser();
	return std::forward<Container>(c)[i];
}

int main()
{
	vector<int> v = { 1,2,4 };
	at(v, 2) = 1;
	for (auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
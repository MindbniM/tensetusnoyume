import <iostream>;
#include<thread>
#include<functional>
#include<chrono>
#include<future>
using namespace std;
int test()
{
	return 1;
}
int main()
{
	std::packaged_task<int()> task(test);
	thread t([&task]
		{
			task();
		});
	t.join();
	cout << task.get_future().get() << endl;
	return 0;
}
#include"bank.h"
using namespace bank;


void init(BankAlgorithm& b)
{
	b.clear();
	int n, m;
	std::ifstream in("1.txt");
	if (!in.is_open())
	{
		std::cout << "文件不存在" << std::endl;
		return;
	}
	in >> n >> m;
	std::vector<Process> pros;
	std::vector<resource> resources;
	for (int i = 0; i < n; i++)
	{
		std::string name;
		in >> name;
		pros.emplace_back(name);
	}
	for (int i = 0; i < m; i++)
	{
		std::string name;
		in >> name;
		resources.emplace_back(name);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			in >> pros[i]._resources[resources[j]._name]._max;
		}
		for (int j = 0; j < m; j++)
		{
			in >> pros[i]._resources[resources[j]._name]._allocation;
		}
		for (int j = 0; j < m; j++)
		{
			resource& re = pros[i]._resources[resources[j]._name];
			re._need = re._max - re._allocation;
		}
		b.insert(pros[i]);
	}
	for (int i = 0; i < m; i++)
	{
		uint32_t num;
		in >> num;
		b.resource(resources[i]._name, num);
	}
}
void interface()
{
	std::cout << "*******************************************" << std::endl;
	std::cout << "1. 查看系统当前资源使用情况" << std::endl;
	std::cout << "2. 分析系统安全性" << std::endl;
	std::cout << "3. 分配资源" << std::endl;
	std::cout << "4. 重新读入数据" << std::endl;
	std::cout << "0. 退出程序" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "请选择: ";
}

int main()
{
	BankAlgorithm b;
	init(b);
	while (1)
	{
		interface();
		int n;
		std::cin >> n;
		std::vector<std::string> vs;
		bool issafe;
		std::string pname, rname;
		int num;
		switch (n)
		{
		case 1:
			b.show();
			b.getresource();
			break;
		case 2:
			issafe=b.isSafe(vs);
			if (issafe)
			{
				b.show();
				std::cout << "系统安全, 分配顺序为 : " << std::endl;
				for (int i=0;i<vs.size();i++)
				{
					if (i == 0)
					{
						std::cout << vs[i];
					}
					else std::cout << "->" << vs[i];
				}
				std::cout << '\n';
			}
			else
			{
				std::cout << "系统不安全" << std::endl;
			}
			break;
		case 3:
			std::cout << "输入要分配的小组名和资源名和资源数" << std::endl;
			std::cin >> pname >> rname>>num;
			b.setresource(pname, rname, num);
			break;
		case 4:
			init(b);
			break;
		case 0:
			return 0;
		default:
			std::cout << "请正确输入" << std::endl;
			break;
		}
	}
	return 0;
}
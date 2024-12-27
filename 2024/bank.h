#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
#include <fstream>
namespace bank
{
    using uint32_t = unsigned int;

    struct resource
    {
        resource() = default;
        resource(const std::string& name, uint32_t max = 0, uint32_t allocation = 0)
            : _name(name), _max(max), _allocation(allocation)
        {
            _need = _max - _allocation;
        }

        std::string _name;
        uint32_t _max;
        uint32_t _need;
        uint32_t _allocation = 0;
        uint32_t _available = 0;
    };

    struct Process
    {
        Process() = default;
        Process(const std::string& name) : _name(name) {}

        template <class... Args>
        void insert(Args&&... args)
        {
            resource temp(std::forward<Args>(args)...);
            _resources[temp._name] = temp;
        }

        std::string _name;
        std::unordered_map<std::string, resource> _resources;
    };

    class BankAlgorithm
    {
    public:
        void insert(const Process& pro)
        {
            _pros.push_back(pro);
        }

        void resource(const std::string& name, uint32_t num)
        {
            _maxresource[name] = num;
        }
        void getresource()
        {
            for (auto& [name, num] : _maxresource)
            {
                std::cout << name << " : " << num << std::endl;
            }
        }
        bool isSafe(std::vector<std::string>& safe)
        {
            std::unordered_map<std::string, uint32_t> work = _maxresource;
            for (const auto& pro : _pros)
            {
                for (const auto& [name, res] : pro._resources)
                {
                    work[name] -= res._allocation;
                }
            }
            //for (auto& [name, num] : work)
            //{
            //    std::cout << name << " " << num << std::endl;
            //}

            std::vector<bool> vb(_pros.size(), false);

            int num = 0;
            for (int  count = 0; count < _pros.size(); count++)
            {
                for (int i = 0; i < _pros.size(); i++)
                {
                    if (!vb[i])
                    {
                        Process& pro = _pros[i];
                        bool canAllocate = true;
                        for (const auto& [name, res] : pro._resources)
                        {
                            if (res._need > work[name])
                            {
                                canAllocate = false;
                                break;
                            }
                        }
                        if (canAllocate)
                        {
                            //std::cout << pro._name << " "<<std::endl;
                            for (auto& [name, res] : pro._resources)
                            {
                                work[name] += res._allocation;
                                res._available = work[name];
                            }
                            num++;
                            //for (auto& [name, num] : work)
                            //{
                            //    std::cout << name << " " << num << std::endl;
                            //}
                            vb[i] = true;
                            safe.push_back(pro._name);
                        }
                    }
                }
                //std::cout << '\n';
            }
            if (num!=vb.size())
            {
                return false;
            }

            return true;
        }
        void show()
		{
            printf(" %15s","max");
            printf("%18s","allocation");
            printf("%18s\n","need");
			printf("%5s ", "小组");
            std::vector<std::string> vs;
            for (auto& [name, _] : _maxresource)
            {
                vs.push_back(name);
            }
			for (auto& s : vs)
			{
				printf("%5s", s.c_str());
			}
            printf(" | ");
			for (auto& s : vs)
			{
				printf("%5s", s.c_str());
			}
            printf(" | ");
			for (auto& s : vs)
			{
				printf("%5s", s.c_str());
			}
			printf("\n");
			for (auto& p : _pros)
			{
				printf("%5s", p._name.c_str());
				for (auto& s : vs)
				{
					printf("%5u", p._resources[s]._max);
				}
                printf(" | ");
				for (auto& s : vs)
				{
					printf("%5u", p._resources[s]._allocation);
				}
                printf(" | ");
				for (auto& s : vs)
				{
					printf("%5u", p._resources[s]._need);
				}
                printf(" | ");
				for (auto& s : vs)
				{
					printf("%5u", p._resources[s]._available);
				}
				printf("\n");
			}
		}
        void clear()
        {
            _pros.clear();
            _maxresource.clear();
        }
        void setresource(const std::string& pname, const std::string& rname, int num)
        {
            if (!_maxresource.count(rname))
            {
                std::cout << "资源不存在" << std::endl;
                return;
            }
            if (_maxresource[rname]<num)
            {
                std::cout << rname<<"资源不够" << std::endl;
                return;
            }
            for (auto& p : _pros)
            {
                if (p._name == pname)
                {
                    _maxresource[rname] -= num;
                    p._resources[rname]._allocation +=num;
                    break;
                }
            }
        }
    private:
        std::vector<Process> _pros;
        std::unordered_map<std::string, uint32_t> _maxresource;
    };
}

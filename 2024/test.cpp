#include<iostream>
#include<vector>
#include<utility>
#include"hash_bucket.h"
#include"unordered_set.h"
#include"unordered_map.h"
int main()
{
	unordered_map<int,int> hash;
	hash[4] = 1;
	hash[14] = 7;
	hash[5] = 6;
	hash[3] = 3;
	hash[8] = 0;
	unordered_map<int,int>::iterator it = hash.begin();
	/*while (it != hash.end())
	{
		std::cout << (*it).first << " "<<(*it).second<<std::endl;
		it = hash.erase((*it).first);
	}*/
	for (auto& p : hash)
	{
		std::cout << p.first << " " << p.second << std::endl;
	}
	return 0;
}
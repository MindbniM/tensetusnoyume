#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int hash[128] = { 0 };
        int hashs[128] = { 0 };
        vector<string> vs;
        for (auto c : t)
            hash[c]++;
        for (int dest = 0, cur = 0, cou = 0; cur < s.size(); cur++)
        {
            hashs[s[cur]]++;
            if (hashs[s[cur]] <= hash[s[cur]])
                cou++;
            while (cou == t.size())
            {
                vs.push_back(s.substr(dest, cur - dest+1));
                if (hashs[s[dest]] <= hash[s[dest]])
                    cou--;
                hashs[s[dest]]--;
                dest++;
            }
        }
        int m = INT_MAX;
        int ret = -1;
        for (int i = 0; i < vs.size(); i++)
        {
            if (m > vs[i].size())
            {
                ret = i;
                m = vs[i].size();
            }
        }
        return vs[ret];
    }
};
int main()
{
    string s=Solution().minWindow("ADOBECODEBANC","ABC");
	return 0;
}
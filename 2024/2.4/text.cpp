#include <iostream>
#include <string>
#include <vector>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> vs{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    void fun(vector<string>& s, string& str, int n, string ss)
    {
        if (n>=str.size())
            return;
        string s1 = vs[str[n]-'0'];
        for (int i = 0; i < s1.size(); i++)
        {
            char c = s1[i];
            string s2 = ss;
            ss += c;
            if (ss.size() == str.size())
            {
                s.push_back(ss);
                ss = s2;
            }
            fun(s, str, n+1, ss);
            ss = s2;
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        string ss;
        fun(v, digits, 0, ss);
        return v;
    }
};
int main()
{
    string s("234");
    vector<string> vv=Solution().letterCombinations(s);
    return 0;
}
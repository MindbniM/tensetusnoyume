#include <iostream>
#include<vector>
#include<fstream>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param board string字符串vector
     * @param word string字符串
     * @return bool布尔型
     */
    int arr1[4] = { -1,1,0,0 };
    int arr2[4] = { 0,0,-1,1 };
    bool gets(vector<string>& b, string& w, int s, int i, int j, vector<vector<bool>>& vb)
    {
        if (s >= w.size()) return true;
        for (int si = 0; si < 4; si++)
        {
            int ni = i + arr1[si], nj = j + arr2[si];
            if (vb[ni][nj] && w[s] == b[ni][nj])
            {
                vb[ni][nj] = false;
                cout << b[ni][nj];
                if (gets(b, w, s + 1, ni, nj, vb)) return true;
                vb[ni][nj] = true;
            }
        }
        return false;
    }
    bool exist(vector<string>& board, string word) {
        vector<vector<bool>> vb(board.size(), vector<bool>(board[0].size(), true));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j])
                {
                    vb[i][j] = false;
                    if (gets(board, word, 1, i, j, vb)) return true;
                    vb = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), true));
                }
            }
        }
        return false;
    }
};
int main()
{
    vector<string> vs= { "XYZE", "SFZS", "XDEE"};
    string str = "XYZZED";
    cout<<Solution().exist(vs,str);
    return 0;
}
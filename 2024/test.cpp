#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int o = 0; o < n; o++)
    {
        int m;
        cin >> m;
        vector<string> vs(m);
        for (int i = 0; i < m; i++)
        {
            cin >> vs[i];
        }
        unordered_set<char> hash;
        int i = 0;
        m--;
        while (i != m && i != m - 1)
        {
            hash.clear();
            int coun = 0;
            for (auto c : vs[i]) hash.insert(c);
            for (auto c : vs[m])
            {
                if (hash.count(c))
                {
                    coun = 1;
                    break;
                }
            }
            if (coun == 0)
            {
                cout << "No" << endl;
                break;
            }
            i++;
            m--;
        }
        if (i == m || i == m - 1)
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
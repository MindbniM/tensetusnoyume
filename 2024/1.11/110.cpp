#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::cin;
int main()
{
    std::vector<char> s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    s.push_back('d');
    s.push_back('e');
    std::vector<char>::iterator it=s.begin();
    std::vector<char>::iterator end=s.end();
    while(it!=end)
    {
        char a=*it;
        *it=*end;
        *end=a;
        it++;
        end--;
    }
    for(auto e:s)
    {
        cout<<e<<" "<<endl;
    }
}
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
template<class T>
void swap(T&a,T&b)
{
    T c=a;
    a=b;
    b=c;
}
int main()
{
   int a=1,b=2;
   char c='a',d='b';
   swap<int>(a,b);
   swap<char>(c,d);
   cout<<a <<" "<<b<<endl;
   cout<<c<<" "<<d<<endl;
}
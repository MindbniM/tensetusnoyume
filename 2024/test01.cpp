#if 0
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cstdlib>
using namespace std;
struct d_data
{
	set<int> _hash;
	int _up;
	int _weight;
	int _moprice=0;
	int _i=0;
	d_data(int up=0,int weight=0):_up(up),_weight(weight)
	{}
    bool operator()(const d_data & d1,const d_data&d2)
	{
		return d1._up<d2._up;
	}
};
int max_weight;
int maxv(d_data& d,vector<double>& v)
{
	int ni=-1, num = 0;
	for(int i=0;i<v.size();i++)
	{
		if(!d._hash.count(i)&&v[i]>num)
		{
			ni=i;
			num=v[i];
		}
	}
	return ni;
}
int main()
{
	int n;
	cout<<"输入背包最大容量"<<endl;
	cin>>max_weight;
	cout<<"输入商品数量"<<endl;
	cin>>n;
	vector<int> price(n);
	vector<int> weight(n);
	vector<double> v(n);
	priority_queue<d_data,vector<d_data>,d_data> q;
	cout<<"输入商品价格"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	double max_v=0;
	cout<<"输入商品重量"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
		v[i]=price[i]*1.0/weight[i];
		max_v=max(max_v,v[i]);
	}
	
	q.push(d_data(max_v*max_weight,0));
	while(true)
	{
		d_data a=q.top();
		q.pop();
		if(a._i==n)
		{
			cout<<"最大价值为:"<<a._up << endl;
			return 0;
		}
		d_data temp=a;
		temp._hash.insert(temp._i);
		int max_v = maxv(temp, v);
		temp._up = temp._moprice;
		if (max_v != -1)
			temp._up += (max_weight - temp._weight) * v[max_v];
		temp._i++;
		a._moprice+=price[a._i];
		a._hash.insert(a._i);
		a._weight+=weight[a._i];
		a._up = a._moprice;
		max_v = maxv(a, v);
		if (max_v != -1)
			a._up += (max_weight - a._weight) * v[maxv(a, v)];
		a._i++;
		q.push(temp);
		if(a._weight<=max_weight)
		{
			q.push(a);
		}
	}
	return 0;
}
#endif

#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define for(i,a,b) for(int i=a;i<b;i++)
#define For(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
anonymous()
{
	vinh
	int n;cin>>n;
	int k;cin>>k;
	int a[n];
	for(i,0,n)
	{
		cin>>a[i];
	}
	multiset<int> d;
	for(i,0,k) d.insert(a[i]);
	if(k%2==0)
	{
		auto it=d.begin();
		for(i,1,d.size()/2)
		{
			++it;
		}
		cout<<*(it)<<" ";
		for(i,1,n-k+1)
		{
			d.insert(a[i+k-1]);
			if(a[i+k-1]>=*(it))
			{
				it++;
			}
			auto it1=d.lower_bound(a[i-1]);
//			if() it--;
			if (*(it1)>*(it)||it1==it) it--; 
			d.erase(it1);
			cout<<*(it)<<" ";
		}
	}
	else 
	{
		auto it=d.begin();
		for(i,1,d.size()/2+1)
		{
			it++;
		}
		cout<<*(it)<<" ";
		for(i,1,n-k+1)
		{
			d.insert(a[i+k-1]);
			if(a[i+k-1]<*(it))
			{
				it--;
			}
			auto it1=d.lower_bound(a[i-1]);
			if(*(it1)<=*(it)) it++;
			d.erase(it1);
			cout<<*(it)<<" ";
			
		}
	}
}
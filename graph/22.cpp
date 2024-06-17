#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> a[10001];
int color[10001];
int DFS(int v)
{
	color[v]=1;
	foreach(x,a[v])
	{
		if(!color[x])
		{
			if(DFS(x)) return 1;
		}
		else if(color[x]==1)
		{
			return 1;
		}
	}
	color[v]=2;
	return 0;
}
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	my_for(i,0,m)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
	}
	my_for(i,1,n+1)
	{
		if(!color[i])
		{
			int x=DFS(i);
			if(x==1) 
			{
				cout<<1;
				return 0;
			}
		}
	}
	cout<<0;
}

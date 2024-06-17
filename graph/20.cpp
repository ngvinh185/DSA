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
int visited[100];
int n,m;
vector<pair<int,int>> d;
void DFS(int i,int v1,int v2)
{
	visited[i]=1;
	foreach(x,a[i])
	{
		if(i==v1&&x==v2||i==v2&&x==v1) continue;
		if(!visited[x])
		{
			DFS(x,v1,v2);
		}
	}
}
int tplt(int v1,int v2)
{
	int cnt=0;
	my_for(i,1,n+1)
	{
		if(visited[i]==0)
		{
			DFS(i,v1,v2);
			cnt+=1;
		}
	}
	return cnt;
}
anonymous()
{
	vinh
	cin>>n>>m;
	my_for(i,1,m+1)
	{
		int x,y;cin>>x>>y;
		d.push_back({x,y});
		a[x].push_back(y);
		a[y].push_back(x);
	}
	my_for(i,1,n+1)
	{
		sort(a[i].begin(),a[i].end());
	}
	int res=tplt(0,0);
	int dem=0;
	my_for(i,0,m)
	{
		memset(visited,0,sizeof(visited));		
		int v1=d[i].first,v2=d[i].second;
		if(tplt(v1,v2)>res)
		{
			dem+=1;
		}
	}
	cout<<dem;
}

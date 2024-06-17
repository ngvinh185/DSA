#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
int a[1001][1001];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int BFS(int n,int s,int t,int u,int v)
{
	queue<pair<pair<int,int>,int>> q;
	q.push({{s,t},0});
	a[s][t]=0;
	while(!q.empty())
	{
		auto it=q.front();
		int x=it.first.first,y=it.first.second;
		int d=it.second;
		q.pop();
		if(x==u&&y==v) return d;
		my_for(k,0,8)
		{
			int i1=x+dx[k],j1=y+dy[k];
			if(i1>=0&&j1>=0&&i1<n&&j1<n&&a[i1][j1]==1) 
			{

				q.push({{i1,j1},d+1});
				a[i1][j1]=0;
			}
		}
	}
	return -1;
}
anonymous()
{
	vinh
	int n;cin>>n;
	int s,t,u,v;cin>>s>>t>>u>>v;
	my_for(i,0,n)
	{
		my_for(j,0,n) cin>>a[i][j];
	}
	cout<<BFS(n,s,t,u,v);
}

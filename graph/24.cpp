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
int visited[10001];
int parent[10001];
int cnt=0;;
int DFS(int v)
{
	cnt+=1;
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			parent[x]=v;
			if(DFS(x)) return 1;
		}
		else if(parent[v]!=x) return 1;//back edge:v->x
	}
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
		a[y].push_back(x);
	}
	DFS(1);
	if(m==n-1&&cnt==n) cout<<1;
	else cout<<0;
	
}

#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> a[1001];
int visited[100];
int p[100];
int s,e;
void DFS(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			DFS(x);
			p[x]=v;
		}
	}
}
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	cin>>s>>e;
	my_for(i,1,m+1)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	my_for(i,1,n+1)
	{
		sort(a[i].begin(),a[i].end());
	}
	DFS(s);
	if(visited[e])
	{
		vector<int> path;
		int con=e;
		while(con!=s)
		{
			path.push_back(con);
			con=p[con];	
		}
		path.push_back(con);
		reverse(path.begin(),path.end());
		foreach(x,path) cout<<x<<" ";
	}
	else cout<<-1;
}

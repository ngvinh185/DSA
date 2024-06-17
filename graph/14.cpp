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
int check=0;
int res[100];
int s,e;
int pos;
void DFS(int v,int index)
{
	if(check) return ;
	res[index]=v;
	if(v==e) 
	{
		check=1;
		pos=index;
		return;
	}
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			DFS(x,index+1);
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
	DFS(s,0);
	if(check)
	{
		my_for(i,0,pos+1) cout<<res[i]<<" ";
	}
	else cout<<-1;
}

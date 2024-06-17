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
int cnt=0;
void DFS(int v)
{
	visited[v]=cnt;
	foreach(x,a[v])
	{
		if(visited[x]==0)
		{
			DFS(x);
		}
	}
}
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
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
	my_for(i,1,n+1)
	{
		if(visited[i]==0)
		{
			cnt+=1;
			DFS(i);
		}
	}
	int q;cin>>q;
	while(q--)
	{
		int s,t;cin>>s>>t;
		if(visited[s]==visited[t])
		{
			cout<<1<<endl;
		}
		else cout<<-1<<endl;
	}
}

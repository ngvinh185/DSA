#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
int visited[100];
vector<int> a[10001];
int parent[1001];
void BFS(int u)
{
	queue<int> q;
	q.push(u);
	visited[u]=1;
	while(q.empty()==0)
	{
		int v=q.front();
		q.pop();
		foreach(x,a[v])
		{
			if(!visited[x])
			{
				parent[x]=v;
				visited[x]=1;
				q.push(x);
				
			}
		}
	}
}
anonymous()
{
	vinh
	int n,m,s,t;cin>>n>>m>>s>>t;
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
	BFS(s);
	if(visited[t])
	{
		vector<int> d;
		int res=t;
		while(res!=s)
		{
			d.push_back(res);
			res=parent[res];
		}
		d.push_back(res);
		reverse(d.begin(),d.end());
		foreach(x,d) cout<<x<<" ";
	}
	else cout<<-1<<endl;
}
